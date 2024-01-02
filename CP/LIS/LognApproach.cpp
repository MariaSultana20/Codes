#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define ld long double
using namespace std;
int longest_increasing_subsequence(vector<int>& arr)
{
    int n=arr.size();
    vector<int>ans;
    for(int i=0;i<n;i++){
        auto it=lower_bound(ans.begin(),ans.end(),arr[i]);
        if(it==ans.end()){    ///arr[i] is greater than all the element in the ans,leading to pushing arr[i]
            ans.push_back(arr[i]);
        }
        else {     ///replacing the cur value of ans with arr[i] where arr[i] is smaller than it.
            *it=arr[i];
        }
    }
    ///LIS array -> ans
    ///for(auto &x:ans) cout<<x<<" "; cout<<endl;
    return ans.size();
}
int main()
{
	vector<int> a = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int ans=longest_increasing_subsequence(a);
	cout<<ans<<endl;
	return 0;
}
