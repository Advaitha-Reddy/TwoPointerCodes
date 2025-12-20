#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int qs8_google(vector<char>arr,int k){
    int n=arr.size();
    multiset<char>st;
    int max_len=0;
    for(int i=0,j=0;j<n;j++){
        st.insert(arr[j]);
        int diff=*st.rbegin()-*st.begin();
        while(diff>k){
            auto it=st.find(arr[i]);
            st.erase(it);
            i++;
            diff=*st.rbegin()-*st.begin();
        }
        int len=j-i+1;
        max_len=max(max_len,len);
    }
    return max_len;
}

int main(){
    int k;
    string st;
    getline(cin,st);
    int l=st.size();
    vector<char>arr(l);
    for(int i=0;i<l;i++){
        arr[i]=st[i];
    }
    cin>>k;
    int ans=qs8_google(arr,k);
    cout<<"Length of the longest substring with abs diff between any pair of the chars within the substr is: "<<ans<<endl;

}