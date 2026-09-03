#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    cout<<"Enter size of the array: ";
    cin>>n;
    int arr[n],dp[n];
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[i]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    for(int i=1;i<n;i++){
        m=max(dp[i-1],dp[i]);
    }
    cout<<m<<endl;
    return 0;
}