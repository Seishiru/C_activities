#include <stdio.h>
#define MAX 15


typedef struct {
    int elem;
    int left;
    int right;
}node;

typedef struct {
    node tree[MAX];
    int avail;
}BST_CB;

typedef int SET;

void initialize(BST_CB *A);
void display(BST_CB A);
void displaySet(BST_CB A, SET a);
void insert(BST_CB *A, SET *a, int elem);
void delete(BST_CB *A, SET *a, int elem);

int main() {
    BST_CB A;
    SET a = -1;
    initialize(&A);
    display(A);
    
    insert(&A, &a, 100);
    insert(&A, &a, 50);
    insert(&A, &a, 150);
    insert(&A, &a, 25);
    insert(&A, &a, 65);
    insert(&A, &a, 125);
    insert(&A, &a, 165);
    insert(&A, &a, 10);
    insert(&A, &a, 30);
    insert(&A, &a, 55);
    insert(&A, &a, 70);
    insert(&A, &a, 115);
    insert(&A, &a, 130);
    insert(&A, &a, 155);
    insert(&A, &a, 175);

    // delete(&A, &a, 50);
    // delete(&A, &a, 175);
    // delete(&A, &a, 100);
    // delete(&A, &a, 50);
    // delete(&A, &a, 10);
    // delete(&A, &a, 55);
    // delete(&A, &a, 130);
    // delete(&A, &a, 65);
    // delete(&A, &a, 155);
    
    // delete(&A, &a, 175);

   
	printf("\n\nAfter insert\n");
    printf("a: %d\n", a);
    display(A);

    delete(&A, &a, 175);
    delete(&A, &a, 100);
    printf("\n\nAfter delete\n");
    printf("a: %d\n", a);
    display(A);

}
void initialize(BST_CB *A) {
    int x;
    for(x = 0; x < MAX; x++) {
        A->tree[x].elem = A->tree[x].left = -1;
		A->tree[x].right = x - 1;
    }
    A->avail = MAX-1;
}
void display(BST_CB A) {
    int x;
    printf("\n----------------------------\n%-8s %-6s %-6s %-6s\n", "index", "left", "elem", "right");
    for(x = 0; x < MAX; x++) {
        printf("%-8d %-6d %-6d %-6d\n", x, A.tree[x].left, A.tree[x].elem, A.tree[x].right);
    }
    printf("Avail: %d\n----------------------------\n",A.avail);
}
void displaySet(BST_CB A, SET a) {
    
}
void insert(BST_CB *A, SET *a, int elem) {
    //check for available space
    if(A->avail == -1) {
        printf("No more available space to insert elem %d\n", elem);
    } else {
        int *trav;
        //Initial: trav gets the address of SET. 
        //Condition: checks whether it is the end of the list and non-duplicate element. 
        //Update: trav gets either left or right address subtree.
        for(trav = a; *trav != -1 && A->tree[*trav].elem != elem; trav = (A->tree[*trav].elem < elem)? &A->tree[*trav].right : &A->tree[*trav].left) { }
        //if it reach the end (-1), that means trav has free node. Else the element alreadt exist
        if(*trav == -1) {
            int getSpace = A->avail;
            A->avail = A->tree[getSpace].right;
            A->tree[getSpace].elem = elem;
            A->tree[getSpace].left = A->tree[getSpace].right = -1;
            *trav = getSpace;

            printf("Successfully inserted %d\n", elem);
        } else {
            printf("Element %d already exist\n", elem);
        }
    }
}
void delete(BST_CB *A, SET *a, int elem) {
    if (*a == -1) {
        printf("There is nothing to delete here\n");
        return;
    }

    int *trav = a;
    int *parent = NULL;

    // Find the node to delete
    while (*trav != -1 && A->tree[*trav].elem != elem) {
        parent = trav;
        trav = (elem < A->tree[*trav].elem) ? &A->tree[*trav].left : &A->tree[*trav].right;
    }

    if (*trav == -1) {
        printf("Element %d does not exist\n", elem);
        return;
    }

    // Case 1: No child or only one child
    if (A->tree[*trav].left == -1 || A->tree[*trav].right == -1) {
        int child = (A->tree[*trav].left == -1) ? A->tree[*trav].right : A->tree[*trav].left;

        // Update parent's link
        if (parent == NULL) {
            *a = child; // The root node is being deleted
        } else if (elem < A->tree[*parent].elem) {
            A->tree[*parent].left = child;
        } else {
            A->tree[*parent].right = child;
        }
        
        // Mark the deleted node as available
        A->tree[*trav].left = -1;
        A->tree[*trav].right = A->avail;
        A->avail = *trav;

        printf("Successfully deleted %d\n", elem);
    } else { // Case 2: Two children
        // Find the inorder successor (minimum value in the right subtree)
        int successor = A->tree[*trav].right;
        int successorParent = *trav;

        while (A->tree[successor].left != -1) {
            successorParent = successor;
            successor = A->tree[successor].left;
        }

        // Replace the value of the deleted node with the successor
        A->tree[*trav].elem = A->tree[successor].elem;

        // Remove the successor from its parent's link
        if (successorParent == *trav) {
            A->tree[successorParent].right = A->tree[successor].right;
        } else {
            A->tree[successorParent].left = A->tree[successor].right;
        }

        // Mark the successor node as available
        A->tree[successor].left = -1;
        A->tree[successor].right = A->avail;
        A->avail = successor;

        printf("Successfully deleted %d\n", elem);
    }
}
