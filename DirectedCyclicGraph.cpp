https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<list>
#include<vector>
#include<queue>
// bool dfs(unordered_map<int,list<int>> &adj,int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsvisited){
//   visited[node] = true;
//   dfsvisited[node] = true;
//   for(auto it:adj[node]){
//     if(!visited[it]){
//       bool cycle=dfs(adj,it,visited,dfsvisited);
//       if(cycle){
//         return true;
//       }
//     }else if(dfsvisited[it]){
//       return true;
//     }
  
//   }
//   dfsvisited[node]= false;
//   return false;
// }
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>> adj;
  for(int i=0;i<edges.size();i++){
    int u = edges[i].first-1;
    int v = edges[i].second-1;

    adj[u].push_back(v);
  }
  vector<int> indegree(n);
  int count=0;
  //indegree
  for(auto i:adj){
    for(auto j:i.second){
      indegree[j]++;
    }
  }
  //check for 0 in a indegree vector
  queue<int> q;
  for(int i=0;i<n;i++){
    if(indegree[i]==0){
        q.push(i);
    }
  }
  while(!q.empty()){
    int front = q.front();
    q.pop();
    count++;

    for(auto i:adj[front]){
      indegree[i]--;
      if(indegree[i]==0){
        q.push(i);
      }
    }
  }
  if(count==n){
    return 0;
  }
  return 1;
  // unordered_map<int,bool> visited;
  // unordered_map<int,bool> dfsvisited;
  // for(int i=1;i<=n;i++){
  //     if(!visited[i]){
  //       bool cycle = dfs(adj,i,visited,dfsvisited);
  //       if(cycle){
  //         return true;
  //       }
  //     }
  // }
  // return false;
}
