#include<iostream>
#include<algorithm>
using namespace std;

struct job{
	int start,finish,profit;
};

bool jobComparator(job s1,job s2){
	return (s1.finish < s2.finish);
}

int latestNonConflict(job arr[],int i){
	for(int j=i-1;j>=0;j--){
		if (arr[j].finish <= arr[i].start)
			return j;
	}
	return -1;
}

int findMaxProfit(job arr[],int n){
	sort(arr,arr+n,jobComparator);
	int *table=new int[n];
	table[0]=arr[0].profit;
	
	for(int i=1;i<n;i++){
		int inclProf=arr[i].profit;
		int l=latestNonConflict(arr,i);
		if (l!=-1)
			inclProf+=table[l];
		table[i]=max(inclProf,table[i-1]);
	}
	int result=table[n-1];
	delete[] table;
	
	return result;
}

int main(){
	int no,start,finish,profit;
	cout<<"Enter the no. of jobs ";
	cin>>no;
	job arr[no];
	cout<<"Enter job details "<<endl;
	for(int i=0;i<no;i++){
		cout<<"Enter Start time";
		cin>> start;
		cout<<"Enter finish time";
		cin>>finish;
		cout<<"Enter weight";
		cin>>profit;
		arr[i].start=start;
		arr[i].finish=finish;
		arr[i].profit=profit;
//		job Arr[]={start,finish,profit};
//		arr[i]=Arr;
	}
	cout<<"The optimal profit is "<<findMaxProfit(arr,no);
	return 0;
}
