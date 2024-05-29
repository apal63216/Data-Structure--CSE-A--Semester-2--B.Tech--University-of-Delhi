#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Define the maximum size of the array

typedef struct {
    int arr[MAX_SIZE];
    int top1;
    int top2;
} TwoStacks;

// Initialize the two stacks
void initTwoStacks(TwoStacks *ts) {
    ts->top1 = -1;
    ts->top2 = MAX_SIZE;
}

// Check if the first stack is empty
int isEmpty1(TwoStacks *ts) {
    return ts->top1 == -1;
}

// Check if the second stack is empty
int isEmpty2(TwoStacks *ts) {
    return ts->top2 == MAX_SIZE;
}

// Check if either stack is full
int isFull(TwoStacks *ts) {
    return ts->top1 + 1 == ts->top2;
}

// Push an element to the first stack
void push1(TwoStacks *ts, int data) {
    if (!isFull(ts)) {  // Check for available space
        ts->top1++;
        ts->arr[ts->top1] = data;
    } else {
        printf("Stack Overflow in Stack 1\n");
        exit(EXIT_FAILURE);
    }
}

// Push an element to the second stack
void push2(TwoStacks *ts, int data) {
    if (!isFull(ts)) {  // Check for available space
        ts->top2--;
        ts->arr[ts->top2] = data;
    } else {
        printf("Stack Overflow in Stack 2\n");
        exit(EXIT_FAILURE);
    }
}

// Pop an element from the first stack
int pop1(TwoStacks *ts) {
    if (!isEmpty1(ts)) {
        int data = ts->arr[ts->top1];
        ts->top1--;
        return data;
    } else {
        printf("Stack Underflow in Stack 1\n");
        exit(EXIT_FAILURE);
    }
}

// Pop an element from the second stack
int pop2(TwoStacks *ts) {
    if (!isEmpty2(ts)) {
        int data = ts->arr[ts->top2];
        ts->top2++;
        return data;
    } else {
        printf("Stack Underflow in Stack 2\n");
        exit(EXIT_FAILURE);
    }
}

// Main function to test stack operations
int main() {
    TwoStacks ts;
    initTwoStacks(&ts);
    
    push1(&ts, 10);
    push2(&ts, 100);
    push1(&ts, 20);
    push2(&ts, 200);
    
    printf("Popped from stack1: %d\n", pop1(&ts));
    printf("Popped from stack2: %d\n", pop2(&ts));
    
    return 0;
}