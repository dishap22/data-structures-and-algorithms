#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

// Function to perform Depth-First Search (DFS) on a graph represented using an adjacency list
void DFS(vector<vector<int>>& adjacencyList, int startNode) {
    int numVertices = adjacencyList.size();
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
        for (int neighbor : adjacencyList[currentNode]) {
            if (!visited[neighbor]) {
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

    vector<vector<int>> adjacencyList(numVertices);

    cout << "Enter the edges (format: from to):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int from, to;
        cin >> from >> to;
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from); // For undirected graph
    }

    int startNode;
    cout << "Enter the starting node for DFS: ";
    cin >> startNode;

    // Perform DFS from the specified start node
    DFS(adjacencyList, startNode);

    return 0;
}
