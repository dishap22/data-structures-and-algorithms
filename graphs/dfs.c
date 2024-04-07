#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph -> numVertices = vertices;

    for (int i = 0; i < vertices; ++i)
    {
        for (int j = 0; j < vertices; ++j)
        {
            graph -> adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    graph -> adjacencyMatrix[src][dest] = 1;
    graph -> adjacencyMatrix[dest][src] = 1;
}

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

    free(graph);
}