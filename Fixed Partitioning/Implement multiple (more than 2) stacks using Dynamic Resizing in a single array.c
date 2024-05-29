#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int totalSize;
    int numStacks;
    int *stackSize;
    int *stackCapacity;
    int *start;
} MultiStack;

// Function prototypes
void initMultiStack(MultiStack *ms, int numStacks, int initialSize);
void push(MultiStack *ms, int stackNum, int value);
int pop(MultiStack *ms, int stackNum);
void expand(MultiStack *ms);
void freeMultiStack(MultiStack *ms);

void initMultiStack(MultiStack *ms, int numStacks, int initialSize) {
    ms->numStacks = numStacks;
    ms->totalSize = numStacks * initialSize;
    ms->array = (int *)malloc(ms->totalSize * sizeof(int));
    ms->stackSize = (int *)calloc(numStacks, sizeof(int));
    ms->stackCapacity = (int *)malloc(numStacks * sizeof(int));
    ms->start = (int *)malloc(numStacks * sizeof(int));

    for (int i = 0; i < numStacks; i++) {
        ms->stackCapacity[i] = initialSize;
        ms->start[i] = i * initialSize;
    }
}

void push(MultiStack *ms, int stackNum, int value) {
    if (stackNum < 0 || stackNum >= ms->numStacks) {
        return; // Invalid stack number
    }

    // Check if the stack is full
    if (ms->stackSize[stackNum] >= ms->stackCapacity[stackNum]) {
        expand(ms);
    }

    int index = ms->start[stackNum] + ms->stackSize[stackNum];
    ms->array[index] = value;
    ms->stackSize[stackNum]++;
}

int pop(MultiStack *ms, int stackNum) {
    if (stackNum < 0 || stackNum >= ms->numStacks || ms->stackSize[stackNum] == 0) {
        return -1; // Invalid operation
    }

    int index = ms->start[stackNum] + ms->stackSize[stackNum] - 1;
    int value = ms->array[index];
    ms->stackSize[stackNum]--;
    return value;
}

void expand(MultiStack *ms) {
    int newSize = ms->totalSize * 2;
    int *newArray = (int *)malloc(newSize * sizeof(int));

    int newCapacity = newSize / ms->numStacks;
    int currentIndex = 0;
    for (int i = 0; i < ms->numStacks; i++) {
        ms->start[i] = currentIndex;
        for (int j = 0; j < ms->stackSize[i]; j++) {
            newArray[currentIndex + j] = ms->array[ms->start[i] + j];
        }
        ms->stackCapacity[i] = newCapacity;
        currentIndex += newCapacity;
    }

    free(ms->array);
    ms->array = newArray;
    ms->totalSize = newSize;
}

void freeMultiStack(MultiStack *ms) {
    free(ms->array);
    free(ms->stackSize);
    free(ms->stackCapacity);
    free(ms->start);
}

int main() {
    MultiStack ms;
    initMultiStack(&ms, 3, 5); // 3 stacks, each with an initial capacity of 5

    push(&ms, 0, 10);
    push(&ms, 0, 20);
    push(&ms, 1, 30);
    push(&ms, 1, 40);
    push(&ms, 1, 50);
    push(&ms, 1, 60); // Should trigger a resize

    printf("Pop stack 0: %d\n", pop(&ms, 0));
    printf("Pop stack 1: %d\n", pop(&ms, 1));

    freeMultiStack(&ms);
    return 0;
}