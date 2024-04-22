#include <bits/stdc++.h>

using namespace std;

int find_min_vertex(vector<bool>visited, vector<int>dist, int n){
    int minn = INT_MAX;
    int min_idx;
    for(int i=0; i<n; i++){
        if(visited[i] == false && dist[i] < minn){
            minn = dist[i];
            min_idx = i;
        }
    }
    return min_idx;
}

void dijkstra_algo(int n, int e, vector<vector<pair<int,int>>>v){
    vector<bool>visited(n,false);
    vector<int>dist(n, INT_MAX);
    vector<int>parent(n, -1);

    dist[0] = 0;

    for(int i=0;i<n-1 ; i++){
        int idx = find_min_vertex(visited, dist, n);
        visited[idx] = true;
        for(auto ele: v[idx]){
            if(visited[ele.first] == false && (ele.second + dist[idx]) < dist[ele.first])
            {
                parent[ele.first] = idx;
                dist[ele.first] = ele.second + dist[idx];
            }
        }
    }
    for(int i=0;i<n; i++){
        cout<<i<<" -> "<<parent[i]<<" with weight -> "<<dist[i]<<"\n";
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<pair<int,int>>>v(e);
    for(int i=0;i<e; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    dijkstra_algo(n,e,v);
}