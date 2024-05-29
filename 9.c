#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int vertex;
    struct Node* next;
}Node;

typedef struct{
    int num_vertices;
    Node** adj_lists;
}GraphList;

GraphList* create_graph_list(int vertices){
    GraphList* graph = malloc(sizeof(GraphList));
    if(graph == NULL){
        printf("Error allocating memory");
        return NULL;
    }
    graph->num_vertices = vertices;
    graph->adj_lists = malloc(sizeof(Node*) * vertices);
    for(int i = 0; i < vertices; i++){
        graph->adj_lists[i] = NULL;
    }
    return graph;
}

int add_graph_list(GraphList* graph, int src, int dest){
    Node* new_node = malloc(sizeof(Node));
    new_node->vertex = dest;
    new_node->next = graph->adj_lists[src];
    graph->adj_lists[src] = new_node;

    new_node = malloc(sizeof(Node));
    new_node->vertex = src;
    new_node->next = graph->adj_lists[dest];
    graph->adj_lists[dest] = new_node;
    return 0;
}

int print_graph_list(GraphList* graph){
    for(int i = 0; i < graph->num_vertices; i++){
        Node* temp = graph->adj_lists[i];
        printf("\n Adjacency list of vertex %d\n head", i);
        while(temp){
            printf("-> %d", temp->vertex);
            temp = temp->next;
        }
    }
}

int main(){
    GraphList* graph;
    graph = create_graph_list(6);
    add_graph_list(graph,1,2);
    add_graph_list(graph,2,3);
    add_graph_list(graph,2,5);
    print_graph_list(graph);
    return 0;
}