#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void faulter(Node *current) {
    current->data = 10; // Accessing a NULL pointer will cause a segmentation fault
}

int main() {
    Node* head = NULL;
    Node* current = head;

    faulter(current);

    return 0;
}