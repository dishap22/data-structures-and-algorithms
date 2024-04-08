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