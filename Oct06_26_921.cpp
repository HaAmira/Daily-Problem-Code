#include<iostream>
#include<string>
#include<stack>

using namespace std;

    int minAddToMakeValid(string s) {
        int a=0;
        int b=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                a++;
            }
            else if(s[i]==')'){
                if(a>0){
                    a--;
                }
                else{
                    b++;
                }
            }
        }
        return a+b;
    }

int main(){
    // string s="(()(()))";
    string s="()))((";
    int a=minAddToMakeValid(s);
    cout<<"Answer:- "<<a<<endl;

    return 0;
}