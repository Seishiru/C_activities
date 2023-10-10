/*cursorbase array implementation where List is a pointer to a structure contaning variable count and a pointer the first element of a dynamically allocated array*/
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the cursor-based list
struct CursorList {
    int count;     // Number of elements in the list
    int* array;    // Pointer to the dynamically allocated array
    int* cursor;   // Cursor to navigate the list
};

// Function to initialize a cursor-based list
struct CursorList* initializeList(int size) {
    struct CursorList* list = (struct CursorList*)malloc(sizeof(struct CursorList));
    if (list == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    list->count = 0;
    list->array = (int*)malloc(size * sizeof(int));
    if (list->array == NULL) {
        perror("Memory allocation failed");
        free(list);
        exit(EXIT_FAILURE);
    }

    list->cursor = list->array; // Initialize the cursor to the beginning of the array

    return list;
}

// Function to add an element to the cursor-based list
void addItem(struct CursorList* list, int data) {
    if (list->count >= sizeof(list->array) / sizeof(int)) {
        printf("List is full. Cannot add more elements.\n");
        return;
    }

    *(list->cursor) = data;
    list->cursor++;
    list->count++;
}

// Function to print the elements of the cursor-based list
void printList(struct CursorList* list) {
    printf("List elements: ");
    for (int i = 0; i < list->count; i++) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}

// Function to free memory used by the cursor-based list
void freeList(struct CursorList* list) {
    free(list->array);
    free(list);
}

int main() {
    struct CursorList* myList = initializeList(10);

    // Add elements to the list
    addItem(myList, 10);
    addItem(myList, 20);
    addItem(myList, 30);

    // Print the list
    printList(myList);

    // Free memory
    freeList(myList);

    return 0;
}


/* List is a structure containing variable count and a pointer the first element of a dynamically allocated array*/

// #include <stdio.h>
// #include <stdlib.h>

// // Define a structure for the cursor-based list
// struct CursorList {
//     int count;     // Number of elements in the list
//     int* array;    // Pointer to the dynamically allocated array
// };

// // Function to initialize a cursor-based list
// void initializeList(struct CursorList* list, int size) {
//     list->count = 0;
//     list->array = (int*)malloc(size * sizeof(int));
//     if (list->array == NULL) {
//         perror("Memory allocation failed");
//         exit(EXIT_FAILURE);
//     }
// }

// // Function to add an element to the cursor-based list
// void addItem(struct CursorList* list, int data) {
//     if (list->count >= sizeof(list->array) / sizeof(int)) {
//         printf("List is full. Cannot add more elements.\n");
//         return;
//     }

//     list->array[list->count] = data;
//     list->count++;
// }

// // Function to print the elements of the cursor-based list
// void printList(const struct CursorList* list) {
//     printf("List elements: ");
//     for (int i = 0; i < list->count; i++) {
//         printf("%d ", list->array[i]);
//     }
//     printf("\n");
// }

// // Function to free memory used by the cursor-based list
// void freeList(struct CursorList* list) {
//     free(list->array);
//     list->count = 0; // Reset count to zero
// }

// int main() {
//     struct CursorList myList;
//     initializeList(&myList, 10);

//     // Add elements to the list
//     addItem(&myList, 10);
//     addItem(&myList, 20);
//     addItem(&myList, 30);

//     // Print the list
//     printList(&myList);

//     // Free memory
//     freeList(&myList);

//     return 0;
// }















/*List is a pointer to a structure containing an array and a variable count*/
// #include <stdio.h>
// #include <stdlib.h>

// // Define a structure for the cursor-based list
// struct CursorList {
//     int* array;    // Pointer to the dynamically allocated array
//     int count;     // Number of elements in the list
// };

// // Function to initialize a cursor-based list
// struct CursorList* initializeList(int size) {
//     struct CursorList* list = (struct CursorList*)malloc(sizeof(struct CursorList));
//     if (list == NULL) {
//         perror("Memory allocation failed");
//         exit(EXIT_FAILURE);
//     }

//     list->array = (int*)malloc(size * sizeof(int));
//     if (list->array == NULL) {
//         perror("Memory allocation failed");
//         free(list);
//         exit(EXIT_FAILURE);
//     }

//     list->count = 0;

//     return list;
// }

// // Function to add an element to the cursor-based list
// void addItem(struct CursorList* list, int data) {
//     if (list->count >= sizeof(list->array) / sizeof(int)) {
//         printf("List is full. Cannot add more elements.\n");
//         return;
//     }

//     list->array[list->count] = data;
//     list->count++;
// }

// // Function to print the elements of the cursor-based list
// void printList(const struct CursorList* list) {
//     printf("List elements: ");
//     for (int i = 0; i < list->count; i++) {
//         printf("%d ", list->array[i]);
//     }
//     printf("\n");
// }

// // Function to free memory used by the cursor-based list
// void freeList(struct CursorList* list) {
//     free(list->array);
//     free(list);
// }

// int main() {
//     struct CursorList* myList = initializeList(10);

//     // Add elements to the list
//     addItem(myList, 10);
//     addItem(myList, 20);
//     addItem(myList, 30);

//     // Print the list
//     printList(myList);

//     // Free memory
//     freeList(myList);

//     return 0;
// }













/*List is a structure containing an array and variable count*/
// #include <stdio.h>
// #include <stdlib.h>

// // Define a structure for the cursor-based list
// struct CursorList {
//     int array[10]; // Array to store elements (adjust size as needed)
//     int count;      // Number of elements in the list
// };

// // Function to initialize a cursor-based list
// void initializeList(struct CursorList* list) {
//     list->count = 0;
// }

// // Function to add an element to the cursor-based list
// void addItem(struct CursorList* list, int data) {
//     if (list->count >= sizeof(list->array) / sizeof(int)) {
//         printf("List is full. Cannot add more elements.\n");
//         return;
//     }

//     list->array[list->count] = data;
//     list->count++;
// }

// // Function to print the elements of the cursor-based list
// void printList(const struct CursorList* list) {
//     printf("List elements: ");
//     for (int i = 0; i < list->count; i++) {
//         printf("%d ", list->array[i]);
//     }
//     printf("\n");
// }

// int main() {
//     struct CursorList myList;
//     initializeList(&myList);

//     // Add elements to the list
//     addItem(&myList, 10);
//     addItem(&myList, 20);
//     addItem(&myList, 30);

//     // Print the list
//     printList(&myList);

//     return 0;
// }
