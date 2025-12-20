#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int qs10(vector<int>arr,int k1,int k2){
    int n=arr.size();
    int count=0;
    for(int i=1;i<n-2;i++){
        int c1=0;
        for(int j=0;j<i;j++){
            if(arr[i]+arr[j]>k1){
                c1++;
            }
        }
        int k=i+1;
        int l=n-1;

        int c2=0;
        while(k<l){
            if(arr[k]+arr[l]>k2){
                c2+=l-k;
                l--;
            }
            else{
                k++;
            }
        }
        count+=c1*c2;
    }

    return count;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k1,k2;
    cin>>k1;
    cin>>k2;
    //Given Array is sorted
    int count=qs10(arr,k1,k2);
    cout<<"Number of quadruplets with the given condition is: "<<count<<endl;
}