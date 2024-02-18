#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define ld long double
using namespace std;
void KMP(string &pat,string &txt)
{
    int n=txt.size();
    int m=pat.size();

    int lps[m];
    ///calculate lps
    int i=1, j=0;
    lps[0]=0;
    while(i<m)
    {
        if(pat[i]==pat[j]){
            lps[i]=j+1;
            i++, j++;
        }
        else               ///pat[i]!=pat[j]
        {
            if(j!=0)       ///searching for pat[j] that match with pat[i]
            {
                j=lps[j-1];
            }
            else          ///if(j==0)  searched for pat[j] that match with pat[i], but no match found
            {
                lps[i]=0;
                i++;
            }
        }
    }
    for(auto &x:lps) cout<<x<<" ";  cout<<endl;

    ///pattern searching
    i=0;          ///index for txt[]
    j=0;          ///index for pat[]
    while((n-i)>=(m-j))
    {
        if(txt[i]==pat[j]){
            i++; j++;
        }

        if(j==m){
            cout<<"Found pattern at index "<<i-j<<endl;
            j=lps[j-1];
        }

        else if(i<n and txt[i]!=pat[j])
        {
            if(j!=0)
                j=lps[j-1];
            else      ///no match -> j=0 -> we can increment i
                i++;
        }
    }

}
int main()
{
    string txt="ABABDABACDABABCABAB";
    string pat="ABABCABAB";
    KMP(pat,txt);

    return 0;
}
