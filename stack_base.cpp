#include<bits/stdc++.h>
using namespace std;
int prec(char c){
    if(c=='^'){
        return 3;
    }else if (c=='*' || c=='/')
    {
        return 2;
    }else if (c=='+' || c=='-')
    {
        return 1;
    }else{
        return -1;
    }    
}
void infixTopostfix(string s){
    if(!s.size()){
        return ; 
    }
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='('){
            st.push(s[i]);
        }else if (s[i]>='a' && s[i]<='z')
        {
            cout<<s[i];
        }else
        {
            if(prec(st.top())<prec(s[i])){
                st.push(s[i]);
            }else{
                while(prec(st.top())>prec(s[i])){
                    cout<<st.top();
                    st.pop();
                }
                if(st.top()=='('){
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }
    while (!st.empty()){
        if(prec(st.top())!=-1){
            cout<<st.top();
            st.pop();
        }
    }
    
}
void infixTopreFix(string s){
    if(s.size()==0){
        return ;
    }
    int i=0,j=s.size()-1;
    while (i<j)
    {
        char c = s[i];
        s[i]=s[j];
        s[j]=c;
        i++;
        j--;
    }
    
    stack<char> st;
    string res ="";
    for ( i = 0; i < s.size(); i++)
    {
        if(s[i]==')'){
            st.push(s[i]);
        }else if (s[i]>='a' && s[i]<='z')
        {
            res += s[i];
        }else
        {
            if(prec(st.top())<prec(s[i])){
                st.push(s[i]);
            }else{
                while(prec(st.top())>prec(s[i])){
                    res += st.top();
                    st.pop();
                }
                if(st.top()==')'){
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }
    while (!st.empty()){
        if(prec(st.top())!=-1){
          res += st.top();
            st.pop();
        }
        st.pop();
    }
        i=0,j=res.size()-1;
        while (i<j)
        {
            char temp = res[i];
            res[i]=res[j];
            res[j]= temp;
            i++;j--;
        }
        cout<<res<<endl;
}
int main(){
    string exp = "(a-b/c)*(a/k-l)";
    infixTopreFix(exp);
    return 0;
}