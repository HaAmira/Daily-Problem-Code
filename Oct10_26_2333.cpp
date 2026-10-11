#include<iostream>
#include<vector>

using namespace std;

void solve(vector<int>& a, int n, int& i, int m){
    int j=0;
    while(i<m){
        if(a[j]>0){
            a[j]--;
        }
        else{
            a[j]++;
        }
        i++;
        j++;
        if(j>=n){
            break;
        }
    }
}

    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        long long m=k1+k2;
        int ans=0;
        long long s=0;
        vector<int> a;
        
        for(int i=0; i<n; i++){
            int p=abs(nums1[i]-nums2[i]);
            a.push_back(p);
        }
        sort(a.rbegin(),a.rend());

        int i=0;
        int j=0;
        bool findZero=false;
        long long finalZero=-1;
        long long finalj=-1;
        long long finalLeft=-1;
        while(m>0){
            int p=a[j];
            while(j<n && p==a[j]){
                j++;
            }

            if(m>=j){
                long long u=0;
                if(j<n){
                    u=a[j-1]-a[j];
                }
                else{
                    u=a[j-1];
                }
                long long v=u;
                u=u*j;
                if(m>u){
                    m=m-u;
                    finalZero=v;
                    finalj=j;
                    if(j>=n){
                        findZero=true;
                        break;
                    }
                }
                else if(m<=u){
                    int q=m/j;
                    int r=m%j;
                    finalZero=q;
                    finalj=j;
                    finalLeft=r;
                    m=0;
                    break;
                }
            }
            else{
                finalLeft=m;
                m=0;
                break;
            }
        }

        if(finalZero!=-1 && finalj!=-1){
            j=finalj-1;
            while(j>=0 && a[j]==0){
                j--;
            }
            if(j>=0){
                a[j]=a[j]-finalZero;
                int g=a[j];
                j--;
                while(j>=0){
                    a[j]=g;
                    j--;
                }
            }
        }
        int l=0;
        while(l<finalLeft){
            if(a[l]>0){
                a[l]=a[l]-1;
            }
            l++;
        }

        if(m>0){
            return 0;
        }

        for(int i=0; i<a.size(); i++){
            long long p=(long long)a[i];
            p=p*p;
            s=s+p;
        }

        return s;
    }

int main(){

    vector<int> nums1 = [18,4,8,19,13,8];
    vector<int> nums2 = [18,11,8,2,13,15];
    int k1 = 16;
    int k2 = 8;
    int a=minSumSquareDiff(nums1,nums2,k1,k2);
    cout<<"Answer:- "<<a<<endl;

    return 0;
}