#include <iostream>
#include <string>

using namespace std;

void cau_1();
void cau_2();
void cau_3();

int main() {
    printf("202201\n");
    cau_1();
    cau_2();
    cau_3();
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

struct NodeNguyen {
    int value;
    NodeNguyen* next;
    NodeNguyen* pre;
};

void print_node(NodeNguyen* p) {
    for (;;) {
        if (p == NULL) {
            printf("NULL\n");
            return;
        }

        printf("%d->", p->value);
        p = p->next;
    }
}

void delete_node(NodeNguyen* p) {
    for (;;) {
        if (p == NULL) {
            return;
        }

        NodeNguyen* temp = p;
        p = p->next;
        delete temp;
    }
}

NodeNguyen* create_node(int* arr, int n) {
    if (n < 1) {
        return NULL;
    }

    NodeNguyen* head = new NodeNguyen();
    head->value = arr[0];

    NodeNguyen* pre = head;
    for (int i = 1; i < n; i++) {
        NodeNguyen* p = new NodeNguyen();
        p->value = arr[i];
        p->pre = pre;

        pre->next = p;
        pre = p;
    }

    return head;
}

NodeNguyen* find_pre_k(NodeNguyen* p, int k) {
    for (;;) {
        if (p == NULL) {
            return NULL;
        }

        if (p->value == k) {
            return p->pre;
        }

        p = p->next;
    }
}

// Return new head if head is k
NodeNguyen* delete_k(NodeNguyen* p, int k) {
    NodeNguyen* head = p;

    for (;;) {
        if (p == NULL) {
            break;
        }

        NodeNguyen* pre = p->pre;
        NodeNguyen* next = p->next;
        if (p->value == k) {
            if (pre == NULL) {
                // Only head has no pre
                head = next;
            } else {
                pre->next = next;

                if (next != NULL) {
                    next->pre = pre;
                }
            }

            delete p;
        }

        p = next;
    }

    return head;
}

NodeNguyen* merge_already_sorted(NodeNguyen* p, NodeNguyen* q) {
    NodeNguyen* head = NULL;
    NodeNguyen* pre = NULL;

    for (;;) {
        if (p == NULL && q == NULL) {
            break;
        }

        // if (p != NULL) {
        //     printf("p %d\n", p->value);
        // }

        // if (q != NULL) {
        //     printf("q %d\n", q->value);
        // }

        // p or q can be NULL
        bool choose_p = false;
        if (q == NULL) {
            choose_p = true;
        } else {
            if (p != NULL && p->value < q->value) {
                choose_p = true;
            }
        }

        if (choose_p) {
            if (pre != NULL) {
                pre->next = p;
            }
            p->pre = pre;
            pre = p;
            p = p->next;

            // Not init head yet
            if (head == NULL) {
                head = pre;
            }
        } else {
            if (pre != NULL) {
                pre->next = q;
            }
            q->pre = pre;
            pre = q;
            q = q->next;

            // Not init head yet
            if (head == NULL) {
                head = pre;
            }
        }
    }

    return head;
}

void cau_2() {
    printf("cau_2\n");
    int arr[4] = {1, 2, 3, 4};
    NodeNguyen* p = create_node(arr, 4);
    print_node(p);

    int k = 3;
    NodeNguyen* found = find_pre_k(p, k);
    if (found != NULL) {
        printf("found pre k %d is %d\n", k, found->value);
    } else {
        printf("not found pre k %d\n", k);
    }

    k = 1;
    NodeNguyen* new_head = delete_k(p, k);
    print_node(new_head);

    delete_node(new_head);

    {
        int arr_p[4] = {1, 3, 5, 7};
        NodeNguyen* p = create_node(arr_p, 4);
        print_node(p);

        int arr_q[4] = {2, 4, 6, 8};
        NodeNguyen* q = create_node(arr_q, 4);
        print_node(q);

        NodeNguyen* new_head = merge_already_sorted(p, q);
        print_node(new_head);
        delete_node(new_head);
    }

    {
        int arr_p[4] = {1, 3, 5, 7};
        NodeNguyen* p = create_node(arr_p, 4);
        print_node(p);

        int arr_q[4] = {2, 4, 6, 8};
        NodeNguyen* q = create_node(arr_q, 4);
        print_node(q);

        NodeNguyen* new_head = merge_already_sorted(q, p);
        print_node(new_head);
        delete_node(new_head);
    }
}

class Observer {
  public:
    virtual void update() = 0;
};

class Button {
  private:
    Observer** observers;
    int index = 0;

  public:
    Button() {
        this->observers = new Observer*[4];
        this->index = 0;
    }

    ~Button() { delete[] this->observers; }

    void addObserver(Observer* obs) {
        this->observers[this->index] = obs;
        this->index++;
    }

    void removeOberver(Observer* obs) {
        // TOOD
    }

    void notify() {
        for (int i = 0; i < index; i++) {
            this->observers[i]->update();
        }
    }
};

class Frame : public Observer {
  public:
    void update() { printf("Update Frame\n"); }
};

class Window : public Observer {
  public:
    void update() { printf("Update Window\n"); }
};

class Application {
  public:
    void main() {
        Button* btn = new Button();
        Frame* f = new Frame();
        btn->addObserver(f);
        Window* w = new Window();
        btn->addObserver(w);
        btn->notify();
        delete w;
        delete f;
        delete btn;
    }
};

void cau_3() {
    printf("cau_3\n");

    Application* app = new Application();
    app->main();
    delete app;
}
