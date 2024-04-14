#include <iostream>
#include <vector>

using namespace std;

// Function to create an adjacency matrix
vector<vector<int>> createAdjacencyMatrix(int numVertices, vector<vector<int>>& edges) {
    // Initialize the adjacency matrix with 0s
    vector<vector<int>> adjacencyMatrix(numVertices, vector<int>(numVertices, 0));

    // Populate the adjacency matrix based on the edges
    for (const auto& edge : edges) {
        int from = edge[0];
        int to = edge[1];
        // Assuming it's an undirected graph
        adjacencyMatrix[from][to] = 1;
        adjacencyMatrix[to][from] = 1; // If it's a directed graph, remove this line
    }

    return adjacencyMatrix;
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    vector<vector<int>> edges(numEdges, vector<int>(2));
    cout << "Enter the edges (format: from to):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> adjacencyMatrix = createAdjacencyMatrix(numVertices, edges);

    // Output the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (const auto& row : adjacencyMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
