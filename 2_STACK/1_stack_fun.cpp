#include<iostream>
#include<stack>
using namespace std;

// push - insert element in stack 
// pop - retrieve element from stack
// top - return a last inserted element
// empty - check is empty or not 0/1

int main()
{
    stack<int> st; 

    st.push(3);
    st.push(4);
    st.push(7);

    cout<<" size:"<< st.size();
    cout<<" empty:" << st.empty();
    
    st.pop();
    st.pop();
    st.pop();

    cout<<" empty:"<<st.empty();

 
    while(!st.empty())           // print a stack
    {
        cout << st.top() <<" ";
        st.pop();
    }

    return 0;
}