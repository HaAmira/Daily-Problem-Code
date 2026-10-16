#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

    int sumCounts(vector<int>& nums) {
        int ans=0;

        for(int i=0; i<nums.size(); i++){
            unordered_map<int,int> m;

            for(int j=i; j<nums.size(); j++){
                m[nums[j]]++;
                int b=m.size();
                b=b*b;
                ans=ans+b;
            }
        }

        return ans;
    }

int main(){

    vector<int> nums = {1,2,1};

    int a=sumCounts(nums); 
    cout<<"Answer:- "<<a<<endl;

    return 0;
}