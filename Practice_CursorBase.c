#include <stdio.h>
#define MAX 10

typedef int Type;
typedef int Position;
typedef int List;

typedef struct{
    Type elem;
    Position next;
}NodeType;

typedef struct{
    NodeType data[MAX];
    Position avail;
}VSpace;

void initHeap(VSpace *vs);
void visualSpace(VSpace vs);
void displayList(VSpace vs, List list);
Position alloSpace(VSpace *vs);
void freeSpace(VSpace *vs, Position index);
void insertFront(VSpace *vs, List *list, Type item);
void deleteFront(VSpace *vs, List *list);

void insertRear(VSpace *vs, List *list, Type item);
void insertAfter(); //This function inserts a new element after a specific element in the linked list.
void deleteElement();
Position findElement();
void reverseList(); //This function reverses the order of elements in the linked list.
void sortList();
List mergeLists();
int listLength();

int main(){
    List listA = -1;
    List listB = -1;
    List listC = -1;
    VSpace mySpace;
    initHeap(&mySpace);
   
    insertFront(&mySpace, &listA, 130);
    displayList(mySpace, listA);
    insertFront(&mySpace, &listA, 140);
    insertFront(&mySpace, &listA, 170);
    displayList(mySpace, listA);
    visualSpace(mySpace);

    // insertFront(&mySpace, &listB, 200);
    // insertFront(&mySpace, &listB, 230);

    insertRear(&mySpace, &listA, 163);
    printf("List A %d\n", listA);
    visualSpace(mySpace);
    displayList(mySpace, listA);
    //displayList(mySpace, listB);
    // displayList(mySpace, listC);



    return 0;
}

void initHeap(VSpace *vs){
    int x;
    for(x=MAX-1; x>=0; --x){
        vs->data[x].elem = 0; //Set elements 0 as default or empty
        vs->data[x].next = x-1;
    }
    vs->avail = MAX-1;
}

void visualSpace(VSpace vs){
    int x;
    printf("%15s | %15s | %15s\n", "INDEX", "ELEM", "NEXT");
    for(x=0; x<MAX; x++){
        printf("%15d | %15d | %15d\n", x, vs.data[x].elem, vs.data[x].next);
    }
    printf("Available: %d Index\n", vs.avail);
}

void displayList(VSpace vs, List list){
    int x;
    printf("{");
    for(x = list; x != -1; x = vs.data[x].next){
        printf("%d", vs.data[x].elem);
        if(vs.data[x].next != -1){
            printf(", ");
        }
    }
    printf("}\n");
}

Position alloSpace(VSpace *vs){
    Position avail = vs->avail;
    if(avail != -1){
        vs->avail = vs->data[avail].next;
    }
    return avail;
}

void freeSpace(VSpace *vs, Position index){
    if(index != -1 && index < MAX){
        vs->data[index].next = vs->avail;
        vs->avail = index;
    }
}

void insertFront(VSpace *vs, List *list, Type item){
    Position temp = alloSpace(vs); //lets say 9 index

    if(temp != -1){
        vs->data[temp].elem = item; //lets say C
        vs->data[temp].next = *list; // the .next of it will change into -1
        *list = temp; // then my -1 or *list will turn into 9
    }
}

void deleteFront(VSpace *vs, List *list){
    Position temp = *list;

    if(*list != -1){
        vs->data[*list].elem = 0;   //Marks the elem as empty
        *list = vs->data[*list].next;
        freeSpace(vs, temp);
    }
}

void insertRear(VSpace *vs, List *list, Type item) {
    int temp = alloSpace(vs); // Allocate space for the new element
    if (temp != -1) {
        vs->data[temp].elem = item;
        vs->data[temp].next = -1; // Set the next pointer of the new node to -1 (indicating it's the last node)

        if (*list == -1) {
            // If the list is initially empty, make the list point to the new node
            *list = temp;
        } else {
            // Find the last node in the list
            Position lastNode = *list;
            while (vs->data[lastNode].next != -1) {
                lastNode = vs->data[lastNode].next;
            }

            // Update the next pointer of the last node to point to the new node
            vs->data[lastNode].next = temp;
        }
    }
}
