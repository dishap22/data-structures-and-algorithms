#include "graph.h"

void DFS(struct Graph* graph, int vertex, int visited[])
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph -> numVertices; ++i)
    {
        if (graph -> adjacencyMatrix[vertex][i] && !visited[i])
        {
            DFS(graph, i, visited);
        }
    }
}