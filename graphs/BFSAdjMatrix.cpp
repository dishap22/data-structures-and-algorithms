#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform Breadth-First Search (BFS) on a graph represented using an adjacency matrix
void BFS(vector<vector<int>>& adjacencyMatrix, int startNode) {
    int numVertices = adjacencyMatrix.size();
    vector<bool> visited(numVertices, false); // To keep track of visited nodes
    queue<int> queue; // Queue to store nodes to visit

    // Enqueue the start node and mark it as visited
    queue.push(startNode);
    visited[startNode] = true;

    cout << "BFS Traversal starting from node " << startNode << ":" << endl;

    // BFS traversal
    while (!queue.empty()) {
        int currentNode = queue.front();
        queue.pop();
        cout << currentNode << " ";

        // Visit all adjacent nodes of the current node
        for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
            if (adjacencyMatrix[currentNode][neighbor] == 1 && !visited[neighbor]) {
                queue.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    // Initialize the adjacency matrix with 0s
    vector<vector<int>> adjacencyMatrix(numVertices, vector<int>(numVertices, 0));

    cout << "Enter the edges (format: from to):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int from, to;
        cin >> from >> to;
        // Assuming it's an undirected graph
        adjacencyMatrix[from][to] = 1;
        adjacencyMatrix[to][from] = 1; // If it's a directed graph, remove this line
    }

    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    // Perform BFS from the specified start node
    BFS(adjacencyMatrix, startNode);

    return 0;
}
