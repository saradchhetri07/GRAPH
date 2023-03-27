https://www.codingninjas.com/codestudio/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h> 
#include<unordered_map>


#include<stack>
void dfs(unordered_map<int,list<int>> adj,vector<bool> &visited,stack<int> &s,int node){
    visited[node]= true;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(adj,visited,s,it);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    vector<bool> visited(v);
    stack<int> s;
    vector<int> ans;
    for(int i=0;i<v;i++){
        if(!visited[i]){
                dfs(adj,visited,s,i);
        }
    }
    
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;

}
