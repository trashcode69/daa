#include<iostream>
#include<stdlib.h>
using namespace std;
int comparison =0;
int randomised_partition(int arr[],int p,int r){
	int temp;
	int s=rand()%r;
	
	int x = arr[s];
	int i = p-1;
	for(int j=p;j<r;j++){
		if (arr[j]<=x){
			i++;
			temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
		}
	}
	return i;
}

int quicksort(int arr[],int p,int r){

	if (p<r){
		comparison+=1;
		int q=randomised_partition(arr,p,r);
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);
	}
	return comparison;
}

void print_arr(int arr[],int size){	
	for(int i=0;i < size;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int size=21,arr_comp[100],j=0;
	for(int k=0;k<100;k++){
		cout<<"Enter size"<<endl;
		size=size+9;
		int arr[size];
		cout<<"Enter elements";
		for(int i=0;i < size;i++){
			arr[i]=rand();
			//cin>>arr[i];
		}
		cout<<"The Array is: ";
		print_arr(arr,size);
		cout<<endl;
		int p=0;
		int r = size-1;
		int comp=quicksort(arr,p,r);
		arr_comp[j]=comp;
		j++;
		comparison=0;
		cout<<"The array after quick sort"<<endl;
		print_arr(arr,size);
	}
	
	cout<<endl;
	print_arr(arr_comp,100);
}
