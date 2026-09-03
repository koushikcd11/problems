#include <iostream>
#include <vector>
#include <map>
using namespace std;

int find(vector<int> &ldr,int t){
    if(ldr[t]!=t){
        ldr[t]=find(ldr,ldr[t]);
    }
    return ldr[t];
}

void join(vector<int> &ldr,int l,int r){
    ldr[find(ldr,l)]=find(ldr,r);
}

int main(){
    int t;
    cin>>t;
    for(int k=1;k<=t;k++){
        cout<<"Case "<<k<<":"<<endl;
        int n,q;
        cin>>n>>q;
        vector<int> arr(n+1),ldr(n+1);
        map<int,int> vlm,lvm;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            if(vlm.find(arr[i])==vlm.end()){
                vlm[arr[i]]=i;
                lvm[i]=arr[i];
            }
            ldr[i]=arr[i];
        }
        while(q--){
            int op;
            cin>>op;
            if(op==1){
                int old,neww;
                cin>>old>>neww;
                if(old==neww) continue;
                if(vlm.find(old)==vlm.end())continue;
                if(vlm.find(neww)!=vlm.end()){
                    join(ldr,vlm[old],vlm[neww]);
                    lvm.erase(vlm[old]);
                    vlm.erase(old);
                }
                else{
                    int xldr=vlm[old];
                    lvm[xldr]=neww;
                    vlm.erase(old);
                    vlm[neww]=xldr;
                }
            }
            else{
                int idx;
                cin>>idx;
                cout<<lvm[find(ldr,ldr[idx])]<<endl;
            }
        }
    }
}