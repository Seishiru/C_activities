#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define VH_SIZE 12

typedef char String[20];

typedef struct node {
    String elem;
    struct node *link;
} *listPtr;

typedef struct {
    String elem;
    int next;
}cursornode;

typedef struct {
    cursornode nodes[VH_SIZE];
    int avail;
} Vheap;

typedef struct {
    int elemIndex;
    int count;
    Vheap *VH;
}SET;


void insertSorted(String data, listPtr *L);
void populate(listPtr *L);
void printList(listPtr L);
void deleteList(listPtr *L);
/*CURSOR BASE*/
Vheap initCursorBase(Vheap VH);
void displayCursorList(Vheap VH);
void insertSortedCursor(String data, SET *S);
void populateCursor(SET *S);
SET initSET(SET S, Vheap *VH);
int getSpace(Vheap *VH);
void displaySet(SET S);

int main() {
    listPtr P = NULL;
    printf("\n[Address of P: %p]\n", &P);
    populate(&P);
    printList(P);
    deleteList(&P);
    printList(P);


    printf("\n-----------CURSOR BASE-------------\n");
    Vheap VH = initCursorBase(VH);
    displayCursorList(VH);

    SET S = initSET(S, &VH);
    populateCursor(&S);
    displayCursorList(VH);
    printf("ELEM INDEX: %d\n", S.elemIndex);
    displaySet(S);
    return 0;
}


void populate(listPtr *L) {
    String data[] = {
        "Smith", "Johnson", "Williams", "Brown", "Jones",
        "Miller", "Davis", "Garcia", "Rodriguez", "Wilson"
    };
    int count = 10;
    for (int x = 0; x < count; x++) {
        insertSorted(data[x], L);
    }
    
}
void printList(listPtr L) {
    printf("Last Names:\n");
    while (L != NULL) {
        printf("%s\n", L->elem);
        L = L->link;
    }
}
void deleteList(listPtr *L) {
    listPtr current = *L;
    listPtr next;

    while (current != NULL) {
        next = current->link; // Save the next pointer before freeing current
        free(current); // Free the memory allocated for current node
        current = next; // Move to the next node
    }

    *L = NULL; 
}
void insertSorted(String data, listPtr *L) {
    listPtr temp = (listPtr)malloc(sizeof(struct node));

    if(temp != NULL) {
        int count = 0;
        listPtr *trav;
        strcpy(temp->elem, data);
        temp->link = NULL;
        trav = L;
        for(trav = L; *trav != NULL && strcmp((*trav)->elem, temp->elem) < 0; trav = &(*trav)->link) { }
        temp->link = *trav;
        *trav = temp;
    }
    
}
Vheap initCursorBase(Vheap VH) {
    int x;
    for(x = 0; x < VH_SIZE; x++) {
        strcpy(VH.nodes[x].elem, "    ");
        VH.nodes[x].next = x - 1;
    }
    VH.avail = x - 1; 
    return VH;
}
void displayCursorList(Vheap VH) {
    printf("+---------------------------------------+\n");
    printf("|          Cursor-based List            |\n");
    printf("+-------+----------+-------------------+\n");
    printf("| Index | Element  |      Next         |\n");
    printf("+-------+----------+-------------------+\n");
    
    int current, index = 0;
    for(current = 0; current < VH_SIZE; current++){
        printf("| %-5d | %-8s | %-5d             |\n", index, VH.nodes[current].elem, VH.nodes[current].next);
        index++;
    }
    printf("+-------+----------+-------------------+\n");
}
void populateCursor(SET *S) {
    String data[] = {
        "Smith", "Johnson", "Williams", "Brown", "Jones",
        "Miller", "Davis", "Garcia", "Rodriguez", "Wilson"
    };
    int count = 10;
    for (int x = 0; x < count; x++) {
        insertSortedCursor(data[x], S);
    }
}
int getSpace(Vheap *VH) {
    int retSpace = VH->avail;
    if(retSpace != -1) {
        VH->avail = VH->nodes[retSpace].next;
    }
    return retSpace;
}
void insertSortedCursor(String data, SET *S) {
    int *trav;
    int space = getSpace(S->VH);
    
    for(trav = &(*S).elemIndex; *trav != -1 && strcmp(S->VH->nodes[*trav].elem, data) < 0; trav = &(*S).VH->nodes[*trav].next) { }


    S->VH->nodes[space].next = *trav;
    *trav = space;
    strcpy(S->VH->nodes[space].elem, data);
}


SET initSET(SET S, Vheap *VH) {
    return (SET){-1, 0, VH};
}
void displaySet(SET S) {
    int current = S.elemIndex;
    while (current != -1) {
        printf("[%d]%s -> ", current, S.VH->nodes[current].elem);
        current = S.VH->nodes[current].next;
    }
    printf("-1\n");
}




