#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int atmost_k(vector<int>arr,int k){
    int n=arr.size();
    int count=0;

    int sum=0;
    for(int i=0,j=0;j<n;j++){
        sum+=arr[j];
        while(sum>=k){
            sum=sum-arr[i];
            i++;
        }
        count+=(j-i+1);

    }
    return count;
}

int pairs_greater_sum_k(vector<int>arr,int k){
    int n=arr.size();
    int total=n*(n+1)/2;
    return total-atmost_k(arr,k);
}
int main(){
    int n;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int count=pairs_greater_sum_k(arr,k);
    cout<<"Number of subarrays with sum greater than or equal to  "<<k<<" : "<<count;
}