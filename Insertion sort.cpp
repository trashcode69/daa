#include<iostream>
#include<stdlib.h>
using namespace std;

int insertion_sort(int arr[],int size){
	int count;
	for(int i=1;i<size;i++){
		int key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j=j-1;
			count+=1;
		}
		arr[j+1]=key;
	}
	
	return count;
}

void print_arr(int arr[],int size){	
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
}


int main(){
	int size,arr_comp[100];
	int j=0;
	for(int k=0;k<=100;k++){
		cout<<"Enter size"<<endl;
		cin>>size;
		int arr[size];
		cout<<"Enter elements";
		for(int i=0;i<size;i++){
			arr[i]=rand();
		}
		cout<<"The Array is: ";
		print_arr(arr,size);
		int a=insertion_sort(arr,size);
		arr_comp[j]=a;
		j++;
		cout<<endl<<"Array after insertion sort is: ";
		print_arr(arr,size);
		cout<<endl;
	}
	
	print_arr(arr_comp,100);
}
