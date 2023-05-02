#include <iostream>
#include <vector>

using namespace std;

void cau_1();

int main() {
    printf("202202\n");
    cau_1();
}

void print_arr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort_arr(int* arr, int n) {
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

void dedupe_arr(int* arr, int* n) {
    // No need to dedupe for empty or only 1 array
    if (*n == 0 || *n == 1) {
        return;
    }

    sort_arr(arr, *n);

    // Init new array with only 1 element from old
    int* new_arr = new int[*n];
    new_arr[0] = arr[0];
    int new_len = 1;

    for (int i = 1; i < *n; i++) {
        // Skip duplicate element
        if (arr[i] == arr[i - 1]) {
            continue;
        }

        // Insert arr[i]
        new_arr[new_len] = arr[i];
        new_len++;
    }

    // Copy new array to old array
    for (int i = 0; i < new_len; i++) {
        arr[i] = new_arr[i];
    }

    // Can change *n
    *n = new_len;

    delete[] new_arr;
}

void cau_1c(int* arr, int n, int k) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < k && arr[i + 1] > k) {
            printf("a b: %d %d\n", arr[i], arr[i + 1]);
        }
    }
}

void cau_1() {
    int arr[5];
    arr[0] = 5;
    arr[1] = 5;
    arr[2] = 3;
    arr[3] = 3;
    arr[4] = 1;

    print_arr(arr, 5);
    sort_arr(arr, 5);
    print_arr(arr, 5);

    int dedupe_len = 5;
    dedupe_arr(arr, &dedupe_len);
    printf("dedupe_len: %d\n", dedupe_len);
    print_arr(arr, dedupe_len);

    cau_1c(arr, dedupe_len, 4);
}
