#include <bits/stdc++.h>
using namespace std;
int longest_increasing_subsequence(vector<int>& arr)
{
    int n=arr.size();
    vector<int>dp(n,1);  ///dp[i]=lis upto index i
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j]<arr[i])
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    int mx=0;
    for(int i=0;i<n;i++){
        mx=max(mx,dp[i]);
    }
    return mx;
}
int main()
{
	vector<int> a = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int ans=longest_increasing_subsequence(a);
	cout<<ans<<endl;
	return 0;
}
