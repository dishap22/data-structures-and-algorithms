#include "bfs.h"

int main()
{
    int numVertices = 5;
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    int visited[MAX_VERTICES] = {0};

    printf("DFS Traversal: ");
    DFS(graph, 0, visited);

    printf("BFS Traversal: ");
    BFS(graph, 0);
    
    free(graph);
}