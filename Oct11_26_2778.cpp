#include<iostream>
#include<vector>

using namespace std;

    int sumOfSquares(vector<int>& nums) {
        int n=nums.size();
        int sum=0;

        for(int i=0; i<n; i++){
            int j=i+1;
            if(n%j==0){
                int a=nums[i]*nums[i];
                sum=sum+a;
            }
        }
        return sum;
    }

int main(){

    vector<int> nums = {18,4,8,19,13,8};

    int a=sumOfSquares(nums); 
    cout<<"Answer:- "<<a<<endl;

    return 0;
}