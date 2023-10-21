#include<iostream>
using namespace std;

class poly
{
public:
    int coff;
    int expo;
};

void display(poly ans[],int t);


void addition(poly a[],poly b[],poly ans[],int t1,int t2)
{
    int i=0,j=0,k=0;
    int t;

    while( i<t1 && j<t2 )
    {
        if(a[i].expo == b[j].expo)
        {
            ans[k].coff = a[i].coff + b[j].coff;
            ans[k].expo = a[i].expo;
            i++; j++; k++;
        }
        
         if(a[i].expo > b[j].expo)
        {
            ans[k].coff = a[i].coff;
            ans[k].expo = a[i].expo;
            i++; k++;
        }

        if(a[i].expo < b[j].expo)
        {
            ans[k].coff = b[j].coff;
            ans[k].expo = b[j].expo;
            j++; k++;
        }        
    }

    while(i<t1)
    {
        ans[k].coff = a[i].coff;
        ans[k].expo = a[i].expo;
        i++; k++;
    }

    while(j<t2)
    {
        ans[k].coff = b[j].coff;
        ans[k].expo = b[j].expo;
        j++; k++;
    }

    t=k;     // total size of a ans array

    display(ans,t);
}

void display(poly ans[],int t)
{
     for(int i=0;i<t;i++)
    {
        cout<< "+" << ans[i].coff << "x^" << ans[i].expo ;
    }
}

int main()
{
    poly a[10],b[10],ans[20];
    int t1,t2;

    cout<<"enter the size of a first poly\n";
    cin>>t1;

    cout<<"enter the coff. and expo. of first poly";

    for(int i=0;i<t1;i++)
    {
        cin>>a[i].coff >> a[i].expo ;
    }


    cout<<"enter the size of a second poly\n";
    cin>>t2;

     cout<<"enter the coff. and expo. of first poly";

    for(int j=0;j<t2;j++)
    {
        cin>>b[j].coff >> b[j].expo ;
    }

    addition(a,b,ans,t1,t2);   // ( a , b , ans , size of a , size of b )
 
    return 0;
}