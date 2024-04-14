#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Function to perform Depth-First Search (DFS) recursively on a graph represented using an adjacency list
void DFSRecursive(vector<vector<int>>& adjacencyList, vector<bool>& visited, int currentNode) {
    // Mark the current node as visited and print it
    visited[currentNode] = true;
    cout << currentNode << " ";

    // Visit all adjacent nodes of the current node
    for (int neighbor : adjacencyList[currentNode]) {
        if (!visited[neighbor]) {
            // Recursively call DFS for unvisited adjacent nodes
            DFSRecursive(adjacencyList, visited, neighbor);
        }
    }
}

// Function to initialize DFS and call the recursive DFS function
void DFS(vector<vector<int>>& adjacencyList, int startNode) {
    int numVertices = adjacencyList.size();
    vector<bool> visited(numVertices, false); // To keep track of visited nodes

    cout << "DFS Traversal starting from node " << startNode << ":" << endl;

    // Call the recursive DFS function
    DFSRecursive(adjacencyList, visited, startNode);
    cout << endl;
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    // Initialize the adjacency list
    vector<vector<int>> adjacencyList(numVertices);

    cout << "Enter the edges (format: from to):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int from, to;
        cin >> from >> to;
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from); // If it's an undirected graph
    }

    int startNode;
    cout << "Enter the starting node for DFS: ";
    cin >> startNode;

    // Perform DFS from the specified start node
    DFS(adjacencyList, startNode);

    return 0;
}
