#include <stdio.h>
#include <stdlib.h>

#define NUM_STACKS 3
#define STACK_SIZE 100

typedef struct {
    int *array;
    int top[NUM_STACKS];
    int base[NUM_STACKS];
    int limit[NUM_STACKS];
} MultiStack;

// Initializes each stack within the MultiStack
void initStacks(MultiStack *s) {
    s->array = (int *)malloc(NUM_STACKS * STACK_SIZE * sizeof(int));
    if (!s->array) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < NUM_STACKS; i++) {
        s->base[i] = i * STACK_SIZE;
        s->limit[i] = s->base[i] + STACK_SIZE;
        s->top[i] = s->base[i] - 1;
    }
}

// Pushes a value onto a specified stack
void push(MultiStack *s, int stackNum, int value) {
    if (s->top[stackNum] + 1 >= s->limit[stackNum]) {
        printf("Stack %d is full\n", stackNum);
        return;
    }
    s->top[stackNum]++;
    s->array[s->top[stackNum]] = value;
}

// Pops a value from a specified stack
int pop(MultiStack *s, int stackNum) {
    if (s->top[stackNum] < s->base[stackNum]) {
        printf("Stack %d is empty\n", stackNum);
        return -1; // Indicating error
    }
    return s->array[s->top[stackNum]--];
}

// Returns the top value of a specified stack without removing it
int peek(MultiStack *s, int stackNum) {
    if (s->top[stackNum] < s->base[stackNum]) {
        printf("Stack %d is empty\n", stackNum);
        return -1; // Indicating error
    }
    return s->array[s->top[stackNum]];
}

int main() {
    MultiStack stacks;
    initStacks(&stacks);

    // Test stack operations
    push(&stacks, 0, 10);
    push(&stacks, 0, 20);
    push(&stacks, 1, 100);
    push(&stacks, 2, 200);

    printf("Popped from Stack 0: %d\n", pop(&stacks, 0));
    printf("Top of Stack 1: %d\n", peek(&stacks, 1));
    printf("Popped from Stack 2: %d\n", pop(&stacks, 2));

    // Free allocated memory
    free(stacks.array);
    return 0;
}