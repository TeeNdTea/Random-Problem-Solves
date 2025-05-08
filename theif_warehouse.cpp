#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000005;
long long a[MAX];
int arr[MAX];

long long getMaxArea(int n) 
{
    long long max_area = 0;
    int sz = 0;
    int i = 0;
    while(i<n) 
    {
        if (sz == 0 || a[arr[sz - 1]] <= a[i]) 
        {
            arr[sz] = i;
            sz++;
            i++;
        } 
        else 
        {
            int idx1 = arr[sz - 1];
            sz--;

            int w;
            if(sz == 0)  w = i;
            else w = i - arr[sz-1] - 1;
            long long area = a[idx1] * w;
            if (area > max_area) max_area = area;
        }
    }

    while(sz > 0) 
    {
        int idx1 = arr[sz - 1];
        sz--;
        int w;
        if (sz == 0) w = i; 
        else w = i - arr[sz - 1] - 1;
        long long area = a[idx1] * w;
        if (area > max_area) max_area = area;
    }
    return max_area;
}
int main() 
{
    int t;
    cin >> t;
    for(int q=0; q<t; q++) 
    {
        int n;
        cin >> n;
        for(int i=0; i<n; i++) 
        {
            cin >> a[i];
        }
        long long res = getMaxArea(n);
        cout << res << endl;
    }
    return 0;
}

