#include<iostream>
#include<string>
#include<stack>

using namespace std;

int scoreOfParentheses(string s){
    int ans=0;
    int n=s.size();
    stack<pair<char,int>> st;

    for(int i=0; i<n; i++){
        if(s[i]=='('){
            if(i<n-1 && s[i+1]==')'){
                if(!st.empty()){
                    int a=st.top().second;
                    a++;
                    st.top().second=a;
                }
                else{
                    ans++;
                }
                i++;
            }
            else{
                st.push({'(',0});
            }
        }
        else if(s[i]==')'){
            int a=st.top().second;
            a=a*2;
            st.pop();
            if(!st.empty()){
                int b=st.top().second;
                st.top().second=a+b;
            }
            else{
                ans=ans+a;
            }
        }
    }
    return ans;
}

int main(){
    // string s="(()(()))";
    string s="(())";
    int a=scoreOfParentheses(s);
    cout<<"Answer:- "<<a<<endl;

    return 0;
}