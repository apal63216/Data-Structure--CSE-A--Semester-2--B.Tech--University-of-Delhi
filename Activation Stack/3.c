#include<stdio.h>
#include<stdlib.h>

typedef struct PolyNode{
    int coeff;
    int exp;
    struct PolyNode* next;
} PolyNode;

PolyNode* create_node(int coeff, int exp) {
    PolyNode* new_node = (PolyNode*) malloc(sizeof(PolyNode));
    if (new_node == NULL) {
        printf("Memory allocation Failed.\n");
        exit(1);
    }
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;
    return new_node;
}

PolyNode* insert_term(PolyNode** poly, int coeff, int exp) {
    PolyNode* new_node = create_node(coeff, exp);
    if (*poly == NULL || exp > (*poly)->exp) {
        new_node->next = *poly;
        *poly = new_node;
    }
    else {
        PolyNode* current = *poly;
        while (current->next != NULL && current->next->exp > exp) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    return new_node;
}

PolyNode* add_polynomials(PolyNode* poly_1, PolyNode* poly_2) {
}