#include<iostream>
#include<vector>

using namespace std;

    const long long MOD = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        int cnt[30] = {};  
        for (int x : nums)
            for (int b = 0; b < 30; b++) cnt[b] += x >> b & 1;
        long long total = 0;
        for (int i = 0; i < k; i++) {  
            long long row = 0;
            for (int b = 0; b < 30; b++)
                if (cnt[b] > i) row |= 1LL << b;  
            total = (total + row * row) % MOD;
        }
        return total;
    }

int main(){

    vector<int> nums = {2,6,5,8};
    int k=2;

    int a=maxSum(nums,k); 
    cout<<"Answer:- "<<a<<endl;

    return 0;
}