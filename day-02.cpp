#include <iostream>
using namespace std;

int isArrTangGiam(int* arr, int n);
bool isArrTangGiamTeacher(int* arr, int n);
int findTopTangGiam(int* arr, int n);
void testArrTangGiam();
void testFindTopTangGiam();

float soDuThangN(float a, float b, float c, int n);
void testSoDuThangN();

int main() {
    testArrTangGiam();
    testFindTopTangGiam();
    testSoDuThangN();
}

// 1 3 5 4 2: ok
// 1 1 3 5 4 2: not ok
// Idea:
// Tang dan tu dau -> stop on top
// Giam dan tu cuoi -> stop on top
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

    // Mang khong tang
    if (indexTop == 0) {
        return 0;
    }

    // Mang khong giam
    if (indexAnotherTop == n - 1) {
        return 0;
    }

    return 1;
}

bool isArrTangGiamTeacher(int* arr, int n) {
    // 1 3 2
    // Below len 3 can not make arr tang giam
    if (n < 3) {
        return false;
    }

    // Mang chi giam -> loai
    if (arr[0] >= arr[1]) {
        return false;
    }

    // Mang chi tang -> loai
    if (arr[n - 2] <= arr[n - 1]) {
        return false;
    }

    int i = 0;
    while (i < n - 1 && arr[i] < arr[i + 1]) {
        i++;
    }

    while (i < n - 1 && arr[i] > arr[i + 1]) {
        i++;
    }

    if (i == n - 1) {
        return true;
    }

    return false;
}

// 1 3 5 4 2 -> top is 5
// Return index top
// Because arr is tang giam, index top always exist
// Demo
// 1 3 5 4 2: left = 0, right = 4
// -> mid = 2
int findTopTangGiam(int* arr, int n) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = (right - left) / 2 + left;
        // printf("left %d right %d mid %d\n", left, right, mid);

        // Prevent undefine behavior below arr[mid - 1]
        if (mid == 0) {
            left++;
            continue;
        }

        // Prevent undefine behavior below arr[mid + 1]
        if (mid == n - 1) {
            right--;
            continue;
        }

        // 1 4 2
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;
        }

        // 1 2 3
        if (arr[mid] < arr[mid + 1]) {
            // To keep it out of the loop
            left = mid + 1;
        }

        // 3 2 1
        if (arr[mid] < arr[mid - 1]) {
            // To keep it out of the loop
            right = mid - 1;
        }
    }

    return -1;
}

void testArrTangGiam() {
    int arr[5];
    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 5;
    arr[3] = 4;
    arr[4] = 2;

    printf("arr tang giam: %d\n", isArrTangGiam(arr, 5));
    printf("arr tang giam: %d\n", isArrTangGiamTeacher(arr, 5));

    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 3;
    arr[3] = 5;
    arr[4] = 4;
    printf("arr tang giam: %d\n", isArrTangGiam(arr, 5));
    printf("arr tang giam: %d\n", isArrTangGiamTeacher(arr, 5));

    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 5;
    arr[3] = 4;
    arr[4] = 4;
    printf("arr tang giam: %d\n", isArrTangGiam(arr, 5));
    printf("arr tang giam: %d\n", isArrTangGiamTeacher(arr, 5));

    arr[0] = 1;
    arr[1] = 2;
    printf("arr tang giam: %d\n", isArrTangGiam(arr, 2));
    printf("arr tang giam: %d\n", isArrTangGiamTeacher(arr, 2));

    arr[0] = 2;
    arr[1] = 1;
    printf("arr tang giam: %d\n", isArrTangGiam(arr, 2));
    printf("arr tang giam: %d\n", isArrTangGiamTeacher(arr, 2));

    arr[0] = 1;
    printf("arr tang giam: %d\n", isArrTangGiam(arr, 0));
    printf("arr tang giam: %d\n", isArrTangGiamTeacher(arr, 0));
}

// TODO: Tim day tang giam dai nhat trong day tang giam (chi tang, chi giam,
// tang ngat roi giam ngat)

void testFindTopTangGiam() {
    {
        int arr[5];
        arr[0] = 1;
        arr[1] = 3;
        arr[2] = 5;
        arr[3] = 4;
        arr[4] = 2;

        printf("top index of arr tang giam: %d\n", findTopTangGiam(arr, 5));
    }

    {
        int arr[6];
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        arr[3] = 4;
        arr[4] = 5;
        arr[5] = 4;

        printf("top index of arr tang giam: %d\n", findTopTangGiam(arr, 6));
    }

    {
        int arr[6];
        arr[0] = 1;
        arr[1] = 5;
        arr[2] = 4;
        arr[3] = 3;
        arr[4] = 2;
        arr[5] = 1;

        printf("top index of arr tang giam: %d\n", findTopTangGiam(arr, 6));
    }

    {
        int arr[7];
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 4;
        arr[3] = 3;
        arr[4] = 2;
        arr[5] = 1;
        arr[6] = 0;

        printf("top index of arr tang giam: %d\n", findTopTangGiam(arr, 7));
    }
}

// x_0 = a
// x_n = (1 + b) * x_(n - 1) (n mod 3 != 0)
// x_n = (1 + b) * x_(n - 1) + c (n mod 3 == 0)
float soDuThangN(float a, float b, float c, int n) {
    if (n == 0) {
        return a;
    }

    if (n % 3 != 0) {
        return (1 + b) * soDuThangN(a, b, c, n - 1);
    } else {
        return (1 + b) * soDuThangN(a, b, c, n - 1) + c;
    }
}

// Khong de quy
// Khong su dung mang
// Luu bien tam chay vong lap
float soDuThangNV2(float a, float b, float c, int n) {
    float soDu = a;
    for (int i = 0; i < n; i++) {
        if (n % 3 != 0) {
            soDu = (1 + b) * soDu;
        } else {
            soDu = (1 + b) * soDu + c;
        }
    }

    return soDu;
}

// Cho truoc b, c
// Tim a toi thieu de sau k thang co so du toi thieu la M

void testSoDuThangN() {
    {
        for (int i = 0; i <= 4; i++) {
            printf("so du thang %d %.6f\n", i,
                   soDuThangN(100000000, 0.01, 50000, i));
            printf("so du thang v2 %d %.6f\n", i,
                   soDuThangN(100000000, 0.01, 50000, i));
        }
    }
}
