#include<iostream>
#include<stdlib.h>
using namespace std;

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


int randomised_select(int arr[],int p,int r,int i){
	if (p==r)
		return arr[p];
	int q=randomised_partition(arr,p,r);
	int k=q-p+1;
	if (i==k)
		return arr[q];
	else if (i<k)
		return randomised_select(arr,p,q-1,i);
	else
		return randomised_select(arr,q+1,r,i);
}

void print_arr(int arr[],int size){	
	for(int i=0;i < size;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int size,i;
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
	cout<<"The position for which highest need to be found ";
	cin>>i;
	cout<<endl;
	int element=randomised_select(arr,p,r,i);
	cout<<"The "<<i<<" largest element is "<<element<<endl;
}
