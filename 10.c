#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct create_vertex {
    int vertex;
    struct Visited;
} Visited;

typedef struct{
    int num_vertices;
    Visited arr;
} Visited;

Visited* create_vertx(int vertices) {
    Visited* visit = malloc(sizeof(Visited));
    if (visit == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(EXIT_FAILURE);
    }
}