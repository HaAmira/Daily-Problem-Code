#include<iostream>
#include<string>
#include<vector>
#include <unordered_map>

using namespace std;

int maxLen;
unordered_map<string,int> m;

void solve(string& s, string& p, int i, int count){
    if(count<0){
        return ;
    }
    if(i>=s.size()){
        if(count==0){
            if(maxLen<p.size()){
                maxLen=p.size();
                m.clear();
                m[p]++;
            }
            else if(maxLen==p.size()){
                m[p]++;
            }
        }
        return ;
    }

    if(s[i]!='(' && s[i]!=')'){
        p.push_back(s[i]);
        solve(s,p,i+1,count);
        p.pop_back();
        return ;
    }

    p.push_back(s[i]);

    solve(s,p,i+1,count+(s[i]=='('?1:-1));
    p.pop_back();
    solve(s,p,i+1,count);
}

    vector<string> removeInvalidParentheses(string s) {

        maxLen=0;
        int count = 0;
        string p="";
        int i=0;
        solve(s,p,i,count);

        vector<string> ans;
        for(auto i:m){
            ans.push_back(i.first);
        }

        return ans;
    }

int main(){
    // string s="(()(()))";
    string s="()())()";
    vector<string> a=removeInvalidParentheses(s);
    cout<<"Answer:- [";
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<a[i].size(); j++){
            cout<<a[i][j];
        }
        if(i!=a.size()-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;

    return 0;
}