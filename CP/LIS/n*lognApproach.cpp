#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define ld long double
using namespace std;
ll longest_increasing_subsequence(vector<ll>&a)
{
    ll n=a.size();
    const ll INF = 1e9;
    vector<ll>d(n+1,INF);    ///d[l]=smallest ending element of LIS of length l
    d[0]=-INF;
    for(int i=0;i<n;i++){
        int l=upper_bound(d.begin(),d.end(),a[i])-d.begin();
        if(d[l-1]<a[i] and a[i]<d[l]){
            d[l]=a[i];
        }
    }
    ///for(auto &x:d) cout<<x<<" "; cout<<endl;
    ll ans=0,pos=0;
    for(int l=n-1;l>0;l--){
        if(d[l]<INF) {
            ans=l; break;
        }
    }
    return ans;
}
int main()
{
	vector<ll> a = { 8,3,4,6,5,2,0,7,9,1 };
	ll ans=longest_increasing_subsequence(a);
	cout<<ans<<endl;
	return 0;
}
