#include<iostream>
#include<stdlib.h>
using namespace std;

int left(int i){
	int j=i*2+1;
	return j;
}

int right(int i){
	int j=i*2+2;
	return j;
}

int max_heapify(int arr[],int i,int size){
	int count=1;
	int l=left(i);
	int r=right(i);
	int largest;
	if (l < size and arr[l] > arr[i])
		largest=l;
	else
		largest=i;
	if (r<size and arr[r] > arr[largest])
		largest=r;
	if (largest!=i){
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		count++;
		max_heapify(arr,largest,size);
	}
	return count;
}

int build_max_heap(int arr[],int size){
	int count=1;
	for(int i=(size-1)/2;i>=0;i--){
		count=count+max_heapify(arr,i,size)+1;
	}
	return count;
}

int heap_sort(int arr[],int size){
	int count=build_max_heap(arr,size);
	for(int i=size-1;i>0;i--){
		int temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		size=size-1;
		count=count+max_heapify(arr,0,size)+1;
	}
	return count;
}

void print_arr(int arr[],int size){	
	for(int i=0;i < size;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int size=21,j=0,arr_comp[100];
	for(int i=0;i<100;i++){
		cout<<"Enter size"<<endl;
		size=size+9;
		cout<<size<<endl;
		int arr[size];
		cout<<"Enter elements";
		for(int i=0;i < size;i++)
			arr[i]=rand();
		cout<<"The Array is: ";
		print_arr(arr,size);
		cout<<endl;
		int count=heap_sort(arr,size);
		arr_comp[j]=count;
		j++;
		cout<<"The array after heap sort"<<endl;
		print_arr(arr,size);
	}
	cout<<endl;
	print_arr(arr_comp,100);
	return 0;
}
