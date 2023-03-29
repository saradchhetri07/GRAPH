https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


#include<queue>
#include<unordered_map>
#include<list>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	unordered_map<int,list<int>> adj;
	for(int i=0;i<edges.size();i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int> q;
	unordered_map<int,bool> visited;
	unordered_map<int,int> parent;

	visited[s] = true;
	q.push(s);
	parent[s]=-1;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(auto neighbour:adj[front]){
			if(!visited[neighbour]){
				q.push(neighbour);
				visited[neighbour]=true;
				parent[neighbour] = front;
			}
		}
	}
	//find path from parent map
	vector<int> ans;
	int temp = t;
	ans.push_back(temp);
	while(temp!=s){
		ans.push_back(parent[temp]);
		temp = parent[temp];
		
		
	}
	reverse(ans.begin(),ans.end());
	return ans;
    
}
