https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


#include<unordered_map>
#include<set>
#include<vector>
#include<list>


void dfs(unordered_map<int,list<int>> &adj,vector<int> &ans,unordered_map<int,bool> &visited,int node){
    //base condition to return
    ans.push_back(node);
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(adj,ans,visited,i);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int,list<int> > adj;
    unordered_map<int,bool> visited;
    vector<vector<int>> finalAns;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<V;i++){
       if(!visited[i]){
            vector<int> ans;
            dfs(adj,ans,visited,i);
            finalAns.push_back(ans);
       }
    }
    return finalAns;
    
}
