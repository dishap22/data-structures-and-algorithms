#include "dfs.h"
#include "queue.h"

void BFS(struct Graph* graph, int vertex)
{
    int numVertices = graph -> numVertices;
    int visited[MAX_VERTICES] = {0};
    queue* q = create_queue(numVertices);

    visited[vertex] = 1;
    enqueue(q, vertex);

    while (!is_empty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++)
        {
            if (graph -> adjacencyMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }

    free(q -> data);
    free(q);
}

/*
Taking graph as 2D Adjacency Matrix rather than struct & 0th row, column of graph as empty, as no 0 node, i.e. total n + 1 rows/cols for n node graph

void BFS(int G[][7], int start, int n)
{
    int i = start, j;
    queue* q = create_queue(n);
    int visited[7] = {0};

    printf("%d ", i);
    visited[i] = 1;
    enqueue(q, i);

    while(!is_empty(q)) {
        i = dequeue(q);
        for (j = i; i < n; j++)
        {
            if (G[i][j] && !visited[j])
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }
}

*/