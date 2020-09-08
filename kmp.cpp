#include<bits/stdc++.h>
using namespace std;
vector<int> failurefunc(string p)
{
    vector<int> f(p.size(),0);
    int i=1,j=0;
    while(i<p.size())
    {
        if(p[i]==p[j])
        {
            f[i]=j+1;
            i++;
            j++;
        }
        else if(j>0)
        j=f[j-1];
        else
        {
            f[i]=0;
            i++;
        }


}
return f;
}
int kmpmatch(string t,string p)
{
    vector<int>f=failurefunc(p);
    int i=0,j=0;
    while(i<t.size())
    {
        if(t[i]==p[j])
        {
            if(j==p.size()-1)
            return i-j;
            else
            {
                i++;j++;
            }
        }
        else
        {
            if(j>0)
            j=f[j-1];
            else{
                
            i++;
            }
        }
    }
    // for(auto i:f)
    // cout<<i<<" ";
    // cout<<endl;
    return -1;
}
int main()
{
    string t="abcdefghijklmnopqrstuvwxyz";
    string p="abacab";
    cout<<kmpmatch(t,p)<<endl;
    
    
    return 0;
}