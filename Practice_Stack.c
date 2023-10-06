#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef int Group;
typedef struct {
    char storage;
    int next_storage;
} Data;

typedef struct {
    Data box[MAX];
    int available_box;
} Vheap;
// Initialize the Vheap container with empty values and set the available box index.
void initializeVheap(Vheap *container);
// Display the contents of the Vheap container, including storage, next_storage, and available_box.
void displayVheap(Vheap container);
// Push (insert) an element 'elem' into the Vheap container with the specified 'type'.
// The 'type' parameter is updated to point to the newly added element.
void push(Vheap *container, char elem, Group *type);
// Allocate space for a new element in the Vheap container and return the index of the allocated space.
// It also updates the 'available_box' index to maintain the available space.
int allocateSpace(Vheap *container);
// Peek at the element in the Vheap container that corresponds to the given 'type'.
// Returns the character stored at that location.
char peek(Vheap container, Group type);
// Pop (remove) the element from the Vheap container associated with the specified 'type'.
// Returns the character stored at that location.
// It also updates the 'type' parameter to point to the next element.
char pop(Vheap *container, Group *type);
//Check if the stack is empty. This operation can help you determine whether there are any elements in the stack.
bool isEmpty(Vheap container);
//Check if the stack is full. This is important in cases where the stack has a maximum capacity, and you want to ensure you don't exceed it.
bool isFull(Vheap container);
//Get the current number of elements in the stack. This operation provides the size of the stack without modifying its contents.
int size(Vheap container);
//Search for a specific element within the stack and return its position/index. This operation would involve popping elements one by one until the target is found or the stack is empty.
int search(Vheap container,char elem ,Group type);
//Reverse the order of elements in the stack. This operation can be achieved by popping all elements from the original stack and pushing them onto a new stack.
Vheap reverse(Vheap *container, Group *type);
//Sort the elements in the stack if they are comparable. You can pop all elements into an array, perform sorting on the array, and then push them back onto the stack.
void sort(Vheap *container, Group type);
//Get the highest (maximum) character value from the elements in the Vheap container associated with the specified 'type'.
char getHigh(Vheap container, Group type);
// Get the lowest (minimum) character value from the elements in the Vheap container associated with the specified 'type'.
char getLowest(Vheap container, Group type);
//Combine two stacks into one. This is especially useful when working with multiple stacks and you want to consolidate their contents.
Vheap merge();
//Implement an iterator or enumerator to iterate through all elements in the stack. This can be helpful when you need to process or display all elements.
void iterator();
//Extend the Peek operation to allow you to peek at the nth element from the top without removing it.
char peekN();
//Push a collection of elements onto the stack in one operation, which can be useful when you have multiple elements to add at once.
void pushAll();
int main() {
    Vheap container;
    Group A = -1;
    initializeVheap(&container);
    // displayVheap(container);

    push(&container, 'C', &A);
    push(&container, 'A', &A);
    push(&container, 'K', &A);
    push(&container, 'Z', &A);
    push(&container, 'U', &A);
    
    printf("INDEX FOUND AT: %d\n",search(container, 'K', A));

    displayVheap(container);
    printf("Group A: %d\n", A);
    printf("PEEK: %c\n", peek(container, A));
    printf("SIZE: %d\n", size(container));


    printf("----------------------------------------\n");
    container = reverse(&container, &A);
    
    sort(&container, A);

    displayVheap(container);
    printf("Group A: %d\n", A);
    printf("PEEK: %c\n", peek(container, A));
    printf("SIZE: %d\n", size(container));
  
    return 0;
}

