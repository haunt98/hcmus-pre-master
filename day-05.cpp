#include <iostream>
#include <vector>

using namespace std;

class Observer;

class Button {};

class Observer {
  public:
    virtual void update() = 0;
};

class Frame : public Observer {
  public:
    void update() {}
};

class Window : public Observer {
  public:
    void update() {}
};

// Counting sort
// Cho day so nguyen n: 0 -> n - 1
// Tim phan tu trung lap va so lan xuat hien
// [1, 2, 2, 3, 4, 4]
// 2 xuat hien 2 lan
// 4 xuat hien 4 lan
void dupCount(int a[], int n) {
    int* temp = new int[n];

    for (int i = 0; i < n; i++) {
        temp[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        temp[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (temp[i] > 1) {
            printf("Duplicate %d times %d\n", i, temp[i]);
        }
    }

    delete[] temp;
}

void test() {
    int a[5];
    a[0] = 1;
    a[1] = 2;
    a[2] = 2;
    a[3] = 1;
    a[4] = 4;
    dupCount(a, 5);
}

struct ThiSinh {
    string HoTen;
    string SBD;
    float DiemCoBan;
    float DiemCoSo;
    bool NgoaiNgu;
    ThiSinh* pNext;
};

ThiSinh* ThemThiSinh(ThiSinh*& pHead, string HoTen, string SBD, float DiemCoBan,
                     float DiemCoSo, bool NgoaiNgu) {
    ThiSinh* a = new ThiSinh;
    a->HoTen = HoTen;
    a->SBD = SBD;
    a->DiemCoBan = DiemCoBan;
    a->DiemCoSo = DiemCoSo;
    a->NgoaiNgu = NgoaiNgu;

    if (pHead == NULL) {
        pHead = a;
        return a;
    }

    ThiSinh* p = pHead;
    while (p != NULL) {
        if (p->pNext == NULL) {
            p->pNext = a;
            break;
        }

        p = p->pNext;
    }

    return a;
}

// TODO
// float XacDinhDiemChuan(ThiSinh *pHead, int ChiTieu)

void test2() {}

int main() { test(); }
