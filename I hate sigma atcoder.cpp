#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> dist(200001,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long int s=0,t=0;
    for(int i=n-1;i>=0;i--){
        t-=dist[arr[i]];
        dist[arr[i]]=n-i;
        t+=n-i;
        s+=t;
    }
    cout<<s<<endl;
}