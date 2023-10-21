#include <iostream>
using namespace std;

void merge(int a[], int s, int m, int e)
{
    int ans[e-s+1];
    int i,j,k;
    i=s;
    j=m+1;
    k=0;

    while (i<=m && j<=e)
    {
            if (a[i]<a[j])
            {
                ans[k] = a[i];
                i++;
                k++;
            }
            else
            {
                ans[k] = a[j];
                j++;
                k++;
            }
    }

        while (i<=m)
        {
            ans[k] = a[i];
            i++;
            k++;
        }

        while (j<=e)
        {
            ans[k] = a[j];
            j++;
            k++;
        }

         for(int i=s;i<=e;i++)
 		    a[i]=ans[i-s];

        cout << "till now , the merged array : ";

        for (int i=0; i<k; i++)
        {
            cout << ans[i] << " ";
        }
        cout<<endl;
    
}

void mergesort(int a[],int s,int e)
{
    if(s>=e)
    {
        return;
    }
    else
    {
        int mid=(s+e)/2;
        cout<<"s:"<<s<<" e:"<<e<<" mid:"<<mid<<endl; 
        mergesort(a,s,mid);
        mergesort(a,mid+1,e);
        merge(a,s,mid,e);
    }
}

int main()
{
     int size,a[50];

     cout<<"enter the size of array\n";
     cin>>size;

     cout<<"enter elements\n";
     for(int i=0;i<size;i++)
       cin>>a[i];

     mergesort(a,0,size-1);

     cout<<"final sorted array\n";
     for(int i=0;i<size;i++)
       cout<<a[i]<<" ";
}

