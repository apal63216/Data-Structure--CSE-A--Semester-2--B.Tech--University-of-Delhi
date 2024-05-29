int dfs_interative(GraphList* graph, int start_vertex) {
    int curr_vertex;
    int visited[graph->vertices];

    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = 0;
    }

    Stack* stack = crete_stack();
    push(stack, start_vertex);

    while (!is_empty(stack)) {
        curr_vertex = pop(stack);
        if (!visited[curr_vertex]) {
            visited[curr_vertex] = 1;
            printf("Visited %d \n", curr_vertex);
        }
    }
}