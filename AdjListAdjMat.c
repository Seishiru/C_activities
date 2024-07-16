#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 6
#define SENTINEL __INT_MAX__
//head -> tail directed
typedef char vertex;

//for populating
typedef struct {
    vertex head;
    vertex tail;
    int weight;
}edge;

// structure definition

//List
typedef struct {
    char vertex;
    int weight;
}adjNode;

typedef struct node{
    adjNode info;
    struct node *next;  
}*adjType;

typedef struct AdjList{
    adjType List[MAX_VERTEX];
    int edgeCount;
    int capacity; //Initial value 6, resize when adding new vertex
}AdjList;

//Matrix
typedef struct {
    int matrix[MAX_VERTEX][MAX_VERTEX];
    int edgeCount;
    int capacity;
}AdjMatrix;

void initializeAdjMatrix(AdjMatrix *am) {
    int x, y;
    for(x = 0; x < MAX_VERTEX; x++) {
        for(y = 0; y < MAX_VERTEX; y++)
        am->matrix[x][y] = SENTINEL;
    }
    am->edgeCount = 0;
    am->capacity = MAX_VERTEX;
}

void initializeAdjList(AdjList *al) {
    int x;
    for(x = 0; x < MAX_VERTEX; x++) {
        al->List[x] = NULL;
        al->edgeCount = 0;
        al->capacity = MAX_VERTEX;
    }
}

void displaydjList(AdjList al) {
    int x;
	adjType temp;
		
	printf("\n\nTHE ADJACENCY LIST ::");
	printf("\n%-8s", "VERTEX");
	printf("%-20s", "ADJACENT VERTICES");
	printf("\n%-8s", "------");
	printf("%-19s", "-----------------");
 
	//Write your code here 
	for (x = 0; x < al.capacity; ++x) {											//at head
		printf("\n  %c :: ", 'A' + x);
		if (al.List[x] == NULL) {
			printf(" NULL");
		} else {
			for (temp = al.List[x]; temp != NULL; temp = temp->next) {			//printf elements
				printf(" %c (%d)\t", temp->info.vertex, temp->info.weight);
			}
		}
	}
	printf("\n\nNumber of arcs: %d", al.edgeCount);
    printf("\nNumber of vertex: %d\n\n", al.capacity);

}

void displayadjMatrix(AdjMatrix am) {
    int row, colm;
    for(colm = 0; colm < am.capacity; colm++) {
        printf("%6c", colm + 'A');
    }
    for(row = 0; row < am.capacity; row++) {
        printf("\n%-5c", 'A' + row);
        for(colm = 0; colm < am.capacity; colm++) {
            (am.matrix[row][colm] != SENTINEL) ? printf("%-6d", am.matrix[row][colm]):printf("%-6c", '_');
        }
    }
    printf("\n\nNumber of arcs: %d", am.edgeCount);
    printf("\nNumber of vertex: %d\n\n", am.capacity);
}
/*Undirected adjacency list*/
AdjList populateadjList() {
    edge data[] = {{'A', 'B', 3}, {'A', 'D', 7}, {'A', 'E', 4},
                   {'B', 'C', 9}, {'B', 'D', 8},
                   {'C', 'D', 1},
                   {'D', 'E', 2}, {'D', 'F', 5}};
    
    // Apply the insert
    AdjList al;
    initializeAdjList(&al);
    int index, x, y;
    adjType temp;
    for(x = 0; x < sizeof(data) / sizeof(data[0]); x++) {
        for(y = 0; y < 2; y++) {
            index = (y == 0)? data[x].head - 'A' : data[x].tail - 'A';
            temp = malloc(sizeof(struct node));
            if(temp != NULL) {
                temp->info.vertex = (y == 0)? data[x].tail: data[x].head;
                temp->info.weight = data[x].weight;
                temp->next = al.List[index];
                al.List[index] = temp;
            }
        }
    }
    return al;
}
int main() {
    AdjList al;
    AdjMatrix am;

    // initializeAdjList(&al);
    initializeAdjMatrix(&am);

    al = populateadjList();

    displaydjList(al);
    displayadjMatrix(am);
}