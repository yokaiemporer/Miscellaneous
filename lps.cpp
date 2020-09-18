#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i=1;
    string str="AAACAAAAAC";
    int lps[str.size()]={0};
    int m=str.size();
    int j=0;
    lps[0]=0;
    while(i<m)
    {
        if(str[i]==str[j])
        {
            lps[i]=++j;
            i++;
        }
        else
        {
            if(j==0)
            {
                lps[i]=j;
                i++;
            }
            else
            j=lps[j-1];
        }
    }
    for(auto i:lps)
    cout<<i<<" ";
    return 0;
}