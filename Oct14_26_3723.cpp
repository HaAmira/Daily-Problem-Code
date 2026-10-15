#include<iostream>
#include<vector>
#include<string>

using namespace std;

    string maxSumOfSquares(int num, int sum) {
        int s=sum;
        string ans;

        while(sum>0 && ans.size()<num){
            if(sum<=9){
                // s=s+sum;
                int a=sum+'0';
                ans.push_back(a);
                sum=0;
            }
            else{
                // s=s+9;
                sum=sum-9;
                ans.push_back('9');
            }
        }

        while(ans.size()<num){
            ans.push_back('0');
        }

        int p=0;

        for(int i=0; i<ans.size(); i++){
            int a=ans[i]-'0';
            p=p+a;
        }
        if(s==p){
            return ans;
        }

        return "";
    }

int main(){

    int num = 2;
    int sum = 17;

    string a=maxSumOfSquares(num, sum); 
    cout<<"Answer:- "<<a<<endl;

    return 0;
}