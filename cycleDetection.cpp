https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


#include<unordered_map>
#include<list>
#include<queue>
// bool isCycle(unordered_map<int,list<int>> adj,int src){
//     unordered_map<int,bool> visited;
//     unordered_map<int,int> parent;
//     queue<int> q;
//     parent[src]=-1;
//     visited[src]=true;

//     q.push(src);

//     while(!q.empty()){
//         int front = q.front();
//         q.pop();

//         for(auto i:adj[front]){
//             if(visited[i] && i!=parent[front]){
//                 return true;
//             }else if(!visited[i]){
//                 q.push(i);
//                 visited[i]=true;
//                 parent[i]= front;
                
//             }
//         }
//     }
//     return false;

    
// }
bool dfs(int node,int src, unordered_map<int,bool> &visited,unordered_map<int,list<int>> adj){
    visited[node] = true;
    for(auto it:adj[node]){
        if(!visited[it]){
            bool cycle = dfs(it,node,visited,adj);
            if(cycle){
                return true;
            }
        }else if( it!=src){
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    
    unordered_map<int,list<int>> adj;

    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    unordered_map<int,bool> visited;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bool ans = dfs(i,-1,visited,adj);
            if(ans==true){
            return "Yes";
        }
     }  
    }
    return "No";
    // for(int i=0;i<n;i++){
    //     bool ans = isCycle(adj,i);
    //     if(ans==1){
    //         return "Yes";
    //     }
    // }
    // return "No";
}
