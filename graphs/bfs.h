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