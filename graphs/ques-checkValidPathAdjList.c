#include <stdlib.h>
#include <stdbool.h>

typedef struct edge {
    int dst;
    struct edge *next;
} EDGE;

bool dfs(int n, EDGE** graph, bool* visited, int curr, int src, int dst)
{
    EDGE *p_edge;
    if (curr == dst) return true;

    p_edge = graph[curr];
    while (p_edge) {
        if (visited[p_edge -> dst] == false) {
            visited[p_edge -> dst] = true;

            if (dfs(n, graph, visited, p_edge -> dst, src, dst) == true) {
                return true;
            }
        }

        p_edge = p_edge -> next;
    }
    return false;
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination){
    EDGE *p_edge, *p_del;
    EDGE **graph = (EDGE **)calloc(1, sizeof(EDGE *) * n);
    bool *visited = (bool *)calloc(1, sizeof(bool) * n);
    bool result;

    for (int i = 0; i < edgesSize; i++) {
        p_edge = (EDGE *)malloc(sizeof(EDGE));
        p_edge->dst = edges[i][1];
        p_edge->next = graph[edges[i][0]];
        graph[edges[i][0]] = p_edge;
        
        p_edge = (EDGE *)malloc(sizeof(EDGE));
        p_edge->dst = edges[i][0];
        p_edge->next = graph[edges[i][1]];
        graph[edges[i][1]] = p_edge;
    }

    result = dfs(n, graph, visited, source, source, destination);

    for (int i = 0; i < n; i++) {
        p_edge = graph[i];
        
        while (p_edge) {
            p_del = p_edge;
            p_edge = p_edge->next;
            free(p_del);
        }
    }

    free(graph);
    free(visited);

    return result;
}