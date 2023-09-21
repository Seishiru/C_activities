
#ifndef MYHEADER_H
#define MYHEADER_H

#define MAX 10

typedef struct {
    char letter;
    int next_index;
} Data;

typedef struct {
    Data box[MAX];
    int available_box;
} Vheap;

typedef int Type;
//Initialize ELEM to '\0' and NEXT to MAX-2 to -1
void initHeap(Vheap *structure);
//Visualization INDEX is the index of the Box, ELEM is the letter and NEXT is linking to the next Box
void visualSpace(Vheap structure);
//Remember if there is nothing you can see in the ELEM, it means there is no space or memory to hold a value so we allocate space by getting the available index but before getting the available index we must get the next value of the Box
int allocateSpace(Vheap *structure);

void insertFront(Vheap *structure, char element, Type *group);

void displayGroup(Vheap structure, Type group);
//This function will only call by any delete function
void deallocateSpace(Vheap *structure, int index_position);

void deleteFront(Vheap *structure, Type *group);

void insertRear(Vheap *structure, char element, Type *group);
//Insert at position. Min range from 0 to MAX-1. The available space will just swap with the position you want to insert. 
void insertAtPosition(Vheap *structure, int position, char element, Type *group);
#endif /* MYHEADER_H */
