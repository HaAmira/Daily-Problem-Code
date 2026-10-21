#include<iostream>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h>

using namespace std;

    int solve1(vector<int>& nums, int t){
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if (nums[m] == t) {
                if (m == 0 || nums[m - 1] != t) {
                    return m;
                }
                e = m - 1;
            }
            else if(nums[m]>t){
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return -1;
    }

    vector<int> targetIndices(vector<int>& nums, int t) {
        sort(nums.begin(),nums.end());
        int s=solve1(nums,t);
        // int e=solve2(nums,t);
        vector<int> ans;
        cout<<s<<endl;

        int i=s;
        while(i!=-1 && i<nums.size() && nums[i]==t){
            ans.push_back(i);
            i++;
        }
        return ans;
    }

int main(){

    vector<int> nums = {1,2,5,2,3};
    int t=2;

    vector<int> a=targetIndices(nums,t); 
    cout<<"Answer:-> ";
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<",";
    }

    return 0;
}