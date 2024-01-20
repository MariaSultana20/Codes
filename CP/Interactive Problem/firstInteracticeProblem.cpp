/**My first interactive problem*/
/**Problem Link: https://atcoder.jp/contests/abc337/tasks/abc337_e*/
#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define ld long double
using namespace std;
int main()
{
    ///ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ///freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    ll t=1,n,m,k,a1,b1,c1,x,y,z,u,p,q,l,r,cnt=0,ans=0,cnt1=0,cnt2=0,temp=0;string s; ///cin>>t;
    cin>>n;
    x=ceil(1.0*log2(n));
    vector<ll>v[x+1];
    for(int i=1;i<n;i++){
        bitset<7>bin(i);
        for(int j=0;j<x;j++){
            if(bin[j]) v[j+1].push_back(i);
        }
    }

    cout<<x<<endl;
    fflush(stdout);
    for(int i=1;i<=x;i++){
        cout<<v[i].size()<<" ";
        for(auto &x:v[i])
            cout<<x<<" ";
        cout<<endl;
        //fflush(stdout);
    }
    fflush(stdout);
    cin>>s;
    reverse(s.begin(),s.end());
    bitset<7>bin(s);
    x=bin.to_ulong();
    if(x==0) x=n;
    cout<<x<<endl;
    fflush(stdout);
    return 0;
}
