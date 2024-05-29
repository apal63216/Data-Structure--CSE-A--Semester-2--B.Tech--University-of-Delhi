#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100
typedef struct 
{
    int items[MAX_SIZE];
    int top;
} Stack;

Stack* create_stack();
int is_empty(Stack* stack);
int is_full(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);
int get_size(Stack* stack);
void destroy(Stack* stack);
Stack* create_stack(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;//check stack is none
    return stack;
}
int is_empty(Stack* stack){
    return stack->top==-1;
}
int is_full(Stack* stack){
    return stack->top == MAX_SIZE - 1;
}
void push(Stack* stack, int item){
    if(is_full(stack)){
        printf("stack full");
        return;
    }
    stack-> items[++stack->top]=item;
}
int pop(Stack* stack){
    if(is_empty(stack)){
        printf("Is empty");
        return -2;
    }
    return stack->items[stack->top--];
}
int peek(Stack* stack){
    if(is_empty(stack)){
        printf("Is empty");
        return -2;
    }
    return stack->items[stack->top];
}
int get_size(Stack* stack){
    return stack-> top +1;
}
void destroy(Stack* stack){
    free(stack);
}
int main(){



    return 0;
}//stack code array