#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n){
	int dp[W+1];
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=n;i++){
		for(int w=W;w>0;w--){
			if (wt[i-1]<=w)
				dp[w]=max(dp[w],dp[w-wt[i-1]]+val[i-1]);
		}
	}
	return dp[W];
}

int main(){
	int size,W;
	cout<<"Enter the no.(s)of values given ";
	cin>>size;
	int wt[size],val[size];
	for(int i=0;i<size;i++){
		cout<<"Enter the value ";
		cin>>val[i];
		cout<<"Enter the weight ";
		cin>>wt[i];
	}
	cout<<"Enter the value of W ";
	cin>>W;
	cout<<knapSack(W,wt,val,size);
	return 0;
}
