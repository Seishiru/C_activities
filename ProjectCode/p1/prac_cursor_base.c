#include <stdio.h>
#include "myHeader.c"

int main(){
    Vheap structure;
    Type group_a = -1;
    initHeap(&structure);
    visualSpace(structure);
    displayGroup(structure, group_a);
    insertFront(&structure, 'D', &group_a);
    visualSpace(structure);
    displayGroup(structure, group_a);
    insertFront(&structure, 'A', &group_a);
    visualSpace(structure);
    displayGroup(structure, group_a);
    insertFront(&structure, 'I', &group_a);
    visualSpace(structure);
    displayGroup(structure, group_a);
    // insertRear(&structure, 'S', &group_a);
    // visualSpace(structure);
    // displayGroup(structure, group_a);

    insertAtPosition(&structure, 8, 'K', &group_a);
    // deleteFront(&structure, &group_a);
    visualSpace(structure);
    displayGroup(structure, group_a);
}