#include <iostream>
#include <vector>
#include <set>
using namespace std;

int find(vector<int>&ldr,int t){
    if(ldr[t]!=t){
        ldr[t]=find(ldr,ldr[t]);
    }
    return ldr[t];
}
void join(vector<int>&ldr,int lt,int rt){
    int l=find(ldr,lt);
    int r=find(ldr,rt);
    ldr[l]=r;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> ldr(n+1);
    for(int i=0;i<=n;i++){
        ldr[i]=i;
    }
    for(int i=0;i<m;i++){
        int lt,rt;
        cin>>lt>>rt;
        join(ldr,lt,rt);
    }
    set<int> dis;
    for(int i=1;i<=n;i++){
        dis.insert(find(ldr,i));
    }
    cout<<dis.size()<<endl;
}