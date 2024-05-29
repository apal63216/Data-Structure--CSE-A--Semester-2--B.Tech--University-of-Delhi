#include <stdio.h>
#include <stdlib.h>

// Define a structure for each node of the stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a structure for the stack
typedef struct {
    Node* top;
} Stack;

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(Stack* stack, int item) {
    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    // Set the data of the new node
    newNode->data = item;
    // Set the next pointer of the new node to point to the current top of the stack
    newNode->next = stack->top;
    // Update the top pointer to point to the new node
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
    // Store the data of the top node
    int item = stack->top->data;
    // Move the top pointer to the next node
    Node* temp = stack->top;
    stack->top = stack->top->next;
    // Free the memory of the popped node
    free(temp);
    return item;
}

// Function to get the top element of the stack without popping it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printf("Top element: %d\n", peek(&stack));

    return 0;
}