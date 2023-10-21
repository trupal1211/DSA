#include<iostream>
using namespace std;

void marge(int a[],int m,int n)  // (array , 1st part sorted array size , 2nd ... )
{
    int i=0,j=m;  // not m+1 bcos it index 
    int k=0;
    int ans[n];

    while(i<m && j<n)
    {
        if(a[i]<a[j])
        {
            ans[k]=a[i];
            i++;k++;
        }
        else
        {
            ans[k]=a[j];
            j++;k++;
        }
    }

    while(i<m)
    {
        ans[k]=a[i];
        i++;k++;
    }

    while(j<n)
    {
        ans[k]=a[j];
        j++;k++;
    }

    cout<<"the merged array : ";

    for(int i=0;i<k;i++)
    {
        cout<<ans[i]<<" ";
    }
}

int main()
{
    int m,n;
    int a[50];
    
    cout<<"enter the size of both sorted array\n";
    cin>>m>>n;

    cout<<"enter the 1nd sorted array\n";
    
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }

    cout<<"enter the 2nd sorted array\n";

    for(int i=m;i<m+n;i++)
    {
        cin>>a[i];
    }

    marge(a,m,m+n);   // (array , 1st part sorted array size , 2nd ... )

return 0;
}

