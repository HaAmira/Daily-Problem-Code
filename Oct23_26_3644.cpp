#include<bits/stdc++.h>

using namespace std;

    struct DSU {
        vector<int> p;
        DSU(int n) { p.resize(n); iota(p.begin(), p.end(), 0); }
        int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
        void unite(int x, int y) { p[find(x)] = find(y); }
    };

    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        if (is_sorted(nums.begin(), nums.end())) return 0;

        int ans = 0;
        for (int bit = 20; bit >= 0; --bit) {
            int k = ans | (1 << bit);
            DSU dsu(n);

            unordered_map<int, int> bucket; 
            for (int i = 0; i < n; ++i) {
                if ( (nums[i] & k) == k ) { 
                    int mask = nums[i] & k;
                    if (bucket.count(mask)) {
                        dsu.unite(i, bucket[mask]);
                    } else {
                        bucket[mask] = i;
                    }
                }
            }

            bool can = true;
            for (int i = 0; i < n; ++i) {
                if (dsu.find(i) != dsu.find(nums[i])) {
                    can = false;
                    break;
                }
            }
            if (can) ans = k;
        }
        return ans;
    }

int main(){

    vector<int> nums={0,3,2,1};

    cout<<"Answer:-> "<<sortPermutation(nums);

    return 0;
}