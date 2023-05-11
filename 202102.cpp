#include <iostream>

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

void delete_queue_node(QueueNode* p) {
    for (;;) {
        if (p == NULL) {
            return;
        }

        QueueNode* next = p->next;
        delete p;
        p = next;
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

void cau_1() {
    printf("cau_1\n");
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
