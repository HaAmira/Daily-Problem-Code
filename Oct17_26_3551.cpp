#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

    int minSwaps(vector<int>& nums) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,vector<int>> m;
        int sp=0;
        
        for(int i=0; i<nums.size(); i++){
            int a=nums[i];
            int s=0;
            while(a>0){
                int r=a%10;
                a=a/10;
                s=s+r;
            }
            m[nums[i]].push_back(i);

            pair<int,int> p;
            p.first=s;
            p.second=nums[i];
            pq.push(p);
        }

        for(int i=nums.size()-1; i>=0; i--){
            pair<int,int> p = pq.top();
            if(nums[i]!=p.second){
                int j=m[p.second].back();
                int a=nums[i];
                nums[i]=p.second;
                nums[j]=a;
                m[nums[j]].back()=j;
                m[nums[i]].pop_back();
                // if(m[nums[i]].empty()){
                //     m.erase(nums[i]);
                // }
                sp++;
            }
            pq.pop();
        }

        return sp;
    }

int main(){

    vector<int> nums = {18,43,34,16};

    int a=minSwaps(nums); 
    cout<<"Answer:-> "<<a<<endl;

    return 0;
}