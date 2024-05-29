#include <stdio.h>
#include <stdlib.h>

// Node structure to store each term of the polynomial
typedef struct Node {
    int coeff;
    int power;
    struct Node *next;
} Node;

Node* createNode(int coeff, int power) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

void insert(Node **head, int coeff, int power) {
    Node *newNode = createNode(coeff, power);
    if (*head == NULL || (*head)->power < power) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->next != NULL && current->next->power > power) {
            current = current->next;
        }
        if (current->next != NULL && current->next->power == power) {
            current->next->coeff += coeff;
            free(newNode); // Free the unused node
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

Node* addPolynomials(Node *poly1, Node *poly2) {
    Node *result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->power > poly2->power) {
            insert(&result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        } else if (poly1->power < poly2->power) {
            insert(&result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) { // Avoid inserting zero coefficient terms
                insert(&result, sumCoeff, poly1->power);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms from poly1
    while (poly1 != NULL) {
        insert(&result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }

    // Add remaining terms from poly2
    while (poly2 != NULL) {
        insert(&result, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }

    return result;
}

void printPolynomial(Node *head) {
    while (head != NULL) {
        printf("%dx^%d ", head->coeff, head->power);
        if (head->next != NULL)
            printf("+ ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *poly1 = NULL, *poly2 = NULL, *result = NULL;

    // Insert terms into polynomial 1
    insert(&poly1, 3, 2);
    insert(&poly1, 5, 1);
    insert(&poly1, 6, 0);

    // Insert terms into polynomial 2
    insert(&poly2, 1, 1);
    insert(&poly2, 4, 0);

    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);

    // Add polynomials
    result = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial: ");
    printPolynomial(result);

    return 0;
}