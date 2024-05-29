#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

Stack* create_stack(); // or init_stack()
int is_empty(Stack* stack);
int is_full(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);
int get_size(Stack*);
void destroy_stack(Stack*stack);

int main() {
    Stack* stack = create_stack();
    push(stack, 10);
    push(stack, 20);
    printf("Top element is: %d\n", peek(stack));
    printf("Stack size is: %d\n", get_size(stack));
    pop(stack);
    destroy_stack(stack);
    return 0;
}

Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;

    return stack;
}

int is_empty(Stack* stack){
    return stack->top == -1;
}

int is_full(Stack* stack) {
    return stack->top == MAX_SIZE -1;
}

void push(Stack* stack, int item) {
    if (is_full(stack)) {
        printf("Stack is full. Cannot push %d.\n", item);
        return;
    }
    stack->items[++stack->top] = item;
}

int pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }

    return stack->items[stack->top--];
}

int peek(Stack* stack) {

    if (is_empty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }

    return stack->items[stack->top];
}

int get_size(Stack* stack) {
    return stack->top +1;
}

void destroy_stack(Stack* stack) {
    free(stack);
}