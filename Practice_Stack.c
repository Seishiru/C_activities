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

void initializeVheap(Vheap *container);
void displayVheap(Vheap container);
void push(Vheap *container, char elem, Group *type);
int allocateSpace(Vheap *container);
char peek(Vheap container, Group type);
char pop(Vheap *container, Group *type);
bool isEmpty(Vheap container);
bool isFull(Vheap container);
int size(Vheap container);
int search(Vheap *container,char elem ,Group *type);
Vheap reverse(Vheap *container, Group *type);
void Sort(Vheap *container, Group type);
char getHigh(Vheap container, Group type);
char getLowest(Vheap container, Group type);
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
    
    //printf("INDEX FOUND AT: %d\n",search(&container, 'D', &A));

    displayVheap(container);
    printf("Group A: %d\n", A);
    printf("PEEK: %c\n", peek(container, A));
    printf("SIZE: %d\n", size(container));


    printf("----------------------------------------\n");
    container = reverse(&container, &A);
    
    Sort(&container, A);

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
int search(Vheap *container, char elem, Group *type) {
    int temp = *type;
    for (; temp != -1 && peek(*container, temp) != elem; temp = *type) {
        pop(container, type);
    }
    return *type;
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
void Sort(Vheap *container, Group type){
    
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
