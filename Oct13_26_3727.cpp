#include<iostream>
#include<vector>

using namespace std;

    long long ll=1;
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            nums[i]=abs(nums[i]);
        }

        sort(nums.begin(),nums.end());
        int n=nums.size();
        int m=n/2;
        long long sum=0;

        int j=m;
        for(int i=0; i<m; i++){
            long long a=ll*nums[i];
            long long b=ll*nums[j];
            a=a*a;
            b=b*b;
            a=b-a;
            sum=sum+a;
            j++;
        }
        if(j<n){
            long long p=ll*nums[j];
            p=p*p;
            sum=sum+p;
        }

        return sum;
    }

int main(){

    vector<int> nums = {1,-1,2,-2,3,-3};

    int a=maxAlternatingSum(nums); 
    cout<<"Answer:- "<<a<<endl;

    return 0;
}