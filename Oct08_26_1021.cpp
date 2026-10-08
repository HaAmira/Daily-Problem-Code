#include<iostream>
#include<string>

using namespace std;

    string removeOuterParentheses(string s) {
        int a=0;
        string ans;

        for(int i=0; i<s.size(); i++){
            if(a>0){
                ans.push_back(s[i]);
            }
            if(s[i]=='('){
                a++;
            }
            else if(s[i]==')'){
                a--;
            }
            if(a==0){
                ans.pop_back();
            }
        }

        return ans;
    }

int main(){
    // string s="(()(()))";
    string s="()()()()(())";
    string a=removeOuterParentheses(s);
    cout<<"Answer:- "<<a<<endl;

    return 0;
}