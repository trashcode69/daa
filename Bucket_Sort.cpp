#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void Bucket_Sort(double * arr , int n){
    vector<double> bucket[n];
    for(int i=0 ; i<n ; i++){
        int index = n*arr[i];
        bucket[index].push_back(arr[i]);
    }
    int k=0;
    for(int i=0 ; i<n ; i++){
        sort(bucket[i].begin(),bucket[i].end());
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<bucket[i].size() ; j++){
            arr[k]=bucket[i][j];
            k++;
        }
    }
}

int main(){
    int n;
    cout<<"Enter Size: ";
    cin>>n;
    double * arr = new double[n];
    for(int i=0 ; i<n ; i++)
        cin>>arr[i];
    Bucket_Sort(arr,n);
    for(int i=0 ; i<n ; i++)
    	cout<<arr[i]<<"  ";
    cout<<endl;
    return 0;
}
