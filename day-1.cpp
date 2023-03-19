#include <iostream>
using namespace std;

// Prototype
int sum(int s[], int n);
void swap(int* a, int* b);
void ffun();
void ffun01();
void sort(int arr[], int n);
void printArr(int arr[], int n);
void deleteArr(int arr[], int* n, int k);
void dedupeArr(int arr[], int* n);
void testDedupeArr();

int main() {
    int s[3];
    s[0] = 0;
    s[1] = 1;
    s[2] = 2;

    printf("sum %d\n", sum(s, 3));

    int a = 1;
    int b = 2;
    printf("before swap %d, %d\n", a, b);

    swap(&a, &b);
    printf("after swap %d, %d\n", a, b);

    ffun();

    ffun01();
    ffun01();

    int arr[5];
    arr[0] = 5;
    arr[1] = 4;
    arr[2] = 3;
    arr[3] = 2;
    arr[4] = 1;
    printArr(arr, 5);

    sort(arr, 5);
    printArr(arr, 5);

    int n = 5;
    deleteArr(arr, &n, 0);
    printArr(arr, n);

    testDedupeArr();

    return 0;
}

// Sum of n so nguyen in s array
int sum(int s[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += s[i];
    }

    return sum;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Manipulate pointer
void ffun() {
    int* a = new int[100];
    a[0] = 10;
    a[1] = 20;
    // Pointer b same address as pointer a
    int* b = a;
    printf("ffun *b %d\n", *b);
    printf("ffun *(b + 1) %d\n", *(b + 1));
}

void ffun01() {
    static int count = 0;

    printf("static count %d\n", count);

    count++;
}

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Delete k index of arr, change n aka len of arr
void deleteArr(int arr[], int* n, int k) {
    if (k < 0 || k >= *n) {
        return;
    }

    for (int i = k; i < (*n) - 1; i++) {
        arr[i] = arr[i + 1];
    }

    *n = (*n) - 1;
}

// 1 1 2 3 3 -> 1 2 3
void dedupeArr(int arr[], int* n) {
    int i = 0;
    while (true) {
        if (arr[i] == arr[i + 1]) {
            deleteArr(arr, n, i + 1);
        }

        i++;

        if (i >= (*n) - 1) {
            break;
        }
    }
}

void testDedupeArr() {
    int arr[5];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 3;
    printf("Pre dedupe\n");
    printArr(arr, 5);

    int n = 5;
    dedupeArr(arr, &n);

    printf("Post dedupe\n");
    printArr(arr, n);
}
