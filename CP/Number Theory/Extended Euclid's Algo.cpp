#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define ld long double
using namespace std;
///returns x,y such that -> ax+by = gcd(a,b) and a>=b
pair<ll,ll> ext_gcd(ll a,ll b)
{
    if(b==0) {  ///Base case
        return {1,0};
    }

    ll r=a%b;
    ll q=a/b;

    auto [x1,y1]=ext_gcd(b,r);
    ll x=y1;
    ll y=x1-y1*q;

    return {x,y};
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ///freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    ll t=1,n,m,k,a1,b1,c1,z,u,v,p,q,l,r,cnt=0,ans=0,cnt1=0,cnt2=0,temp=0;string s,s1,s2;
    auto [x,y]=ext_gcd(80,22);
    cout<<x<<" "<<y<<endl;
}
