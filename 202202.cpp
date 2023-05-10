#include <iostream>

using namespace std;

void cau_1();
void cau_2();
void cau_3();

int main() {
    printf("202202\n");
    cau_1();
    cau_2();
    cau_3();
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
    printf("cau 1\n");

    // Array init quick way
    int arr[5] = {5, 5, 3, 3, 1};
    // arr[0] = 5;
    // arr[1] = 5;
    // arr[2] = 3;
    // arr[3] = 3;
    // arr[4] = 1;

    print_arr(arr, 5);
    sort_arr(arr, 5);
    print_arr(arr, 5);

    int dedupe_len = 5;
    dedupe_arr(arr, &dedupe_len);
    printf("dedupe_len: %d\n", dedupe_len);
    print_arr(arr, dedupe_len);

    cau_1c(arr, dedupe_len, 4);
}

struct BinarySearchTree {
    int value;
    BinarySearchTree* left;
    BinarySearchTree* right;
};

BinarySearchTree* insertBST(BinarySearchTree* p, int value) {
    if (p == NULL) {
        BinarySearchTree* p = new BinarySearchTree();
        p->value = value;
        p->left = NULL;
        p->right = NULL;
        return p;
    }

    if (p->value == value) {
        return p;
    }

    if (p->value > value) {
        p->left = insertBST(p->left, value);
        return p;
    }

    p->right = insertBST(p->right, value);
    return p;
}

BinarySearchTree* findBST(BinarySearchTree* p, int value) {
    if (p == NULL) {
        return NULL;
    }

    if (p->value == value) {
        return p;
    }

    if (p->value > value) {
        return findBST(p->left, value);
    }

    return findBST(p->right, value);
}

void deleteBST(BinarySearchTree* p) {
    if (p == NULL) {
        return;
    }

    deleteBST(p->left);
    deleteBST(p->right);

    // printf("Delete %d\n", p->value);
    delete p;
}

// Pre order N L R
void printBST(BinarySearchTree* p, int level) {
    if (p == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("->");
    }
    printf("%d\n", p->value);

    printBST(p->left, level + 1);
    printBST(p->right, level + 1);
}

// Tim m lon nhat sao cho m <= k
BinarySearchTree* cau_2c(BinarySearchTree* p, int k) {
    if (p == NULL) {
        return NULL;
    }

    if (p->value < k) {
        BinarySearchTree* found = cau_2c(p->right, k);
        if (found != NULL) {
            return found;
        }
    }

    // Sau khi de quy ben phai nhung van khong ra ket qua
    // Maybe p chua gia tri minh can tim
    printf("p->value %d\n", p->value);
    if (p->value <= k) {
        return p;
    }

    // p > k, cau tra loi nam o ben trai
    return cau_2c(p->left, k);
}

void cau_2() {
    printf("cau 2\n");

    BinarySearchTree* head = NULL;
    head = insertBST(head, 5);
    insertBST(head, 2);
    insertBST(head, 1);
    insertBST(head, 3);
    insertBST(head, 8);
    insertBST(head, 6);
    insertBST(head, 9);
    printBST(head, 0);

    BinarySearchTree* found = findBST(head, 9);
    if (found != NULL) {
        printf("found %d\n", found->value);
    }

    found = findBST(head, 10);
    if (found != NULL) {
        printf("found %d\n", found->value);
    } else {
        printf("not found %d\n", 10);
    }

    int k = 7;
    found = cau_2c(head, k);
    if (found != NULL) {
        printf("found %d\n", found->value);
    } else {
        printf("not found with k %d\n", k);
    }

    deleteBST(head);
}

class ThietBiDien {
  protected:
    string ten;
    string ma_so;
    int vi_tri;
    bool is_turn_on;

  public:
    virtual void Trigger() {
        this->is_turn_on = !this->is_turn_on;
        printf("Trigger %d\n", this->is_turn_on);
    }
};

class Den : public ThietBiDien {
  protected:
    int do_sang;
};

class DenNgu : public Den {
  private:
    int mau_sang;

  public:
    void update_mau_sang(int mau_sang) { this->mau_sang = mau_sang; }
};

class DenChieuSan : public Den {};

class DieuHoa : public ThietBiDien {
  private:
    int nhiet_do;
    int che_do;
    int muc_do;

  public:
    void update_nhiet_do(int nhiet_do) { this->nhiet_do = nhiet_do; }
};

class TV : public ThietBiDien {
  private:
    int am_luong;
    int kenh;
};

void cau_3() {
    printf("cau_3\n");

    ThietBiDien* arr[3];
    // ThietBiDien** arr = new ThietBiDien*[3];

    arr[0] = new DenNgu();
    arr[1] = new DieuHoa();
    arr[2] = new TV();

    for (int i = 0; i < 3; i++) {
        arr[i]->Trigger();
    }

    for (int i = 0; i < 3; i++) {
        arr[i]->Trigger();
    }
}
