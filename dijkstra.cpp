https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h> 
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<limits.h>

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<edges;i++){
      int u = vec[i][0];
      int v = vec[i][1];
      int w = vec[i][2];

      adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));

    }
  
    vector<int> dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }
   
    set<pair<int,int>> st;
    st.insert(make_pair(0,source));
    
    dist[source]=0;

    
    while(!st.empty()){
        // fetch the top record
        auto top = *(st.begin());

        st.erase(st.begin());
        int nodeDistance = top.first;
        int node = top.second;
        for(auto it:adj[node]){
            if((nodeDistance + it.second) < dist[it.first]){
                //search 
                auto record = st.find(make_pair(dist[it.first],it.first));

                //if found erase
                if(record != st.end()){
                    st.erase(record);
                }

                //distance update
                dist[it.first] = nodeDistance + it.second;

                st.insert(make_pair(dist[it.first],it.first));
            }
        }
        // pair<int,int> top = st.top();
        // // cout<<top.first<<","<<top.second<<endl;
        // st.pop();

        // for(auto it:adj[top.second]){
        //     int temp = it.second + dist[top.second];
        //     if(temp<dist[it.first]){
        //         cout<<it.first<<temp<<endl;
        //         dist[it.first]=temp;
        //         st.push(make_pair(temp,it.first));
        //     }
        // }
    }
    return dist;

}
