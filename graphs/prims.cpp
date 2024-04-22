#include<bits/stdc++.h>

using namespace std;

int find_min_distance_vertex(vector<bool>visited, vector<int>dist, int n){
    int minn = INT_MAX;
    int idx;
    for(int i=0;i<n ; i++){
        if(visited[i] == false && dist[i] < minn){
            minn = dist[i];
            idx = i;
        }
    }
    return idx;
}

void find_min_spanning_tree(int n,vector<int>&parent, vector<bool>visited, vector<int>dist, vector<vector<int>>v){

    int curr_parent = -1;
    dist[0] = 0;
    parent[0]=-1;
    for(int i=0;i<n-1; i++){
        int idx = find_min_distance_vertex(visited, dist,n);
        visited[idx] = true;
        curr_parent = idx;
        for(int j=0;j<n; j++){
            if(v[idx][j] !=0 && visited[j]==false && v[idx][j] < dist[j]){
                v[idx][j] = dist[j];
                parent[j] = idx;
            }
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>>v(n, vector<int>(n,0));
    for(int i=0;i<n; i++){
        int a,b,w;
        cin>>a>>b>>w;
        v[a][b] = w;
        v[b][a] = w;
    }
    vector<int>parent(n,-1);
    vector<bool>visited(n,false);
    vector<int>dist(n, INT_MAX);
    find_min_spanning_tree(n, parent , visited , dist,v);
    for( int i=0;i<n; i++){
        cout<<i<<" -> "<<parent[i]<<"\n";
    }
}