#include <stdio.h>
#define MAX 15

typedef struct {
    int elem;
    int left;
    int right;
} node;

typedef node Tree[MAX];

void init(Tree A);
void insert(Tree A, int elem, int *root);
void displayInOrder(Tree A, int root);

int main() {
    Tree A;
    init(A);
    printf("Inserting\n");
    int root = -1;
    insert(A, 100, &root);
    insert(A, 50, &root);
    insert(A, 150, &root);
    insert(A, 25, &root);
    insert(A, 75, &root);
    insert(A, 15, &root);
    insert(A, 30, &root);
    insert(A, 60, &root);
    insert(A, 90, &root);
    // printf("In-order traversal:\n");
    // displayInOrder(A, root);
    return 0;
}

int findEmptyIndex(Tree A) {
    for (int x = 0; x < MAX; x++) {
        if (A[x].elem == -1) {
            return x;
        }
    }
    return -1; // Indicates no empty space found
}

void insert(Tree A, int elem, int *root) {
    int index = findEmptyIndex(A);
    if (index == -1) {
        printf("Tree is full. Cannot insert.\n");
        return;
    }
    *root = (*root == -1) ? index : *root;

    int parent = -1;
    int current = *root;

    for (;current != -1;) {
        parent = current;
        current = (elem < A[current].elem) ? A[current].left : A[current].right;
    }

    A[parent].left = (elem < A[parent].elem) ? index : A[parent].left;
    A[parent].right = (elem >= A[parent].elem) ? index : A[parent].right;

    A[index].elem = elem;
    A[index].left = A[index].right = -1;
}


void init(Tree A) {
    for (int x = 0; x < MAX; x++) {
        A[x].elem = A[x].left = A[x].right = -1;
    }
}

void displayInOrder(Tree A, int root) {
    if (root == -1) {
        return;
    }
    displayInOrder(A, A[root].left);
    printf("%d ", A[root].elem);
    displayInOrder(A, A[root].right);
}
