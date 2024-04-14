#include <iostream>
#include <vector>

using namespace std;

// Function to create an adjacency list
vector<vector<int>> createAdjacencyList(int numVertices, vector<vector<int>>& edges) {
    // Initialize the adjacency list with an empty vector for each vertex
    vector<vector<int>> adjacencyList(numVertices);

    // Populate the adjacency list based on the edges
    for (const auto& edge : edges) {
        int from = edge[0];
        int to = edge[1];
        // Assuming it's an undirected graph
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from); // If it's a directed graph, remove this line
    }

    return adjacencyList;
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

    vector<vector<int>> adjacencyList = createAdjacencyList(numVertices, edges);

    // Output the adjacency list
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        cout << i << ": ";
        for (int neighbor : adjacencyList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
