///Segment tree
#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define ld long double
using namespace std;
class Tree
{
public:
    int propagation=0, sum=0;
};
const int N = 2e5+10;
int a[N];
Tree tree[N<<2];
void build(int i,int j,int ti)
{
    if(i==j){
        tree[ti].sum = a[i]; return;
    }
    int mid=(i+j)/2;
    build(i,mid,2*ti);
    build(mid+1,j,2*ti+1);
    tree[ti].sum=tree[2*ti].sum+tree[2*ti+1].sum;
}
void update(int qi,int qj,int x,int i,int j,int ti)  ///range update
{
    if(j<qi or i>qj) {              ///irrelevant segment or out of bound segment
        return;
    }
    if(i>=qi and j<=qj){           ///contributor or relevant segment
        tree[ti].propagation+=x;
        tree[ti].sum+=(j-i+1)*x;
    }
    else{              ///overlapping segment
        int mid=(i+j)/2;
        update(qi,qj,x,i,mid,2*ti);
        update(qi,qj,x,mid+1,j,2*ti+1);
        tree[ti].sum=tree[2*ti].sum + tree[2*ti+1].sum + (j-i+1)*tree[ti].propagation;
    }
}
int query(int qi,int qj,int i,int j,int ti,int carry=0)
{
    if(j<qi or i>qj) return 0;          ///irrelevant or out of bound
    if(i>=qi and j<=qj)                 ///contributor or relevant
        return (j-i+1)*carry + tree[ti].sum;

    ///partially overlap
    int mid=(i+j)/2;
    int prop=tree[ti].propagation;
    int L=query(qi,qj,i,mid,2*ti, carry+prop);
    int R=query(qi,qj,mid+1,j,2*ti+1,carry+prop);
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
            cin>>l>>r>>x;
            update(l,r,x,1,n,1);
        }
        else if(choice==2){  ///query
            cin>>l>>r;
            cout<<query(l,r,1,n,1,0)<<endl;
        }
        else{
            cout<<"Invalid choice\n";
        }
    }
}
/**
5 8
1 1 2 3 3
2 1 2
1 2 3 2
2 2 4
2 2 2
1 1 3 1
2 2 3
1 1 3 1
2 1 3

Ans:
2
10
3
9
14
*/

