#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define EDGE pair<int,pair<int,int> >
using namespace std;
///segment tree
const int N = 1e6;
int a11[N];
int tree[N<<2];
void build(int i,int j,int ti)
{
    if(i==j){
        tree[ti]=a11[i]; return;
    }
    int mid=(i+j)/2;
    build(i,mid,2*ti);
    build(mid+1,j,2*ti+1);
    tree[ti]=tree[2*ti]+tree[2*ti+1];
}
void update(int i,int j,int ti,int k,int x)
{
    if(i==j){
        tree[ti]=a11[k]; return;
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

///DSU
class Disjoint
{
public:
    ///int parent[100],rank[100];
    int *parent, *rank;
    Disjoint(int n){       ///Constructor
        parent = new int[n];
        rank = new int[n];
        for(int i=0;i<n;i++){
            parent[i]=i;    ///Makeset
            rank[i]=1;     ///initializing ranking
        }
    }
    ~Disjoint(){             ///Destructor
        delete[] parent, rank;
    }

    int findSet(int x){             ///or,find representative
        if(x==parent[x]) return x;   /// return findSet(parent[x]); (without path compression)///or,
        int y=findSet(parent[x]);    ///For path compression
        parent[x]=y;
        return y;
    }
    void merge(int u,int v)         ///Union
    {
        int ru=findSet(u);
        int rv=findSet(v);
        if(ru==rv) return;
        else if(rank[ru]<rank[rv]){
            parent[ru]=rv;       ///not ru=rv
            rank[rv]+=rank[ru];
        }
        else {
            parent[rv]=ru;
            rank[ru]+=rank[rv];
        }
    }
};
int kruskal(EDGE ed[],int n,int e)   ///vector<EDGE> kruskal(EDGE ed[],int n,int e)
{
    Disjoint d(n+1);     /// Disjoint d(n); ///object
    sort(ed,ed+e);

    int mstCost=0;
    for(int i=0;i<e;i++){
        int w = ed[i].first;
        int u = ed[i].second.first;
        int v = ed[i].second.second;

        if(d.findSet(u)!=d.findSet(v)){
            mstCost+=w;
            d.merge(u,v);
        }
    }
    return mstCost;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t=1,n,m,x,y,z,k,p,q,u,v,l,r,cnt=0,ans=0,cnt1=0,cnt2=0,temp=0;string s,s1,s2; cin>>t;
    while(t--)
    {
        cin>>n;
    }
}
