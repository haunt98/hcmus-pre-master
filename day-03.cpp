#include <iostream>

using namespace std;

class MyClass {
  public:
    int A;
    void doIt() { printf("Do it\n"); }
    // Constructor
    MyClass() { printf("Constructor\n"); }
};

class ChildClass : public MyClass {};

void test();

class ThietBiDien {
  public:
    virtual void TurnOn() { printf("Turn on\n"); }
};

class TBDen : public ThietBiDien {
  protected:
    int doSang;
};

class TBDenNgu : public TBDen {
  private:
    int mauSang;

  public:
    void changeMauSang(int mauSang) { this->mauSang = mauSang; }
};

class TBDenChieuSang : public TBDen {};

class TBDieuHoa : public ThietBiDien {
  private:
    int nhietDo;
    int cheDoHoatDong;
    int mucDoQuat;

  public:
    void changeNhietDo(int nhietDo) { this->nhietDo = nhietDo; }
    void TurnOn() { printf("Dieu hoa turn on\n"); }
};

class TBTivi : public ThietBiDien {};

void testThietBiDien();

int main() {
    test();
    testThietBiDien();
}

void test() {
    MyClass c;
    c.A = 5;
    printf("%d\n", c.A);
    c.doIt();

    ChildClass cc;
    cc.A = 6;
    printf("%d\n", cc.A);
    cc.doIt();
}

void testThietBiDien() {
    ThietBiDien* arr[10];

    arr[0] = new TBDen();

    arr[1] = new TBDieuHoa();

    for (int i = 0; i < 2; i++) {
        // If pointer (*abc).TurnOn is equal to abc->TurnOn
        arr[i]->TurnOn();
    }

    // Slicing
    // https://stackoverflow.com/a/21068741
    // TBDieuHoa is lost, ThietBiDien only
    // Because not pointer
    ThietBiDien t = TBDieuHoa();
    t.TurnOn();
}
