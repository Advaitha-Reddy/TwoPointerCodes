#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> st;

        int count = 0;

        for (int i = 0, j = 0; j < n; j++) {
            st.insert(nums[j]);

            int diff = *st.rbegin() - *st.begin();

            while (diff > limit) {
                auto it = st.find(nums[i]);
                st.erase(it);
                i++;
                diff = *st.rbegin() - *st.begin();
            }

            count+=(j-i+1);
        }

        return count;
    }


int main(){
    int n;
    //cout<<"Enter the number of elements: "<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int count=longestSubarray(arr,k);
    cout<<"Number of subarrays with absolute difference between each pair less than or equal to  "<<k<<" : "<<count;
    cout<<endl;

}