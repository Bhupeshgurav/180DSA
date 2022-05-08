// time:O(logn)*o(n) = nlogn as o(logn) as we are dividing by 2 and o(n) as we are linearly traversing. O(1) as we are not using extra space
// space: o(1)
#include <bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m)
{
    int gap = ceil(float(n + m) / 2);
    while (gap > 0)
    {
        int i = 0;
        int j = gap;
        while (j < (n + m))
        {
            if (j < n && arr1[i] > arr1[j])
            {
                swap(arr1[i], arr1[j]);
            }
            else if (j >= n && i < n && arr1[i] > arr2[j - n])
            {
                swap(arr1[i], arr2[j - n]);
            }
            else if (j >= n && i >= n && arr2[i - n] > arr2[j - n])
            {
                swap(arr2[i - n], arr2[j - n]);
            }
            j++;
            i++;
        }
        if (gap == 1)
        {
            gap = 0;
        }
        else
        {
            gap = ceil((float)gap / 2);
        }
    }
}

int main()
{
    int arr1[] = {1, 4, 7, 8, 10};
    int arr2[] = {2, 3, 9};

    merge(arr1, arr2, 5, 3);
    cout << "After Merge:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }
}