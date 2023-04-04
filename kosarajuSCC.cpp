#https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


#include<unordered_map>
#include<list>
#include<stack>


void findSCC(unordered_map<int,list<int>> &transposeAdj,unordered_map<int,bool> &transVis,int node){
	transVis[node]=true;

	for(auto it:transposeAdj[node]){
		if(!transVis[it]){
			findSCC(transposeAdj,transVis,it);
		}
	}
		
}
void dfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,int node,stack<int> &st){
	visited[node] = true;
	for(auto it: adj[node]){
		if(!visited[it]){
			dfs(adj,visited,it,st);
		}
	}
	st.push(node);
}
// void transpose(vector<vector<int>> &edges,unordered_map<int,list<int>> &transposeAdj){
// 	for(int i=0;i<edges.size();i++){
// 		int u = edges[i][0];
// 		int v = edges[i][1];

// 		transposeAdj[v].push_back(u);
// 	}
// }

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	unordered_map<int,list<int>> adj;
	for(int i=0;i<edges.size();i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}
	unordered_map<int,bool> visited;
	unordered_map<int,bool> transVis;
	stack<int> st;
	for(int i=0;i<v;i++){
		if(!visited[i]){
			dfs(adj,visited,i,st);
		}
	}
	unordered_map<int,list<int>> transposeAdj;
	//transpose(edges,transposeAdj);
	for(int i=0;i<v;i++){
		for(auto it:adj[i]){
			transposeAdj[it].push_back(i);
		}
	}

	//cout<<s.size()<<endl;
	int count=0;
	while(!st.empty()){
		int front = st.top();
		st.pop();
		

		if(!transVis[front]){
			count++;
			findSCC(transposeAdj, transVis,front);
		}
	}
	return count;
	
}
