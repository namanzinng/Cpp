#include <bits/stdc++.h>
using namespace std;
#define R 5
#define C 5

struct Cell{
	int x;
	int y;
};

struct Queue{
	Cell pt; 
	int dist;
};

bool checkValid(int R, int C){
	return ((R >= 0) && (R < R) &&	(C >= 0) && (C < C));
}

int RNum[] = {-1, 0, 0, 1};
int CNum[] = {0, -1, 1, 0};

int bfsLee(int mat[][C], Cell src, Cell dest){
	if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
		return -1;

	bool visited[R][C];
	memset(visited, false, sizeof visited);

	visited[src.x][src.y] = true;

	queue<Queue> q;
	
	Queue s = {src, 0};
	q.push(s); 

	while (!q.empty()){
		Queue curr = q.front();
		Cell pt = curr.pt;

		if (pt.x == dest.x && pt.y == dest.y)
			return curr.dist;
		q.pop();
		for (int i = 0; i < 4; i++){
			int R = pt.x + RNum[i];
			int C = pt.y + CNum[i];
			
			if (checkValid(R, C) && mat[R][C] && !visited[R][C]){
				visited[R][C] = true;
				Queue Adjcell = { {R, C},curr.dist + 1 };
				q.push(Adjcell);
			}
		}
	}

	return -1;
}

int main(){
	int mat[R][C] ={
		{ 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1 },
		{ 1, 1, 1, 0, 1 },
		{ 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 0, 1 }};

	Cell source = {0, 0};
	Cell dest = {2, 1};

	int dist = bfsLee(mat, source, dest);

	if (dist != -1)
		cout<< "Length of the Shortest Path is: "<<dist ;
	else
		cout<< "Shortest Path doesn't exist";

	return 0;
}
