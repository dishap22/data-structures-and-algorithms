#include <stdlib.h>
#include <stdbool.h>

bool DFS(int** adjacency, int n, int source, int destination, bool* visited) {
    if (source == destination)
        return true;

    visited[source] = true;

    for (int i = 0; i < n; ++i) {
        if (adjacency[source][i] && !visited[i] && DFS(adjacency, n, i, destination, visited))
            return true;
    }

    return false;
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    int** adjacency = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; ++i) {
        adjacency[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; ++j)
            adjacency[i][j] = 0;
    }

    for (int i = 0; i < edgesSize; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjacency[u][v] = 1; 
        adjacency[v][u] = 1;
    }

    bool visited[n];
    for (int i = 0; i < n; ++i)
        visited[i] = false;

    return DFS(adjacency, n, source, destination, visited);
}