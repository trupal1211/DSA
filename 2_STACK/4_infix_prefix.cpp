#include<iostream>
#include<stack>
#include <algorithm>
using namespace std;

int pre(char c)
{
    if(c == '^')
       return 3;
    else if (c == '*' || c == '/')
       return 2;
    else if (c == '+' || c == '-')
       return 1; 
    else  
      return 0;  
}

string prefix(string s)
{
    string ans;
    stack<char> st;

    reverse(s.begin(),s.end());   //

    for(int i=0 ; i<s.size() ; i++)
    {
        if( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') )
        {
            ans += s[i];
        }

        else if(s[i] == ')')                         //
        {
            st.push(s[i]);
        }

        else if( s[i]=='(' )                         //
        {
            while( !st.empty() && st.top() != ')')    //
            {
                ans += st.top();
                st.pop();
            }
            st.pop();   // retrieve '('
        }

        else
        {        
            while( !st.empty() && ( pre(s[i]) <= pre(st.top()) ) )
            {
                ans += st.top();
                st.pop();
            }

            st.push(s[i]);
        }
    }
    
    while(!st.empty())
    {
            ans += st.top();
            st.pop();
    }

    reverse(ans.begin(),ans.end());   //

    return ans;
}


int main()
{
    string s;
    cout<<" infix : ";
    cin>>s;


    cout<<" prefix : "<< prefix(s) ;

return 0;
}