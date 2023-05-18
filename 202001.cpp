#include <iostream>

using namespace std;

void cau_2();
void cau_3();

int main() {
    cau_2();
    cau_3();

    return 0;
}

struct Node {
    int value;
    Node* next;
};

Node* append_tail(Node* p, int value) {
    Node* q = new Node();
    q->value = value;

    Node* tail = p;
    if (tail == NULL) {
        return q;
    }

    while (tail->next != NULL) {
        tail = tail->next;
    }

    tail->next = q;
    return q;
}

Node* remove_k_index(Node* p, int k) {
    if (k < 0) {
        return NULL;
    }

    Node* prev = NULL;
    Node* cur = p;

    // 0->1->2->3->4->5
    for (int i = 0; i < k; i++) {
        if (cur == NULL) {
            // There is no value at k index
            return NULL;
        }

        prev = cur;
        cur = cur->next;
    }

    // Double check cur again
    if (cur == NULL) {
        return NULL;
    }

    if (prev == NULL) {
        // Linked list only has 1 node
        return cur;
    }

    prev->next = cur->next;
    return cur;
}

void print_node(Node* p) {
    while (p != NULL) {
        printf("%d->", p->value);
        p = p->next;
    }
    printf("NULL\n");
}

void cau_2() {
    printf("cau_2\n");

    Node* head = NULL;
    head = append_tail(head, 1);
    append_tail(head, 2);
    append_tail(head, 3);
    append_tail(head, 4);
    append_tail(head, 5);
    print_node(head);

    Node* p = remove_k_index(head, 3);
    if (p != NULL) {
        printf("Remove %d\n", p->value);
    }
    print_node(head);

    p = remove_k_index(head, 3);
    if (p != NULL) {
        printf("Remove %d\n", p->value);
    }
    print_node(head);
}

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
    virtual void draw(Shape* s) = 0;
};

class Rectangle : public Shape {
  private:
    int x;
    int y;
    int width;
    int height;

  public:
    Rectangle(int x, int y, int width, int height, DrawingShape* drawer)
        : Shape(drawer) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    void draw() { this->drawer->draw(this); }
};

class Circle : public Shape {
  private:
    int x;
    int y;
    int radius;

  public:
    Circle(int x, int y, int radius, DrawingShape* drawer) : Shape(drawer) {
        this->x = x;
        this->y = y;
        this->radius = radius;
    }

    void draw() { this->drawer->draw(this); }
};

class DrawingRectangle : public DrawingShape {
  public:
    void draw(Shape* s) { printf("Draw rectangle\n"); }
};

class DrawingCircle : public DrawingShape {
  public:
    void draw(Shape* s) { printf("Draw circle\n"); }
};

void cau_3() {
    printf("cau_3\n");
    DrawingShape* dr = new DrawingRectangle();
    DrawingShape* dc = new DrawingCircle();
    Shape** arr = new Shape*[3];
    arr[0] = new Rectangle(1, 2, 3, 4, dr);
    arr[1] = new Circle(1, 2, 3, dc);
    arr[2] = new Rectangle(1, 2, 3, 4, dr);

    for (int i = 0; i < 3; i++) {
        arr[i]->draw();
    }
}
