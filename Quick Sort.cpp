#include<iostream>
#include<stdlib.h>
using namespace std;

int partition(int arr[],int p,int r){
	int x = arr[r];
	int i = p-1;
	int temp;
	for(int j=p;j<r;j++){
		if (arr[j]<=x){
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	
	temp=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=temp;
	i++;
	return i;
}

void quicksort(int arr[],int p,int r){
	if (p<r){
		int q=partition(arr,p,r);
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);
	}
}

void print_arr(int arr[],int size){	
	for(int i=0;i < size;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int size;
	cout<<"Enter size"<<endl;
	cin>>size;
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
	quicksort(arr,p,r);
	cout<<"The array after quick sort"<<endl;
	print_arr(arr,size);
}
