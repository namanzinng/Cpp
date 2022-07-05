#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=1e9+10;
vector<int> dist(N,INF);
vector<int> vis(N,0);
vector<pair<int,int>> g[N];


void dijkstra(int sr){	
	set<pair<int,int>> st;	
	st.insert({0,sr});
	dist[sr]=0;
	
	while(!st.empty()){
		auto node=*st.begin();
		int v=node.second;
		int dis=node.first;
		st.erase(st.begin());
		if(vis[v]==1) continue;
		vis[v]=1;
		for(auto child:g[v]){
			int child_v=child.first;
			int wt=child.second;
			if(dist[v]+wt<dist[child_v]){
				dist[child_v]=dist[v]+wt;
				st.insert({dist[child_v],child_v});
			}
		}	
}
}
int main(){
	int n,m;
	cout<<"Enter num of vertices and edges\n";
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,wt;
		cout<<"Enter edges and its weight\n";
		cin>>x>>y>>wt;
		g[x].push_back({y,wt});
		g[y].push_back({x,wt});
	}
	cout<<"Enter source node\n";
	int sr;
	cin>>sr;
	dijkstra(sr);
	cout<<"Vertex \t Distace from Source"<<endl;
	for(int i=0;i<n;i++)
		cout<<i<<" \t\t"<<dist[i]<<endl;
}
