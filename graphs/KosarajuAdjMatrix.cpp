#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

// Function to perform Depth-First Search (DFS) on a graph represented using an adjacency matrix
void DFS(vector<vector<int>>& adjacencyMatrix, int currentNode, vector<bool>& visited, stack<int>& finishedNodes) {
    visited[currentNode] = true;
    
    // Visit all adjacent nodes of the current node
    for (int neighbor = 0; neighbor < adjacencyMatrix.size(); ++neighbor) {
        if (adjacencyMatrix[currentNode][neighbor] == 1 && !visited[neighbor]) {
            DFS(adjacencyMatrix, neighbor, visited, finishedNodes);
        }
    }
    
    // Push the current node to the stack when all its neighbors have been visited
    finishedNodes.push(currentNode);
}

// Function to perform DFS on the transpose of the graph (reverse of the original graph)
void DFSTranspose(vector<vector<int>>& adjacencyMatrixTranspose, int currentNode, vector<bool>& visited, vector<int>& component) {
    visited[currentNode] = true;
    component.push_back(currentNode);
    
    // Visit all adjacent nodes of the current node in the transpose graph
    for (int neighbor = 0; neighbor < adjacencyMatrixTranspose.size(); ++neighbor) {
        if (adjacencyMatrixTranspose[currentNode][neighbor] == 1 && !visited[neighbor]) {
            DFSTranspose(adjacencyMatrixTranspose, neighbor, visited, component);
        }
    }
}

// Function to find strongly connected components using Kosaraju's Algorithm
vector<vector<int>> findStronglyConnectedComponents(vector<vector<int>>& adjacencyMatrix) {
    int numVertices = adjacencyMatrix.size();
    vector<bool> visited(numVertices, false);
    stack<int> finishedNodes;

    // Perform first DFS to get the order of finishing times of vertices
    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            DFS(adjacencyMatrix, i, visited, finishedNodes);
        }
    }

    // Transpose the graph
    vector<vector<int>> adjacencyMatrixTranspose(numVertices, vector<int>(numVertices));
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            adjacencyMatrixTranspose[i][j] = adjacencyMatrix[j][i];
        }
    }

    // Reset visited array
    fill(visited.begin(), visited.end(), false);

    vector<vector<int>> stronglyConnectedComponents;

    // Perform second DFS on the transpose graph using the finishing times from the stack
    while (!finishedNodes.empty()) {
        int currentNode = finishedNodes.top();
        finishedNodes.pop();

        if (!visited[currentNode]) {
            vector<int> component;
            DFSTranspose(adjacencyMatrixTranspose, currentNode, visited, component);
            stronglyConnectedComponents.push_back(component);
        }
    }

    return stronglyConnectedComponents;
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
        adjacencyMatrix[from][to] = 1; // Assuming it's a directed graph
    }

    // Find strongly connected components using Kosaraju's Algorithm
    vector<vector<int>> stronglyConnectedComponents = findStronglyConnectedComponents(adjacencyMatrix);

    // Output the strongly connected components
    cout << "Strongly Connected Components:" << endl;
    for (const auto& component : stronglyConnectedComponents) {
        for (int vertex : component) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
