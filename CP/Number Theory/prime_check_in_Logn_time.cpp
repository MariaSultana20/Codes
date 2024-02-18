    ///Prime check function in logn\\\

#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define ld long double
using namespace std;
///returns a^n mod m
ll big_power(ll a,ll b,ll m)
{
    if(b==0) return 1;
    ll res=big_power(a,b/2,m);
    if(b&1) return (((res*a)%m)*res)%m;
    else return (res*res)%m;
}

///checks whether or not a number is prime in logn time
bool prime_check(int n)
{
    vector<ll>a{2,3,5,7,11,13,17,19,23,29,31,37};
    if(n<38){
        if(!binary_search(a.begin(),a.end(),n)) return false;
    }
    else {
        for(auto &x:a) {
            if(big_power(x,n-1,n)!=1) return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ///freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    ll t=1,n,m,k,a1,b1,c1,x,y,z,u,v,p,q,l,r,cnt=0,ans=0,cnt1=0,cnt2=0,temp=0;string s,s1,s2; cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<prime_check(n)<<endl;
    }
}
