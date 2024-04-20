#include <bits/stdc++.h>

using namespace std;

int helper(int curr, vector<vector<int>>&adj, int &maxx, vector<bool>&vis)
{
    vis[curr] = true;
    int temp_maxx = 0;
    
    vector<int> temp_height;
    for(auto ele : adj[curr])
    {
        if(vis[ele]  == false)
        {
            int h = helper(ele,adj, maxx,vis);
            temp_height.push_back(h);
        }
    }
    
    sort(temp_height.begin(), temp_height.end() );
    int s = temp_height.size();
    if(s==0)
    {
        maxx = max(maxx , 1);
        return 1;
    }
    if(s==1)
    {
        maxx = max(maxx , temp_height[0]+1);
    }
    else
    {
        maxx = max( maxx , temp_height[s-1]+temp_height[s-2]+1);
    }
    return temp_height[s-1]+1;
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> adj(n);
    
    for(int i=1;i<n;i++)
    {
        adj[A[i]].push_back(i);
        adj[i].push_back(A[i]);
    }
    int maxx = 0;
    vector<bool>vis(n,false);
    helper(1,adj,maxx,vis);
    return maxx-1;
}
