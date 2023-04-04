
//https://replit.com/@saradchhetri1/FloweryOurAdmin#main.cpp

//cycle detection in undirected graphs
#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <list>
#include<iostream>
using namespace std;
int min(int a,int b){
    if(a < b){
        return a;
    }
    return b;
}
void dfs(int node,int parent,unordered_map<int, list<int>> &adj,vector<int> &disc,vector<int> &low,int timer,unordered_map<int,bool > &visited,vector<int> &result){

    visited[node] = true;
    low[node]= disc[node] = timer++;
  int child =0;
    for(auto neighbour: adj[node]){
        if(neighbour==parent){
            continue;
        }if(!visited[neighbour]){
            dfs(neighbour,node,adj,disc,low,timer,visited,result);
            
            low[node]=min(low[node],low[neighbour]);
            //check if it is articulation point

            if(low[neighbour]>=disc[node] && parent !=-1){
                result[node]=1;
            }
          child++;

        }else{
            low[node] = min(low[node],disc[neighbour]);
        }
    }
  // cout<<node<<"->"<<parent<<endl;
  
    if(parent==-1 && adj[0].size()>1){
        result[node]=1;
     
    }
    

}
int main(){
    vector<pair<int,int> > edges;
    int v=5;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(1,2));
    

    unordered_map<int, list<int>> adj;

    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    int parent = -1;
    vector<int> disc(v);
    vector<int> low(v);
    vector<int> art(v,0);
    int timer =0;

    for(int i=0;i<v;i++){
        disc[i]=-1;
        low[i]=-1;
    }
    unordered_map<int,bool > visited(v);
    vector<int> result;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,parent,adj,disc,low,timer,visited,art);
        }
    }
  for(int i=0;i<v;i++){
    if(art[i]==1){
      cout<<i<<endl;
    }
  }

 





    
}
