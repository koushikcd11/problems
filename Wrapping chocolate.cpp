#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> width;
    vector<int> chl(n+1),bxl(m+1);
    for(int i=1;i<=n;i++){
        int w; cin>>w;
        width.push_back({w,-i});
    }
    for(int i=1;i<=n;i++){
        cin>>chl[i];
    }
    for(int i=1;i<=m;i++){
        int w; cin>>w;
        width.push_back({w,i});
    }
    for(int i=1;i<=m;i++){
        cin>>bxl[i];
    }
    sort(width.begin(),width.end(),greater<>());
    multiset<int> s;
    for(auto[w,idx]:width){
        if(idx>0){
            s.insert(bxl[idx]);
        }
        else{
            auto it=s.lower_bound(chl[-idx]);
            if(it!=s.end()){
                s.erase(it);
            }
            else{
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
}