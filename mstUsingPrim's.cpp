//https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


#include <bits/stdc++.h> 
#include<unordered_map>
#include<limits.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<g.size();i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);
   
    for(int i=0;i<=n;i++){
        key[i]=INT_MAX;
        mst[i]=false;
        parent[i]=-1;
    }
     key[1]=0;
     parent[1]=-1;
   
    for(int i=1;i<=n;i++){
         int mini = INT_MAX;
        int u;
        //find minimum value from key array
       for(int v=1;v<=n;v++){
           if(mst[v]==false && key[v]<mini){
               u=v;
               mini = key[v];
           }
           
       }
        mst[u] = true;
       //check for adjacent value of u
        for(auto it:adj[u]){
           int v= it.first;
           int w = it.second;
           if(mst[v]==false && w<key[v]){
               key[v]=w;
               parent[v]=u;
           }

       }
    }

    vector<pair<pair<int, int>, int>> result;
    for(int i=2;i<=n;i++){
      result.push_back({{parent[i],i},key[i]});
    }
    
    return result;
}
