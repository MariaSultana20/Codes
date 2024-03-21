///Segment tree
///array tree and a both are in 1-based index
#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define ld long double
using namespace std;
const int N = 1e6+10;
int a[N];
int tree[N<<2];
void build(int i,int j,int ti)
{
    if(i==j){
        tree[ti]=a[i]; return;
    }
    int mid=(i+j)/2;
    build(i,mid,2*ti);
    build(mid+1,j,2*ti+1);
    tree[ti]=tree[2*ti]+tree[2*ti+1];
}
void update(int i,int j,int ti,int k,int x)
{
    if(i==j){
        tree[ti]=a[k]=x; return;
    }
    int mid=(i+j)/2;
    if(k<=mid) update(i,mid,2*ti,k,x);  ///either left child
    else   update(mid+1,j,2*ti+1,k,x);  ///or,   right child

    tree[ti]=tree[2*ti]+tree[2*ti+1];
}
int query(int qi,int qj,int i,int j,int ti)
{
    if(j<qi or i>qj) return 0;                  ///irrelevant or out of bound
    if(i>=qi and j<=qj) return tree[ti];   ///contributor or relevant

    ///partially overlap
    int mid=(i+j)/2;
    int L=query(qi,qj,i,mid,2*ti);
    int R=query(qi,qj,mid+1,j,2*ti+1);
    return L+R;
}
int main()
{
    int n,q,l,r,k,x,choice,cnt=0;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,n,1);
    while(q--){
        cin>>choice;
        if(choice==1){    ///update
            cin>>k>>x;
            update(1,n,1,k,x);
        }
        else if(choice==2){  ///query
            cin>>l>>r;
            cout<<query(l,r,1,n,1)<<endl;
        }
        else{
            cout<<"Invalid choice\n";
        }
    }
}
/**
5 4
78 1 22 12 3
2 1 2
1 2 2
2 2 4
2 4 4
*/
