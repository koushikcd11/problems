#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    long long int count=0,temp=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]==i)count++;
    }
    count=(count*(count-1))/2;
    for(int i=1;i<=n;i++){
        if(arr[i]!=i && arr[arr[i]]==i)temp++;
    }
    temp/=2;
    cout<<count+temp<<endl;
}