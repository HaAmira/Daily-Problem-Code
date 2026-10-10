#include<iostream>
#include<string>

using namespace std;

    int minInsertions(string s) {
        int a=0;
        int ans=0;
        int i=0;

        while(i<s.size()){
            if(s[i]=='('){
                a++;
            }
            else if(s[i]==')'){
                if(a>0){
                    if(s[i+1]==')'){
                        i++;
                    }
                    else{
                        ans++;
                    }
                    a--;
                }
                else{
                    if(s[i+1]==')'){
                        ans++;
                        i++;
                    }
                    else{
                        ans=ans+2;
                    }
                }
            }
            // cout<<i<<":- "<<s[i]<<","<<ans<<"| "<<a<<endl;
            i++;
        }
        if(a>0){
            ans=ans+(a*2);
        }
        return ans;
    }

int main(){

    string s="(()))";
    string a=minInsertions(s);
    cout<<"Answer:- "<<a<<endl;

    return 0;
}