#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform Depth-First Search (DFS) on a graph represented using an adjacency matrix
void DFS(vector<vector<int>>& adjacencyMatrix, int startNode) {
    int numVertices = adjacencyMatrix.size();
    vector<bool> visited(numVertices, false); // To keep track of visited nodes
    stack<int> stack; // Stack to store nodes to visit

    // Push the start node to the stack and mark it as visited
    stack.push(startNode);
    visited[startNode] = true;

    cout << "DFS Traversal starting from node " << startNode << ":" << endl;

    // DFS traversal
    while (!stack.empty()) {
        int currentNode = stack.top();
        stack.pop();
        cout << currentNode << " ";

        // Visit all adjacent nodes of the current node
        for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
            if (adjacencyMatrix[currentNode][neighbor] == 1 && !visited[neighbor]) {
                stack.push(neighbor);
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
    cout << "Enter the starting node for DFS: ";
    cin >> startNode;

    // Perform DFS from the specified start node
    DFS(adjacencyMatrix, startNode);

    return 0;
}
