#include<iostream>
using namespace std;
int explore[4],index=0;

bool checkExplore(int arr[],int size,int v){
	for(int i=0;i<size;i++){
		if (arr[i]==v)
			return true;
	}
	return false;
}

void DFS(int Amat[4][4],int size,int u){
	explore[index]=u;
	for(int i=0;i<size;i++){
		if (Amat[u][i]==1 and checkExplore(explore,size,i)==false){
			index++;
//			explore[index]=i;
			DFS(Amat,size,i);
		}
	}
}

int main(){
	int graph[4][4]={{0,1,1,0},{1,0,0,1},{1,1,0,0},{0,0,1,0}};
	DFS(graph,4,0);
	for(int j=0;j<4;j++){
		cout<<explore[j]<<" ";
	}
	return 0;
}	
