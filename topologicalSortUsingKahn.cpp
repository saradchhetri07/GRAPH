https://www.codingninjas.com/codestudio/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


//topoogical sorting using kahn
#include <bits/stdc++.h> 
#include<unordered_map>
#include<queue>
#include<list>
// void dfs(unordered_map<int,list<int>> adj,vector<bool> &visited,stack<int> &s,int node){
//     visited[node]= true;
//     for(auto it:adj[node]){
//         if(!visited[it]){
//             dfs(adj,visited,s,it);
//         }
//     }
//     s.push(node);
// }
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int x = edges[i][0];
        int y = edges[i][1];

        adj[x].push_back(y);
    }
    vector<int> indegree(v);
    vector<int> ans;
    //intialize the indegree
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    //do dfs
    while(!q.empty()){
        int front = q.front();
        
        q.pop();
        ans.push_back(front);
        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    return ans;
    // vector<bool> visited(v);
    // stack<int> s;
    // vector<int> ans;
    // for(int i=0;i<v;i++){
    //     if(!visited[i]){
    //             dfs(adj,visited,s,i);
    //     }
    // }
    
    // while(!s.empty()){
    //     ans.push_back(s.top());
    //     s.pop();
    // }
    // return ans;

}
