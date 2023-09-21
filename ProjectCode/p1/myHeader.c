#include <stdio.h>
#include "myHeader.h" // Include your header file to access the struct and constant


void initHeap(Vheap *structure){
    int x = 0;
    for (x = MAX-1; x >= 0; x--)
    {
        structure->box[x].letter = '\0';
        structure->box[x].next_index = x-1;
    }
    structure->available_box = MAX-1;
    
}
void visualSpace(Vheap structure) {
    int x;
    printf("\n\t\t%15s | %15s | %15s\n", "INDEX", "ELEM", "NEXT");
    for (x = 0; x < MAX; x++) {
        printf("\t\t%15d | %15c | %15d\n", x, structure.box[x].letter, structure.box[x].next_index);
    }
    printf("Available: %d Index\n", structure.available_box);
    if (structure.available_box == -1) {
        printf("Not available to insert\n");
    }
}
int allocateSpace(Vheap *structure){
    int available_space = structure->available_box;
    if(available_space != -1){
        structure->available_box = structure->box[available_space].next_index;
    }
    return available_space;
}
void insertFront(Vheap *structure, char element, Type *group){
    int getSpace = allocateSpace(structure);
    if(getSpace != -1){
        structure->box[getSpace].letter = element;
        structure->box[getSpace].next_index = *group;
        *group = getSpace;
    }
}
void displayGroup(Vheap structure, Type group) {
    int x;
    printf("Type group: %d index {",group);
    for (x = group; x != -1; x = structure.box[x].next_index) {
        printf("%c", structure.box[x].letter);
        if (structure.box[x].next_index != -1) {
            printf(" -> ");
        }
    }
    printf("}\n");
}
void deallocateSpace(Vheap *structure, int index_position){
    if(index_position != -1 && index_position < MAX){
        structure->box[index_position].next_index = structure->available_box;
        structure->available_box = index_position;
    }
}
void deleteFront(Vheap *structure, Type *group){
    int holder = *group;
    //if *group was -1 then that means it was empty
    if(*group != -1){
        structure->box[*group].letter = '\0';
        //*group will get the value of the next box
        *group = structure->box[*group].next_index;
        deallocateSpace(structure, holder);
    }
}
void insertRear(Vheap *structure, char element, Type *group) {
    int available_space = allocateSpace(structure);
    
    if (available_space != -1) {
        if (*group == -1) {
            // If the group is empty, set *group to the available space
            *group = available_space;
        } else {
            int last_index = *group;
            for (; structure->box[last_index].next_index != -1; last_index = structure->box[last_index].next_index) {
                // Loop until we find the last element
            }
            // Update the next_index of the last element to the available space
            structure->box[last_index].next_index = available_space;
        }
        
        // Initialize the available space with the element and set its next_index to -1
        structure->box[available_space].letter = element;
        structure->box[available_space].next_index = -1;
    }
}
void insertAtPosition(Vheap *structure, int position, char element, Type *group) {
    int available_space = allocateSpace(structure);
    
    if (available_space != -1) {
        // Insert the element at the available space
        structure->box[available_space].letter = element;
        
        if (position == -1) {
            // If the position is -1, insert at the beginning
            structure->box[available_space].next_index = *group;
            *group = available_space;
        } else {
            // Find the element before the specified position
            int prev_index = -1;
            int current_index = *group;
            
            while (current_index != -1 && current_index != position) {
                prev_index = current_index;
                current_index = structure->box[current_index].next_index;
            }
            
            // Insert the available space between prev_index and position
            structure->box[prev_index].next_index = available_space;
            structure->box[available_space].next_index = position;
        }
    }
}

