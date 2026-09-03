#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int find(vector<int> &ldr,int t){
    if(ldr[t]!=t){
        ldr[t]=find(ldr,ldr[t]);
    }
    return ldr[t];
}

void join(vector<int> &ldr,int l,int r){
    int lt=find(ldr,l);
    int rt=find(ldr,r);
    ldr[lt]=rt;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> ldr(n+1),grp(n+1,0),edge(n+1,0);
    vector<pair<int,int>> nedge(m);
    for(int i=0;i<=n;i++){
        ldr[i]=i;
    }
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        nedge[i]={l,r};
        join(ldr,l,r);
    }
    for(int i=1;i<=n;i++){
        int was=find(ldr,i);
        grp[was]++;
    }
    for(auto[l,r]:nedge){
        int ulti=find(ldr,l);
        edge[ulti]++;
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long sans=grp[i];
        ans+=(sans*(sans-1)/2)-edge[i];
    }
    cout<<ans<<endl;
}