#include <stdio.h>
#define MAX 10

typedef struct {
    char elem;  
    int next_index;
} Data;

typedef struct {
    Data array[MAX];
    int front;
    int rear;
} CircularQueue;

void initialize(CircularQueue *Q);
void display(CircularQueue Q);
void enqueue(CircularQueue *Q, char insert);  
char peek(CircularQueue Q);
char dequeue(CircularQueue *Q);

int main() {
    CircularQueue Q;
    initialize(&Q);
    display(Q);
    enqueue(&Q, 'A');
    display(Q);

    dequeue(&Q);
    display(Q);

    enqueue(&Q, 'B');
    display(Q);

    dequeue(&Q);
    display(Q);

    enqueue(&Q, 'C');
    display(Q);

    dequeue(&Q);
    display(Q);

    enqueue(&Q, 'D');
    display(Q);

    enqueue(&Q, 'E');
    display(Q);

    dequeue(&Q);
    display(Q);

    enqueue(&Q, 'F');
    display(Q);

    enqueue(&Q, 'G');
    display(Q);

    dequeue(&Q);
    display(Q);

    enqueue(&Q, 'H');
    display(Q);

    enqueue(&Q, 'I');
    display(Q);

    dequeue(&Q);
    display(Q);

    enqueue(&Q, 'J');
    display(Q);

    dequeue(&Q);
    display(Q);

    dequeue(&Q);
    display(Q);

    dequeue(&Q);
    display(Q);

    enqueue(&Q, 'C');
    display(Q);
    
    return 0;
}

void initialize(CircularQueue *Q) {
    int x;
    for (x = 0; x < MAX; x++) {
        Q->array[x].next_index = (x + 1) % MAX;
        Q->array[x].elem = '\0';  
    }
    Q->front = -1;
    Q->rear = -1;
}

void display(CircularQueue Q) {
    printf("\n%5s\t|\t%7s\t|\t%10s\n", "INDEX", "ELEMENT", "NEXT_INDEX");
    for (int x = 0; x < MAX; x++) {
        printf("%5d\t|\t%7c\t|\t%10d\n", x, Q.array[x].elem, Q.array[x].next_index);  
    }
    printf("FRONT: %d\t", Q.front);
    printf("REAR: %d\t\t\n", Q.rear);
}

void enqueue(CircularQueue *Q, char insert) {  
    if ((Q->rear + 1) % MAX == Q->front) {
        puts("[ Queue is full ]");
    } else {
        if (Q->front == -1) {
            Q->front = 0;
        }
        Q->rear = (Q->rear + 1) % MAX;
        Q->array[Q->rear].elem = insert;  
    }
}

char peek(CircularQueue Q) {
    if (Q.front == -1) {
        puts("[ Queue is empty ]");
        return '\0';
    }
    return Q.array[Q.front].elem;
}

char dequeue(CircularQueue *Q) {
    if (Q->front == -1) {
        puts("[ Nothing to dequeue ]");
        return '\0';
    }

    char removed_elem = peek(*Q);
    Q->array[Q->front].elem = '\0';

    if (Q->front == Q->rear) {
        // Queue is now empty
        Q->front = -1;
        Q->rear = -1;
    } else {
        Q->front = (Q->front + 1) % MAX;
    }

    return removed_elem;
}
