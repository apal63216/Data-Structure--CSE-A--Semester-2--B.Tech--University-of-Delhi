#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define URL_SIZE 256

typedef struct Node {
    char url[URL_SIZE];
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

// Function declarations
void push(Stack *s, const char *url);
char* pop(Stack *s);
char* peek(Stack *s);
void initStack(Stack *s);
int isEmpty(Stack *s);
void printHistory(Stack *backStack);

int main() {
    Stack backStack, forwardStack;
    initStack(&backStack);
    initStack(&forwardStack);

    printf("A new browsing session has started.\n");
    printf("NEW SESSION\n");

    char currentURL[URL_SIZE] = "";
    char input[URL_SIZE];
    int stage = 0;

    while (1) {
        printf("Enter URL or Command (BACK, NEXT, PRINT HISTORY): ");
        fgets(input, URL_SIZE, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strcmp(input, "BACK") == 0) {
            if (!isEmpty(&backStack)) {
                push(&forwardStack, currentURL);
                strcpy(currentURL, pop(&backStack));
                printf("Current URL: %s\n", currentURL);
            } else {
                printf("BACK (NO PREVIOUS PAGES)\n");
            }
        } else if (strcmp(input, "NEXT") == 0) {
            if (!isEmpty(&forwardStack)) {
                push(&backStack, currentURL);
                strcpy(currentURL, pop(&forwardStack));
                printf("Current URL: %s\n", currentURL);
            } else {
                printf("NEXT (NO FURTHER PAGES)\n");
            }
        } else if (strcmp(input, "PRINT HISTORY") == 0) {
            printHistory(&backStack);
            printf("Current URL: %s\n", currentURL);
        } else {
            // Assume it's a URL
            if (strlen(currentURL) > 0) {
                push(&backStack, currentURL);
            }
            strcpy(currentURL, input);
            printf("Current URL: %s\n", currentURL);
            // Clear the forward stack because new URL breaks the forward chain
            while (!isEmpty(&forwardStack)) {
                pop(&forwardStack);
            }
        }
    }

    return 0;
}

void initStack(Stack *s) {
    s->top = NULL;
}

void push(Stack *s, const char *url) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Failed to allocate memory.\n");
        return;
    }
    strcpy(newNode->url, url);
    newNode->next = s->top;
    s->top = newNode;
}

char* pop(Stack *s) {
    if (isEmpty(s)) {
        return "";
    }
    Node *topNode = s->top;
    char *url = topNode->url;
    s->top = topNode->next;
    free(topNode);
    return url;
}

char* peek(Stack *s) {
    return s->top ? s->top->url : "";
}

int isEmpty(Stack *s) {
    return s->top == NULL;
}

void printHistory(Stack *backStack) {
    printf("Browsing History:\n");
    for (Node *current = backStack->top; current != NULL; current = current->next) {
        printf("%s\n", current->url);
    }
}
