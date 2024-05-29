#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    int top1, top2, size;
} TwoStacks;

// Function to initialize the two stacks
void initStacks(TwoStacks* ts, int n) {
    ts->size = n;
    ts->arr = (int*) malloc(ts->size * sizeof(int));
    ts->top1 = -1;
    ts->top2 = ts->size;
}

// Function to dynamically resize the array
void resize(TwoStacks* ts) {
    int newSize = ts->size * 2; // Double the size
    ts->arr = (int*) realloc(ts->arr, newSize * sizeof(int));
    if (!ts->arr) {
        printf("Memory error\n");
        return;
    }

    // Move stack 2 elements to the new end of the array
    for (int i = ts->top2; i < ts->size; i++) {
        ts->arr[i + ts->size] = ts->arr[i];
    }

    ts->top2 += ts->size;
    ts->size = newSize;
}

// Function to push an element to stack 1
void push1(TwoStacks* ts, int x) {
    if (ts->top1 + 1 == ts->top2) { // Need to resize
        resize(ts);
    }
    ts->arr[++ts->top1] = x;
}

// Function to push an element to stack 2
void push2(TwoStacks* ts, int x) {
    if (ts->top1 + 1 == ts->top2) { // Need to resize
        resize(ts);
    }
    ts->arr[--ts->top2] = x;
}

// Function to pop an element from stack 1
int pop1(TwoStacks* ts) {
    if (ts->top1 == -1) {
        printf("Stack 1 is Empty\n");
        return -1;
    }
    return ts->arr[ts->top1--];
}

// Function to pop an element from stack 2
int pop2(TwoStacks* ts) {
    if (ts->top2 == ts->size) {
        printf("Stack 2 is Empty\n");
        return -1;
    }
    return ts->arr[ts->top2++];
}

// Function to free stack resources
void freeStacks(TwoStacks* ts) {
    free(ts->arr);
}

int main() {
    TwoStacks ts;
    initStacks(&ts, 10); // Start with an array of size 10
    
    push1(&ts, 1);
    push2(&ts, 10);
    push1(&ts, 2);
    push2(&ts, 9);
    push1(&ts, 3);
    push2(&ts, 8);

    printf("Popped from Stack1: %d\n", pop1(&ts));
    printf("Popped from Stack2: %d\n", pop2(&ts));

    freeStacks(&ts);

    return 0;
}