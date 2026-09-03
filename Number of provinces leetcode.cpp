#include <iostream>
#include <vector>
#include <set>
using namespace std;

int find(vector<int> &ldr,int t){
    if(ldr[t]!=t){
        ldr[t]=find(ldr,ldr[t]);
    }
    return ldr[t];
}

void join(vector<int>&ldr,int l,int r){
    ldr[find(ldr,l)]=find(ldr,r);
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n=isConnected.size();
    vector<int> ldr(n+1);
    for(int i=0;i<=n;i++){
        ldr[i]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            if(isConnected[i][j]==1){
                join(ldr,i+1,j+1);
            }
        }
    }
    set<int> dis;
    for(int i=1;i<=n;i++){
        dis.insert(find(ldr,i));
    }
    return dis.size();
}