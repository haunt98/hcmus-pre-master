#include <iostream>
using namespace std;

int isArrTangGiam(int* arr, int n);
void testArrTangGiam();

int main() { testArrTangGiam(); }

// 1 3 5 4 2: ok
// 1 1 3 5 4 2: not ok
// idea:
// tang dan tu dau -> stop on top
// giam dan tu cuoi -> stop on top
int isArrTangGiam(int* arr, int n) {
    int indexTop = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            return 0;
        } else if (arr[i] > arr[i + 1]) {
            indexTop = i;
            break;
        }
    }

    int indexAnotherTop = n - 1;
    for (int i = n - 1; i > 1; i--) {
        if (arr[i] == arr[i - 1]) {
            return 0;
        } else if (arr[i] > arr[i - 1]) {
            indexAnotherTop = i;
            break;
        }
    }

    if (indexTop != indexAnotherTop) {
        return 0;
    }

    if (indexTop == 0) {
        return 0;
    }

    if (indexAnotherTop == n - 1) {
        return 0;
    }

    return 1;
}

void testArrTangGiam() {
    int arr[5];
    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 5;
    arr[3] = 4;
    arr[4] = 2;

    printf("arr tang giam: %d\n", isArrTangGiam(arr, 5));

    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 3;
    arr[3] = 5;
    arr[4] = 4;
    printf("arr tang giam: %d\n", isArrTangGiam(arr, 5));

    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 5;
    arr[3] = 4;
    arr[4] = 4;
    printf("arr tang giam: %d\n", isArrTangGiam(arr, 5));

    arr[0] = 1;
    arr[1] = 2;
    printf("arr tang giam: %d\n", isArrTangGiam(arr, 2));

    arr[0] = 2;
    arr[1] = 1;
    printf("arr tang giam: %d\n", isArrTangGiam(arr, 2));

    arr[0] = 1;
    printf("arr tang giam: %d\n", isArrTangGiam(arr, 0));
}
