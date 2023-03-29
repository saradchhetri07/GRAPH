https://replit.com/@saradchhetri1/CharmingAdventurousNanocad#shortestPath.cpp


//shortest path in directed acyclic graph(DAG)

#include <iostream>
#include <unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;
class Graph{
  public:
  unordered_map<int,list<pair<int,int>>> adj;

  void addGraph(int u,int x,int y){
    pair<int,int> p=make_pair(x,y);
    adj[u].push_back(p);
  }

void printGraph(){
  for(auto it:adj){
    cout<<it.first<<"->";
    for(auto j:it.second){
      cout<<"["<<j.first<<","<<j.second<<"]";
    }
    cout<<endl;
  }
}
void dfs(unordered_map<int,list<pair<int,int>>> adj,unordered_map<int,bool> &visited,int node,stack<int> &s){
  visited[node] = true;
  for(auto neighbour:adj[node]){
    if(!visited[neighbour.first]){
      dfs(adj,visited,neighbour.first,s);
    }
  }
  s.push(node);
}
};

int main() {
  Graph g;
  g.addGraph(0, 1, 5);
  g.addGraph(0, 2, 3);
  g.addGraph(1, 2, 2);
  g.addGraph(1, 3, 6);
  g.addGraph(2, 3, 7);
  g.addGraph(2, 4, 4);
  g.addGraph(2, 5, 2);
  g.addGraph(3, 4, -1);
  g.addGraph(4, 5, -2);

  g.printGraph();

  unordered_map<int,bool> visited;
  //topological sort using dfs
  int n=6;
  stack<int> s;
  for(int i=0;i<n;i++){
    if(!visited[i]){
      g.dfs(g.adj,visited,i,s);
    }
  }
  vector<int> distance(n);
  int source = 1;
  int target = 5;
  for(int i=0;i<n;i++){
    distance[i]=INT_MAX;
  }
  distance[source]=0;
  while(!s.empty()){
    int top = s.top();
    s.pop();
    if(distance[top]==INT_MAX){
      continue;
    }else{
      for(auto it:g.adj[top]){
        int temp = distance[top]+it.second;
        if(temp<distance[it.first]){
          distance[it.first]= temp;
        }
      }
    }
  }
  for(int i=0;i<distance.size();i++){
    cout<<i<<"->"<<distance[i]<<endl;
  }

  
}
