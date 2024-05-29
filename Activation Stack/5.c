#include <stdio.h>
#include <stdlib.h>

#define STACK_COUNT 3
#define STACK_SIZE 4

typedef struct {
    int *arr;
    int *top;
    int *next;
    int free; // to store the index of the first free slot in the array
} MultiStack;

MultiStack* createMultiStack() {
    MultiStack *stack = (MultiStack*)malloc(sizeof(MultiStack));
    if (stack == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    stack->arr = (int*)malloc(sizeof(int) * STACK_SIZE * STACK_COUNT);
    if (stack->arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    stack->top = (int*)malloc(sizeof(int) * STACK_COUNT);
    if (stack->top == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    stack->next = (int*)malloc(sizeof(int) * STACK_SIZE * STACK_COUNT);
    if (stack->next == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    // Initialize all stacks as empty
    for (int i = 0; i < STACK_COUNT; i++)
        stack->top[i] = -1;
    // Initialize all slots as free
    stack->free = 0;
    for (int i = 0; i < STACK_SIZE * STACK_COUNT - 1; i++)
        stack->next[i] = i + 1;
    stack->next[STACK_SIZE * STACK_COUNT - 1] = -1;
    return stack;
}

int isFull(MultiStack *stack) {
    return (stack->free == -1);
}

int isEmpty(MultiStack *stack, int stackNum) {
    return (stack->top[stackNum] == -1);
}

void push(MultiStack *stack, int stackNum, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow.\n");
        return;
    }
    int i = stack->free;
    stack->free = stack->next[i];
    stack->next[i] = stack->top[stackNum];
    stack->top[stackNum] = i;
    stack->arr[i] = value;
}

int pop(MultiStack *stack, int stackNum) {
    if (isEmpty(stack, stackNum)) {
        printf("Stack %d is empty. Cannot pop.\n", stackNum + 1);
        return -1;
    }
    int i = stack->top[stackNum];
    stack->top[stackNum] = stack->next[i];
    stack->next[i] = stack->free;
    stack->free = i;
    return stack->arr[i];
}

void displayStack(MultiStack *stack, int stackNum) {
    if (isEmpty(stack, stackNum)) {
        printf("Stack %d is empty.\n", stackNum + 1);
        return;
    }
    printf("Stack %d: ", stackNum + 1);
    int i = stack->top[stackNum];
    while (i != -1) {
        printf("%d ", stack->arr[i]);
        i = stack->next[i];
    }
    printf("\n");
}

int main() {
    MultiStack *stack = createMultiStack();

    // push to stack1
    push(stack, 0, 1);
    push(stack, 0, 2);
    push(stack, 0, 3);
    push(stack, 0, 4);

    // push to stack2
    push(stack, 1, 5);
    push(stack, 1, 6);
    push(stack, 1, 7);
    push(stack, 1, 8);

    // Print size of each stack
    printf("Size of each stack:\n");
    for (int i = 0; i < STACK_COUNT; i++)
        printf("Stack %d: %d\n", i + 1, stack->top[i] + 1);

    // Print capacity of each stack
    printf("\nCapacity of each stack: %d\n", STACK_SIZE);

    // Display each stack
    printf("\nStacks:\n");
    for (int i = 0; i < STACK_COUNT; i++)
        displayStack(stack, i);

    // pop from stack3
    pop(stack, 2);
    // pop from stack2
    pop(stack, 1);
    // pop from stack1
    pop(stack, 0);

    // Print size of each stack
    printf("\nSize of each stack after popping:\n");
    for (int i = 0; i < STACK_COUNT; i++)
        printf("Stack %d: %d\n", i + 1, stack->top[i] + 1);

    // Display each stack after popping
    printf("\nStacks after popping:\n");
    for (int i = 0; i < STACK_COUNT; i++)
        displayStack(stack, i);

    free(stack->arr);
    free(stack->top);
    free(stack->next);
    free(stack);

    return 0;
}