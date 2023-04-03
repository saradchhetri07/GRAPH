#https://www.codingninjas.com/codestudio/problems/bridges-in-graph_893026?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<unordered_map>
#include<list>
#include<vector>
void dfs(unordered_map<int,list<int>> &adj,vector<int> &disc,vector<int> &low,int &parent,unordered_map<int,bool> &visited,int &timer,int node,vector<vector<int>> &result){
    visited[node] = true;
    disc[node] = low[node] = timer++;

    for(auto neighbour:adj[node]){
        if(neighbour == parent){
            continue;
        }else if(!visited[neighbour]){
            dfs(adj,disc,low,node,visited,timer,neighbour,result);
            low[node]= min(low[node],low[neighbour]);
            //check for bridge
            if(low[neighbour]>disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);

                result.push_back(ans);
            }

        }else{
            //back edge
            low[node] = min(low[node],disc[neighbour]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> result;
    vector<int> disc(v);
    vector<int> low(v);
    
    int timer =0;
    int parent = -1;
    unordered_map<int,bool> visited;
    for(int i=0;i<v;i++){
        disc[i]=-1;
        low[i]=-1;
    }
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(adj,disc,low,parent,visited,timer,i,result);
        }
    }

    return result;

}
