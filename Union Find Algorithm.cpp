#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int parent[N];
int size[N];
void make(int v){
	parent[v]=v;
	size[v]=1;
}
int find(int v){
	if(v==parent[v])
		return v;
	return parent[v]=find(parent[v]);	
}
void Union(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b){
		if(size[a]<size[b])
		swap(a,b);
		parent[b]=a;
	}
	size[a]+=size[b];
}
int main(){
	make(1);
	make(2);
	Union(1,2);
	make(3);
	make(4);
	Union(2,4);
	cout<<"parent of 4 is = "<<find(4);
	return 0;
}
