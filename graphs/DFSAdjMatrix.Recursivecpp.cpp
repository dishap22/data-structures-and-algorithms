#include <iostream>
#include <vector>

using namespace std;

// Function to perform Depth-First Search (DFS) recursively on a graph represented using an adjacency matrix
void DFSRecursive(vector<vector<int>>& adjacencyMatrix, vector<bool>& visited, int currentNode) {
    // Mark the current node as visited and print it
    visited[currentNode] = true;
    cout << currentNode << " ";

    // Visit all adjacent nodes of the current node
    for (int neighbor = 0; neighbor < adjacencyMatrix.size(); ++neighbor) {
        if (adjacencyMatrix[currentNode][neighbor] == 1 && !visited[neighbor]) {
            // Recursively call DFS for unvisited adjacent nodes
            DFSRecursive(adjacencyMatrix, visited, neighbor);
        }
    }
}

// Function to initialize DFS and call the recursive DFS function
void DFS(vector<vector<int>>& adjacencyMatrix, int startNode) {
    int numVertices = adjacencyMatrix.size();
    vector<bool> visited(numVertices, false); // To keep track of visited nodes

    cout << "DFS Traversal starting from node " << startNode << ":" << endl;

    // Call the recursive DFS function
    DFSRecursive(adjacencyMatrix, visited, startNode);
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
    cout << "Enter the starting node for DFS: ";
    cin >> startNode;

    // Perform DFS from the specified start node
    DFS(adjacencyMatrix, startNode);

    return 0;
}
