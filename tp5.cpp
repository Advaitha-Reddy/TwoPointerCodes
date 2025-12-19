#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> st;

        int maxLen = 0;

        for (int i = 0, j = 0; j < n; j++) {
            st.insert(nums[j]);

            int diff = *st.rbegin() - *st.begin();

            // FIXED condition
            while (diff > limit) {
                auto it = st.find(nums[i]);
                st.erase(it);
                i++;
                diff = *st.rbegin() - *st.begin();
            }

            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
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
    int len=longestSubarray(arr,k);
    cout<<"Max lengthed subarray with absolute difference between each pair less than or equal to  "<<k<<" : "<<len;
    cout<<endl;

}