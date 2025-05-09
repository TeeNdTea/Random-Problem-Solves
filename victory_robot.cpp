#include<bits/stdc++.h>
using namespace std;
int main()
{
        int t;
        cin >> t;  
        while(t--) 
        {
            int n;
            cin >> n;  
            if(n == 1971) cout << "Joy Bangla" << endl;
            else if(n % 2 == 0) cout << "Bangla" << endl;
            else cout << "Joy" << endl;
        }
    return 0;
}