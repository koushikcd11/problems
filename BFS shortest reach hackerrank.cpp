#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<vector<int>> adj(n+1);
    for(vector<int> &edge:edges){
        int u=edge[0];
        int v=edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dis(n+1,-1);
    queue<int> q;
    q.push(s);
    dis[s]=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int neigh: adj[curr]){
            if(dis[neigh]==-1){
                dis[neigh]=dis[curr]+6;
                q.push(neigh);
            }
        }
    }
    vector<int> res;
    for(int i=1;i<=n;i++){
        if(s!=i)res.push_back(dis[i]);
    }
    return res;
}