#include <bits/stdc++.h>

using namespace std;

vector<int> dijkstra(int n, int source, vector<vector<pair<int, int>>>& adj)
{
    vector<bool> visited(n, false);
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

    p.push(make_pair(0, source)); //weight & vertex
    dist[source] = 0;

    while (!p.empty())
    {
        pair<int, int> pi = p.top();
        p.pop();
        int u = pi.second;

        if (visited[u]) continue;
        visited[u] = true;

        for (auto& edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                p.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    int source, destination;
    cin >> source >> destination;

    vector<int> distances = dijkstra(n, source, adj);
    
    if (distances[destination] == INT_MAX)
        cout << "No path exists between the nodes\n";
    else
        cout << "Shortest distance between " << source << " and " << destination << " is " << distances[destination] << "\n";

    return 0;
}
