#include<iostream>
#include<stdlib.h>
int count = 0;
using namespace std;

void print_arr(int arr[],int start,int size){	
	for(int i=start;i < size;i++){
		cout<<arr[i]<<" ";
	}
}

int merge(int *array_of_integers, int p, int q, int r) {
     int n1 = q - p + 1;
     int n2 = r - q; 
     int i, j, k;
     int left_array[n1 + 1];
     int right_array[n2 + 1];

     left_array[n1] = 123456798;
     right_array[n2] = 123456798;

     for (i = 0; i < n1; i++)
         left_array[i] = array_of_integers[p + i];
     for (j = 0; j < n2; j++)
         right_array[j] = array_of_integers[q + j + 1];

     i = 0;
     j = 0;

     for (k = p; k <= r; k++) {
         if (left_array[i] <= right_array[j]) {
             array_of_integers[k] = left_array[i];
             i++;
             count++;
         } 
		 else {
             array_of_integers[k] = right_array[j];
             j++;
         }
     }
     return count;
 }

int merge_sort(int *array_of_integers, int p, int r) {
    if(p >= r) {
    	return 0;
		}
    int q = p + (r-p) / 2;
    merge_sort(array_of_integers, p, q);
    merge_sort(array_of_integers, q +1, r);
    int a=merge(array_of_integers, p, q, r);
	count+=1;
	
	return count;
 }
 
int main(){
	int r,comp,arr_comp[100],j=0;
	for(int k=0;k<100;k++){
		cout<<"Enter size"<<endl;
		cin>>r;
		int arr[r];
		cout<<"Enter elements";
		for(int i=0;i < r;i++){
			arr[i]=rand();
			//cin>>arr[i];
		}
		cout<<"The Array is: ";
		print_arr(arr,0,r);
		cout<<endl;
		int p=0;
		comp=merge_sort(arr,p,r);
		arr_comp[j]=comp;
		j++;
		count=0;
		cout<<"The Array after merge sort is: "<<endl;
		if (r%2!=0)
			print_arr(arr,1,r+1);
		else
			print_arr(arr,0,r);
		cout<<endl;
	}
		
	print_arr(arr_comp,0,100);
	return 0;
}
