#include <iostream>

using namespace std;

class AbstractStorage {
  public:
    virtual int getSize() = 0;
};

class File : public AbstractStorage {
  public:
    int getSize() { return 1; }
};

class Folder : public AbstractStorage {
  private:
    // AbstractStorage is virtual class
    AbstractStorage** childList;
    int nChild;

  public:
    int getSize() {
        int size = 0;

        for (int i = 0; i < nChild; i++) {
            size += childList[i]->getSize();
        }

        return size;
    }
};

class DrawingShape;

class Shape {
  protected:
    DrawingShape* drawer;

  public:
    Shape(DrawingShape* drawer) { this->drawer = drawer; }
    virtual void draw() = 0;
};

class DrawingShape {
  public:
    virtual void draw(Shape* shape) = 0;
};

class Rectangle : public Shape {
  private:
    int x, y, w, h;

  public:
    // C++ error must explicitly initialize the base class 'parent' which does
    // not have a default constructor
    Rectangle(int x, int y, int w, int h, DrawingShape* drawer)
        : Shape(drawer) {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }
    void draw() { drawer->draw(this); }
};

class DrawingRectangle : public DrawingShape {
  public:
    void draw(Shape* s) { printf("Draw rectangle\n"); }
};

class Circle : public Shape {
  private:
    int x, y, radius;

  public:
    Circle(int x, int y, int radius, DrawingShape* drawer) : Shape(drawer) {
        this->x = x;
        this->y = y;
        this->radius = radius;
    }
    void draw() { drawer->draw(this); }
};

class DrawingCircle : public DrawingShape {
  public:
    void draw(Shape* s) { printf("Draw circle\n"); }
};

void test() {
    DrawingShape* drawingRectangle = new DrawingRectangle();
    DrawingShape* drawingCircle = new DrawingCircle();

    Shape* arr[3];
    arr[0] = new Rectangle(0, 0, 1, 1, drawingRectangle);
    arr[1] = new Rectangle(0, 0, 1, 1, drawingRectangle);
    arr[2] = new Circle(0, 1, 2, drawingCircle);

    for (int i = 0; i < 3; i++) {
        arr[i]->draw();
    }

    for (int i = 0; i < 3; i++) {
        delete arr[i];
    }

    delete drawingCircle;
    delete drawingRectangle;
}
// Only 1 CTO
// How to make singleton ?
// Hide constructor in private
// static GetInstance()
// return static var
class CTO {
  private:
    CTO() {}

  public:
    string name;
    // Static funciton with static var inside
    // Lazy singletance
    static CTO* GetInstance() {
        static CTO* only_cto = new CTO();

        return only_cto;
    }
};

void test2() {
    CTO* a = CTO::GetInstance();
    CTO* b = CTO::GetInstance();
    a->name = "fuck";
    b->name = "you";
    cout << b->name << endl;
}

int main() {
    test();
    test2();
}
