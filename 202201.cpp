#include <iostream>
#include <string>
#include <vector>

using namespace std;

void cau_1();

int main() {
    printf("202201\n");
    cau_1();
}

void print_arr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

struct Sach {
    string ten;
    int nxb;
    float money;
};

Sach* find_sach_binary_search(Sach** arr, int left, int right, int nxb) {
    if (left > right) {
        return NULL;
    }

    int mid = left + (right - left) / 2;
    if (arr[mid]->nxb == nxb) {
        return arr[mid];
    } else if (arr[mid]->nxb > nxb) {
        return find_sach_binary_search(arr, left, mid - 1, nxb);
    } else {
        return find_sach_binary_search(arr, mid + 1, right, nxb);
    }
}

Sach* find_sach(Sach** arr, int n, int nxb) {
    return find_sach_binary_search(arr, 0, n - 1, nxb);
}

void cau_1() {
    printf("cau_1\n");
    Sach* arr[4];
    arr[0] = new Sach();
    arr[0]->ten = "Sach 0";
    arr[0]->nxb = 1998;
    arr[1] = new Sach();
    arr[1]->ten = "Sach 1";
    arr[1]->nxb = 1999;
    arr[2] = new Sach();
    arr[2]->ten = "Sach 2";
    arr[2]->nxb = 2000;
    arr[3] = new Sach();
    arr[3]->ten = "Sach 3";
    arr[3]->nxb = 2001;

    int nxb = 1999;
    Sach* found = find_sach(arr, 4, nxb);
    if (found != NULL) {
        cout << "Found nxb " << nxb << " " << found->ten << endl;
    } else {
        cout << "Not found nxb " << nxb << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete arr[i];
    }
}
