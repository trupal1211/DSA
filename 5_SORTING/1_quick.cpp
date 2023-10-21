#include <iostream>
using namespace std;

int getpivotindex(int a[], int s, int e)
{
    int cnt = 0;
    int pivot = a[s];

    // 1. place pivot to it's correct place

    for (int i = s + 1; i <= e; i++)
    {
        if (a[i] <= pivot)
            cnt++;
    }

    int PI = s + cnt;
    swap(a[s], a[PI]);

    // 2. check both side's element  , (leftside < pivot) , (rightside > pivot)

    int i = s, j = e;

    while (i < PI && j > PI)      // index  o.w value if(arr[i] > pivot && arr[j] < pivot)
    {
        while (a[i] < pivot)
            i++;

        while (a[j] > pivot)
            j--;

        if (i < PI && j > PI)     // must recheck 
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    return PI;
};

void quicksort(int a[], int s, int e)
{
    if (s >= e)    // base case
    {
        return;
    }
    else
    {
        int PI = getpivotindex(a, s, e);

        quicksort(a, s, PI - 1); // left side
        quicksort(a, PI + 1, e); // right side
    }
};

int main()
{
    int size = 8;
    int a[8] = {40, 50, 90, 30, 100, 100, 10, 70};

    quicksort(a, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << a[i] << " ";

    return 0;
}