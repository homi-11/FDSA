#include <iostream>
#include <stack>
using namespace std;

int priority(char op){
    if(op=='+' || op=='-') return 1;
    if(op=='*' || op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}

int main(){
    string infix,postfix="";
    stack<char> s;

    cout<<"Enter infix expression: ";
    cin>>infix;

    for(char c:infix){
        if(isalnum(c))
            postfix+=c;

        else if(c=='(')
            s.push(c);

        else if(c==')'){
            while(!s.empty() && s.top()!='('){
                postfix+=s.top();
                s.pop();
            }
            if(!s.empty())
                s.pop();
        }

        else{
            while(!s.empty() && priority(s.top())>=priority(c)){
                postfix+=s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }

    cout<<"Postfix: "<<postfix<<endl;

    return 0;
}