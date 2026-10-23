#include<bits/stdc++.h>

using namespace std;

    int minOperations(string s) {
        string p=s;
        string t=s;
        int n=s.size()-1;
        sort(p.begin(),p.end());
        if(s.size()==2 && p!=s){
            return -1;
        }
        if(s==p){
            return 0;
        }

        int ans1=0;
        int ans2=0;
        int ans=0;

        while(ans1<=30){
            if(s==p){
                // return ans1;
                break;
            }
            // cout<<"("<<s<<",";
            string a=s;
            sort(s.begin(),s.begin()+n);
            // cout<<s<<") ,";
            if(a!=s){
                ans1++;
            }
            if(s==p){
                // return ans1;
                break;
            }
            // cout<<"("<<s<<",";
            string b=s;
            sort(s.begin()+1,s.end());
            // cout<<s<<") ,"<<endl;
            if(b!=s){
                ans1++;
            }
            if(s==p){
                // return ans1;
                break;
            }
        }

        while(ans2<=30){
            if(t==p){
                // return ans1;
                break;
            }

            string a=t;
            sort(t.begin()+1,t.end());
            if(a!=t){
                ans2++;
            }
            if(t==p){
                break;
            }
            
            string b=t;
            sort(t.begin(),t.begin()+n);
            if(b!=t){
                ans2++;
            }
            if(t==p){
                break;
            }
        }

        if(ans1==0 || ans2==0){
            ans=max(ans1,ans2);
            return ans;
        }
        return min(ans1,ans2);
    }

int main(){

    string s="dog";

    cout<<"Answer:-> "<<minOperations(s);

    return 0;
}