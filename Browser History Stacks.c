#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 256
#define STACK_SIZE 100

typedef struct {
    char* items[STACK_SIZE];
    int top;
} Stack;

void initializeStack(Stack* s) {
    s->top = -1;
}

int isFull(Stack* s) {
    return s->top == STACK_SIZE - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int push(Stack* s, const char* url) {
    if (isFull(s)) {
        return 0;
    }
    s->items[++s->top] = strdup(url);
    return 1;
}

char* pop(Stack* s) {
    if (isEmpty(s)) {
        return NULL;
    }
    char* url = s->items[s->top];
    s->items[s->top--] = NULL;
    return url;
}

char* peek(Stack* s) {
    if (isEmpty(s)) {
        return NULL;
    }
    return s->items[s->top];
}

int main() {
    Stack backStack;
    Stack forwardStack;
    initializeStack(&backStack);
    initializeStack(&forwardStack);

    char currentUrl[MAX_URL_LENGTH] = "";

    printf("A new browsing session has started.\nNEW SESSION\n");

    char command[MAX_URL_LENGTH];
    while (1) {
        printf("Enter URL, BACK, NEXT, or PRINT HISTORY: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;  // Remove newline

        if (strncmp(command, "https://", 8) == 0) {
            if (strlen(currentUrl) > 0) {
                push(&backStack, currentUrl);
            }
            strncpy(currentUrl, command, MAX_URL_LENGTH);
            while (!isEmpty(&forwardStack)) {  // Clear forward history on new navigation
                free(pop(&forwardStack));
            }
            printf("Current URL: %s\n", currentUrl);
        } else if (strcmp(command, "BACK") == 0) {
            if (!isEmpty(&backStack)) {
                push(&forwardStack, currentUrl);
                strcpy(currentUrl, pop(&backStack));
                printf("Current URL: %s\n", currentUrl);
            } else {
                printf("BACK (NO PREVIOUS PAGES)\n");
            }
        } else if (strcmp(command, "NEXT") == 0) {
            if (!isEmpty(&forwardStack)) {
                push(&backStack, currentUrl);
                strcpy(currentUrl, pop(&forwardStack));
                printf("Current URL: %s\n", currentUrl);
            } else {
                printf("NEXT (NO FURTHER PAGES)\n");
            }
        } else if (strcmp(command, "PRINT HISTORY") == 0) {
            printf("Browser History:\n");
            for (int i = backStack.top; i >= 0; i--) {
                printf("%s <- ", backStack.items[i]);
            }
            printf("CURRENT: %s", currentUrl);
            for (int i = 0; i <= forwardStack.top; i++) {
                printf(" -> %s", forwardStack.items[i]);
            }
            printf("\n");
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}