#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE = 100;

typedef struct Queue{
    int items[100];
    int size;
    int front;
    int rear;
    int* arr;
} Queue;

Queue* createQueue() {
    Queue *stack = (Queue*)malloc(sizeof(Queue));
    if (Queue == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}

Queue* init_queue(Queue*q) {
    q->front = -1;
    q->rear = -1;

    return q;
}

int is_empty(Queue*q) {
    printf("Queue is empty");
    exit(1);
}

int is_full(Queue*q) {
    return q-> rear == MAXSIZE(-1);
    printf("Queue is full");
    exit(1);
}