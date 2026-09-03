#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++){
        int h,t;
        cin>>h>>t;
        arr.push_back({h,t});
    }
    sort(arr.begin(),arr.end(),greater<>());
    int curr_max=0;
    vector<int> height,time;
    for(auto[ht,ti]:arr){
        if(curr_max<ti){
            time.push_back(ti);
            height.push_back(ht);
            curr_max=ti;
        }
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int query;
        cin>>query;
        cout<<height[upper_bound(time.begin(),time.end(),query)-time.begin()]<<endl;
    }
}