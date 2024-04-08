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


/*
Taking graph as 2D Adjacency Matrix rather than struct & 0th row, column of graph as empty, as no 0 node, i.e. total n + 1 rows/cols for n node graph

void DFS(int G[][7], int start, int n)
{
    static int visited[7] = {0};

    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;
        for (j = 1; j < n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0)
            {
                DFS(G, j, n);
            }
        }
    }
}

*/

void DFSAllVertices(struct Graph* graph)
{
    int visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; ++i)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < graph->numVertices; ++i)
    {
        if (!visited[i])
        {
            DFS(graph, i, visited);
        }
    }
}