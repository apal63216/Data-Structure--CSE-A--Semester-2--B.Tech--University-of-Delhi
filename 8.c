#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num_vertices;
    int **adj_matrix;
} GraphMatrix;

GraphMatrix* create_graph_matrix(int vertices) {
    GraphMatrix* graph = malloc(sizeof(GraphMatrix));
    graph->num_vertices = vertices;
    graph->adj_matrix = malloc(sizeof(int*) * vertices);

    for (int i = 0; i < vertices; i++) {
        graph->adj_matrix[i] = malloc(sizeof(int) * vertices);
        for (int j = 0; j < vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
    return graph;
}

void add_edge(GraphMatrix* g, int src, int dest) {
    if (src < g->num_vertices && dest < g->num_vertices) {
        g->adj_matrix[src][dest] = 1;
        g->adj_matrix[dest][src] = 1;
    }
}

void print_graph(GraphMatrix* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            printf("(%d,%d): %d ", i, j, g->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

void free_graph(GraphMatrix* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        free(g->adj_matrix[i]);
    }
    free(g->adj_matrix);
    free(g);
}

int main() {
    GraphMatrix* graph = create_graph_matrix(4);
    
    add_edge(graph, 0, 1);
    add_edge(graph, 2, 3);
    
    print_graph(graph);

    free_graph(graph);
    
    return 0;
}