#include <stdio.h>

int sum(int s[], int n);
void swap(int *a, int*b);

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

void swap(int *a, int*b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
