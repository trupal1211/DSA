#include<iostream>
using namespace std;

void toh(int n,char A,char B,char C)
{
    if(n>0)
    {
        toh(n-1,A,C,B);
        cout<<"("<<A<<"-"<<C<<") ";
        toh(n-1,B,A,C);
    }
}

int main()
{
    toh(3,'A','B','C');

return 0;
}

