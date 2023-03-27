#https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        int visited[V] = {0};
        visited[0] = 1;
        q.push(0);
        vector<int> BFS;
       
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            BFS.push_back(frontNode);
            for(auto it:adj[frontNode]){
                if(!visited[it]){
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        return BFS;
    }
};


