#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int pairs_diff_k(vector<int>arr,int k){
    int n=arr.size();
    int count=0;
    sort(arr.begin(),arr.end());
    for(int i=0,j=0;j<n;j++){
        int abs_diff=abs(arr[i]-arr[j]);

        while(abs_diff>k){
            i++;
            abs_diff=abs(arr[i]-arr[j]);
        }
        count+=(j-i+1);
    }
    return count-n;
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
    int count=pairs_diff_k(arr,k);
    cout<<"Number of pairs with absolute difference less than or equal to  "<<k<<" : "<<count;
}