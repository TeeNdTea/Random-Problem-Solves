#include<bits/stdc++.h>
using namespace std;
int toDecimal(char bin[]) 
{
    int res = 0;
    for (int i=0; i<8; i++) 
    {
        res = res * 2;
        if (bin[i] == '1') 
        {
            res = res + 1;
        }
    }
    return res;
}

void partDecIP(char ip[], int part[]) 
{
    int i = 0;
    int idx1 = 0;
    int val = 0;
    while (ip[i] != '\0') 
    {
        if(ip[i] == '.') 
        {
            part[idx1] = val;
            idx1++;
            val = 0;
        } 
        else 
        {
            val = val* 10 + (ip[i] - '0');
        }
        i++;
    }
    part[idx1] = val;
}

void partBinIP(char ip[], int part[]) 
{
    int i = 0;
    int idx1 = 0;
    int idx2 = 0;
    char bin[9]; 
    bin[8] = '\0';

    while(ip[i] != '\0') 
    {
        if(ip[i] == '.') 
        {
            part[idx1] = toDecimal(bin);
            idx1++;
            idx2 = 0;
        } 
        else 
        {
            bin[idx2] = ip[i];
            idx2++;
        }
        i++;
    }
    part[idx1] = toDecimal(bin);
}

int main() 
{
    int t;
    cin >> t;

    for (int q=1; q<=t; q++) 
    {
        char decIP[100], binIP[100];
        cin >> decIP;
        cin >> binIP;
        int partD[4], partB[4];
        partDecIP(decIP, partD);
        partBinIP(binIP, partB);

        bool isSame = true;
        for(int i=0; i<4; i++) 
        {
            if(partD[i] != partB[i]) isSame = false;
        }

        cout << "Case " << q << ": ";
        if (isSame == true) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
