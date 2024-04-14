#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Function to perform Breadth-First Search (BFS) on a graph represented using an adjacency list
void BFS(vector<vector<int>>& adjacencyList, int startNode) {
    int numVertices = adjacencyList.size();
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
        for (int neighbor : adjacencyList[currentNode]) {
            if (!visited[neighbor]) {
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
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    // Perform BFS from the specified start node
    BFS(adjacencyList, startNode);

    return 0;
}
