int traverse_bfs_interactive(GraphList* graph, int start_vertex) {
    int curr_vertex;
    int visited[graph->num_vertices];

    for (int i = 0; i < graph->num_vertices; i++) {
        visited[i] = 0;
    }

    Queue queue;
    initialize_queue(&square);

    visited[start_vertex] = 1;
    enqueue(&square, start_vertex);

    while (!is_empty(&queue)) {
        curr_vertex = dequeue(&queue);
        printf("Visited %d\n", curr_vertex);
    }
}