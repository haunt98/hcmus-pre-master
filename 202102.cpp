#include <iostream>
#include <string>

using namespace std;

void cau_1();

int main() {
    printf("202102\n");
    cau_1();
}

struct QueueNode {
    int value;
    QueueNode* next;
};

void print_queue_node(QueueNode* p) {
    for (;;) {
        if (p == NULL) {
            printf("NULL\n");
            return;
        }

        printf("%d->", p->value);
        p = p->next;
    }
}

struct Queue {
    QueueNode* head;
    QueueNode* tail;
};

void enqueue(Queue* q, int value) {
    if (q == NULL) {
        return;
    }

    QueueNode* p = new QueueNode();
    p->value = value;

    if (q->head == NULL) {
        q->head = p;
        q->tail = p;
        return;
    }

    // Append to tail
    q->tail->next = p;
    q->tail = p;
}

QueueNode* dequeue(Queue* q) {
    if (q == NULL || q->head == NULL) {
        return NULL;
    }

    QueueNode* temp = q->head;

    // Move head
    q->head = q->head->next;

    // List only have 1, move head = return to empty
    if (q->head == NULL) {
        q->tail = NULL;
    }

    return temp;
}

void cau_1_ab() {
    printf("cau_1_ab\n");
    Queue* q = new Queue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    print_queue_node(q->head);

    QueueNode* p = dequeue(q);
    if (p != NULL) {
        printf("Dequeue %d\n", p->value);
        delete p;
    }

    p = dequeue(q);
    if (p != NULL) {
        printf("Dequeue %d\n", p->value);
        delete p;
    }

    p = dequeue(q);
    if (p != NULL) {
        printf("Dequeue %d\n", p->value);
        delete p;
    }

    p = dequeue(q);
    if (p != NULL) {
        printf("Dequeue %d\n", p->value);
        delete p;
    }

    delete q;
}

struct PriorityQueueNode {
    int value;
    // The bigger the more important
    int priority;
    PriorityQueueNode* next;
};

struct PriorityQueue {
    PriorityQueueNode* head;
    PriorityQueueNode* tail;
};

void print_priority_queue_node(PriorityQueueNode* p) {
    for (;;) {
        if (p == NULL) {
            printf("NULL\n");
            return;
        }

        printf("(%d, p%d)->", p->value, p->priority);
        p = p->next;
    }
}

void enqueue_priority(PriorityQueue* q, int value, int priority) {
    if (q == NULL) {
        return;
    }

    PriorityQueueNode* p = new PriorityQueueNode();
    p->value = value;
    p->priority = priority;

    if (q->head == NULL) {
        q->head = p;
        q->tail = p;
        return;
    }

    // Append to tail
    q->tail->next = p;
    q->tail = p;
}

PriorityQueueNode* dequeue_priority(PriorityQueue* q) {
    if (q == NULL || q->head == NULL) {
        return NULL;
    }

    int max_priority = -1;
    PriorityQueueNode* prev_max = NULL;
    PriorityQueueNode* max = NULL;
    PriorityQueueNode* prev_p = NULL;
    PriorityQueueNode* p = q->head;
    for (;;) {
        if (p == NULL) {
            break;
        }

        if (p->priority > max_priority) {
            max_priority = p->priority;
            prev_max = prev_p;
            max = p;
        }

        prev_p = p;
        p = p->next;
    }

    // Need to dequeue max
    if (prev_max == NULL) {
        // max is head
        // NULL -> max -> ... -> NULL
        q->head = max->next;

        if (q->head == NULL) {
            // NULL -> max -> NULL
            q->tail = NULL;
        }
    } else {
        // ... -> prev_max -> max -> ...
        prev_max->next = max->next;

        if (prev_max->next == NULL) {
            // max is tail
            // ... -> prev_max -> max -> NULL
            q->tail = prev_max;
        }
    }

    return max;
}

