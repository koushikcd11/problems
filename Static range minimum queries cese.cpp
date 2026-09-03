#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2e9
using namespace std;

int find(vector<int> &seg,int node,int st,int en,int l,int r){
    if(l>en || r<st){
        return INF;
    }
    if(st>=l && en<=r){
        return seg[node];
    }
    int mid=(st+en)/2;
    int lt=find(seg,2*node,st,mid,l,r);
    int rt=find(seg,2*node+1,mid+1,en,l,r);
    return min(lt,rt);
}

int main(){
    int n,m;
    cin>>n>>m;
    int newn=1;
    while(newn<n) newn=newn<<1;
    vector<int> seg(2*newn,INF);
    for(int i=newn;i<newn+n;i++){
        cin>>seg[i];
    }
    for(int i=newn-1;i>0;i--){
        seg[i]=min(seg[2*i],seg[2*i+1]);
    }
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        cout<<find(seg,1,1,newn,l,r)<<endl;;
    }
}