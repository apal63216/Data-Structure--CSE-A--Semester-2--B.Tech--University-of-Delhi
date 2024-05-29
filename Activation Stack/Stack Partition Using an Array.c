#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 4
#define NUM_STACKS 3

// Structure to represent each stack
typedef struct {
    int top;
    int capacity;
    int* array;
} Stack;

// Function to create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) return NULL;
    stack->capacity = STACK_SIZE;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    if (!stack->array) return NULL;
    return stack;
}

// Function to check if stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto stack
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Cannot pop. Stack is empty.\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to print size of stack
void printSize(Stack* stack) {
    printf("%d ", stack->top + 1);
}

// Function to print capacity of stack
void printCapacity(Stack* stack) {
    printf("%d ", stack->capacity);
}

// Function to display elements of stack
void display(Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int main() {
    // Initialize array of stacks
    Stack* arr[NUM_STACKS];
    for (int i = 0; i < NUM_STACKS; i++) {
        arr[i] = createStack();
    }

    // Print initial size and capacity of each stack
    for (int i = 0; i < NUM_STACKS; i++) {
        printSize(arr[i]);
    }
    printf("\n");
    for (int i = 0; i < NUM_STACKS; i++) {
        printCapacity(arr[i]);
    }
    printf("\n");

    // Push elements onto stack1
    for (int i = 0; i < STACK_SIZE; i++) {
        push(arr[0], i);
    }

    // Print size and capacity after pushing onto stack1
    for (int i = 0; i < NUM_STACKS; i++) {
        printSize(arr[i]);
    }
    printf("\n");
    for (int i = 0; i < NUM_STACKS; i++) {
        printCapacity(arr[i]);
    }
    printf("\n");

    // Push elements onto stack2
    for (int i = 0; i < STACK_SIZE; i++) {
        push(arr[1], i);
    }

    // Print size and capacity after pushing onto stack2
    for (int i = 0; i < NUM_STACKS; i++) {
        printSize(arr[i]);
    }
    printf("\n");
    for (int i = 0; i < NUM_STACKS; i++) {
        printCapacity(arr[i]);
    }
    printf("\n");

    // Pop from stack3
    pop(arr[2]);

    // Pop from stack2
    pop(arr[1]);

    // Pop from stack1
    pop(arr[0]);

    // Print size and capacity after popping from stacks
    for (int i = 0; i < NUM_STACKS; i++) {
        printSize(arr[i]);
    }
    printf("\n");
    for (int i = 0; i < NUM_STACKS; i++) {
        printCapacity(arr[i]);
    }
    printf("\n");

    // Display each stack
    for (int i = 0; i < NUM_STACKS; i++) {
        display(arr[i]);
    }

    // Free allocated memory
    for (int i = 0; i < NUM_STACKS; i++) {
        free(arr[i]->array);
        free(arr[i]);
    }

    return 0;
}


/**



int main(){
    // Initialize arr - parent array that stores multiple stacks
    // Size of arr = 12
    // Capacity of each stack = 4

   // Initialize stack1
   // Initialize stack2

   // Print size of each stack - 0, 0, 0
   // Print capacity of each stack - 4, 4, 4
   // Display each stack

   // push to stack1
   // push to stack1
   // push to stack1
   // push to stack1

   // Print size of each stack - 4, 0, 0
   // Print capacity of each stack - 4, 4, 4
   // Display each stack

   // push to stack2
   // push to stack2
   // push to stack2
   // push to stack2

   // Print size of each stack - 4, 4, 0
   // Print capacity of each stack - 4, 4, 4
   // Display each stack

   // pop from stack3 -- "Cannot pop. Stack is empty."
   // pop from stack2
   // pop from stack1

   // Print size of each stack - 3, 3, 0
   // Print capacity of each stack - 4, 4, 4
   // Display each stack

}
*/