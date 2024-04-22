#include <bits/stdc++.h>

using namespace std;

void dijkstra(int n, int e, vector<vector<pair<int, int>>>& adj)
{
    vector<bool> visited(n, false);
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

    p.push(make_pair(0, 0)); //weight & vertex
    dist[0] = 0;

    while (!p.empty())
    {
        pair<int, int> pi = p.top();
        p.pop();
        visited[pi.second] = true;

        for (auto ele : adj[pi.second])
        {
            if (!visited[ele.first] && (pi.first + ele.second) < dist[ele.first])
            {
                parent[ele.first] = pi.second;
                dist[ele.first] = (pi.first + ele.second);
                p.push({dist[ele.first], ele.first});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << parent[i] << " with weight -> " << dist[i] << "\n";
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> adj;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    dijkstra(n, e, adj);
}