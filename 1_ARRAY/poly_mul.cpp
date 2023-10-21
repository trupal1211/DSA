
#include<iostream>
using namespace std;

class poly
{
public:
    int coff;
    int expo;
};

void multiplication(poly a[],poly b[],poly ans[],int t1,int t2)
{
    int i=0,j=0,k=0;
    int t3;

    while(i<t1)
    {
        j=0;
        while(j<t2)
        {
            ans[k].coff = a[i].coff * b[j].coff;
            ans[k].expo = a[i].expo + b[j].expo;

            j++;
            k++;
        }
        i++;
    }
    
    t3=k;

    for(int i=0;i<t3;i++)
    {
        for(int j=i+1;j<t3-1;j++)
        {
            if(ans[i].expo < ans[j].expo)
            {
                swap(ans[i].expo , ans[j].expo);
            }
        }
    }


    for(int i=0;i<t3-1;i++)
    {
        for( int j=i+1 ; j<t3 ; j++ )
        {
            if( ans[i].expo == ans[j].expo )
            {
                for( int k=j ; k<t3 ; k++ )
                {
                    ans[k].expo = a[k+1].expo;
                    ans[k].coff = a[k].coff + a[k+1].coff;
                }
               
                t3--;
                j--;
            }
        }
    }


    
    for(int i=0;i<t3;i++)
    {
        cout<<"+" << ans[i].coff << "x^" << ans[i].expo;
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

    multiplication(a,b,ans,t1,t2);
    

return 0;
}