void initializeVheap(Vheap *container) {
    container->available_box = MAX - 1;
    size_t x;
    for (x = 0; x < MAX; x++) {
        container->box[x].storage = '\0'; // \0 represents empty
        container->box[x].next_storage = x - 1;
    }
}
void displayVheap(Vheap container) {
    size_t x;

    printf("\nINDEX    | STORAGE   | NEXT_STORAGE\n"); // Adjusted column spacing
    for (x = 0; x < MAX; x++) {
        printf("%-8d | %-9c | %-13d\n", x, container.box[x].storage, container.box[x].next_storage); // Adjusted spacing
    }
    printf("AVAILABLE BOX: %d\n", container.available_box);
}
void push(Vheap *container, char elem, Group *type){
    int getSpace = allocateSpace(container);    //get space
    if (getSpace != -1){
        container->box[getSpace].storage = elem;
        container->box[getSpace].next_storage = *type;
        *type = getSpace;
    }
}
int allocateSpace(Vheap *container){
    int temp = container->available_box;    
    if(temp >= 0){
        container->available_box = container->box[temp].next_storage;   //Changes the available_box to the value of next_storage
    }
    return temp;
}
char peek(Vheap container, Group type) {
    if (type >= 0 && type < MAX) {
        return container.box[type].storage;
    }
}
char pop(Vheap *container, Group *type){
    int temp = *type;
    char element = container->box[*type].storage;
    if (temp != -1){
        container->box[temp].storage = '\0';
        *type = container->box[temp].next_storage;
        container->available_box = temp;
    }
    return element;
}
bool isEmpty(Vheap container) {
    return (container.available_box == MAX - 1);
}
bool isFull(Vheap container){
    return (container.available_box == -1);
}
int size(Vheap container) {
    return (MAX - 1) - container.available_box;
}
int search(Vheap container, char elem, Group type) {
    int temp = type;
    Vheap copyContainer = container; // Create a copy of the container
    
    for (; temp != -1 && peek(copyContainer, temp) != elem; temp = type) {
        pop(&copyContainer, &type); // Pop from the copy, not the original container
    }
    
    return type;
}
Vheap reverse(Vheap *container, Group *type){
    Vheap temporaryContainer;
    initializeVheap(&temporaryContainer);
    int getSpace = -1;
    int temp = *type;
    int tempII = *type;
    for(;temp != -1; temp = *type){
        getSpace = allocateSpace(&temporaryContainer);
        temporaryContainer.box[getSpace].storage = container->box[temp].storage;
        temporaryContainer.box[getSpace].next_storage = container->box[getSpace].next_storage;
        pop(container, type);
    }
    *type = tempII;
    return temporaryContainer;
}
void sort(Vheap *container, Group type){
    
    Vheap containerII;
    initializeVheap(&containerII);
    Group typeII = -1;

    Vheap containerIII;
    initializeVheap(&containerIII);
    Group typeIII = -1;
    // im thinking i should create another container
    char temp = getHigh(*container, type);
    while(type != -1){
        typeII = allocateSpace(&containerII);
        containerII.box[typeII].storage = container->box[type].storage;
        containerII.box[typeII].next_storage = container->box[typeII].next_storage;
        if(container->box[type].storage == temp){
            typeIII = allocateSpace(&containerIII);
            containerIII.box[typeIII].storage = container->box[type].storage;
            containerIII.box[typeIII].next_storage = container->box[typeIII].next_storage;
        }
        type = container->box[type].next_storage;
    }
}
char getHigh(Vheap container, Group type) {
    if (type == -1) {
        // Handle empty container
        return '\0';
    }

    char highest = container.box[type].storage;
    type = container.box[type].next_storage;

    while (type != -1) {
        if (container.box[type].storage > highest) {
            highest = container.box[type].storage;
        }
        pop(&container, &type);
        type = container.box[type].next_storage;
    }

    return highest;
}
char getLowest(Vheap container, Group type) {
    if (type == -1) {
        // Handle empty container
        return '\0';
    }

    char lowest = container.box[type].storage;
    type = container.box[type].next_storage;

    while (type != -1) {
        if (container.box[type].storage < lowest) {
            lowest = container.box[type].storage;
        }
        pop(&container, &type);
        type = container.box[type].next_storage;
    }

    return lowest;
}

/*
    Some things to note:

    - sort is not completed
    - other functions have not yet implemented
    
    As of October 06 2023, 4:06pm
    Cecil Quibranza
*/
