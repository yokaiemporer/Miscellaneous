#include<iostream>
#include<vector>
using namespace std;
void displayBeads(int len,int maxelement,vector<vector<int>> &abacus)
{
for(int i=0;i<len;i++){
        
    for(int j=0;j<maxelement;j++){
        
    cout<<abacus[i][j]<<" ";
    }
    cout<<"\n";
    }
    cout<<"=================================================================\n";

}
int main()
{
    vector<int> arr;
    static int n,len,temp,maxelement,index,sum;
    cin>>n;
    len=n;
    while(n-- > 0 && cin>>temp){
    arr.push_back(temp);
    maxelement=max(maxelement,temp);
    
    }
    vector<vector<int>> abacus;
    
   
    for(auto element:arr)
    {
        vector<int> temp2(maxelement,0);
        for(int i=0;i<element;i++)
        temp2[i]=1;
        abacus.push_back(temp2);
        
    }
    // visualize beads before sort
    displayBeads(len,maxelement,abacus);

    //apply Gravity!
    for(int i=0;i<maxelement;i++)
    {
        sum=0;
        for(int j=len-1;j>=0;j--){
        sum+=abacus[j][i];
        abacus[j][i]=0;
        }
        for(int j=len-1;j>=(len-sum);j--)
        abacus[j][i]=1;
    }
    // visualize beads after sort
    displayBeads(len,maxelement,abacus);
    arr.clear();
    for(int i=0;i<len;i++)
    {
        sum=0;
        for(int j=0;j<maxelement;j++)
        sum+=abacus[i][j];
        arr.push_back(sum);
    }
    for(auto element: arr)
    cout<<element<<" ";

    

}