void cau_1_cd() {
    printf("cau_1_cd\n");

    PriorityQueue* q = new PriorityQueue();
    enqueue_priority(q, 1, 1);
    enqueue_priority(q, 2, 1);
    enqueue_priority(q, 3, 1);
    enqueue_priority(q, 4, 3);
    enqueue_priority(q, 5, 3);
    enqueue_priority(q, 6, 2);
    enqueue_priority(q, 7, 2);

    print_priority_queue_node(q->head);

    PriorityQueueNode* p = dequeue_priority(q);
    if (p != NULL) {
        printf("Dequeue (%d, p%d)\n", p->value, p->priority);
        delete p;
    }
    print_priority_queue_node(q->head);

    p = dequeue_priority(q);
    if (p != NULL) {
        printf("Dequeue (%d, p%d)\n", p->value, p->priority);
        delete p;
    }
    print_priority_queue_node(q->head);

    p = dequeue_priority(q);
    if (p != NULL) {
        printf("Dequeue (%d, p%d)\n", p->value, p->priority);
        delete p;
    }
    print_priority_queue_node(q->head);

    p = dequeue_priority(q);
    if (p != NULL) {
        printf("Dequeue (%d, p%d)\n", p->value, p->priority);
        delete p;
    }
    print_priority_queue_node(q->head);

    p = dequeue_priority(q);
    if (p != NULL) {
        printf("Dequeue (%d, p%d)\n", p->value, p->priority);
        delete p;
    }
    print_priority_queue_node(q->head);

    p = dequeue_priority(q);
    if (p != NULL) {
        printf("Dequeue (%d, p%d)\n", p->value, p->priority);
        delete p;
    }
    print_priority_queue_node(q->head);

    p = dequeue_priority(q);
    if (p != NULL) {
        printf("Dequeue (%d, p%d)\n", p->value, p->priority);
        delete p;
    }
    print_priority_queue_node(q->head);

    delete q;
}

void cau_1() {
    printf("cau_1\n");

    cau_1_ab();
    cau_1_cd();
}

struct BinaryNode {
    int value;
    BinaryNode* left;
    BinaryNode* right;
};

BinaryNode* find_k(BinaryNode* p, int k) {
    for (;;) {
        if (p == NULL) {
            break;
        }

        if (p->value == k) {
            return p;
        }

        if (p->value > k) {
            p = p->left;
        } else {
            p = p->right;
        }
    }

    return NULL;
}

void print_giam_dan(BinaryNode* p) {
    if (p == NULL) {
        return;
    }

    print_giam_dan(p->right);
    printf("%d ", p->value);
    print_giam_dan(p->left);
}

// Binary tree
// > left child
// < right child
// Binary search tree
// > all left nodes -> > max all left nodes (the most right of left child)
// < all right nodes -> < min all right nodes (the most left of right child)
// https://afteracademy.com/blog/check-if-a-binary-tree-is-BST-or-not/
bool is_binary_tree(BinaryNode* p) {
    if (p == NULL) {
        return true;
    }

    if (p->left != NULL) {
        BinaryNode* max_left = p->left;
        while (max_left->right != NULL) {
            max_left = max_left->right;
        }

        if (p->value < max_left->value) {
            return false;
        }

        if (!is_binary_tree(p->left)) {
            return false;
        }
    }

    if (p->right != NULL) {
        BinaryNode* min_right = p->right;
        while (min_right->left != NULL) {
            min_right = min_right->left;
        }

        if (p->value > min_right->value) {
            return false;
        }

        if (!is_binary_tree(p->right)) {
            return false;
        }
    }

    return true;
}

class DataStorage {
  public:
    string Name;
    virtual int getSize() = 0;
};

class File : public DataStorage {
  public:
    int getSize() { return 1; }
};

class Folder : public DataStorage {
  private:
    DataStorage** children;
    int n;

  public:
    int getSize() {
        int size = 0;
        for (int i = 0; i < n; i++) {
            size += this->children[i]->getSize();
        }
        return size;
    }
};

void cau_3() { printf("cau_3\n"); }
