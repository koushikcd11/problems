#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string str;
    cin>>str;
    int pos=n-1;
    while(m--){
        int op,val;
        cin>>op>>val;
        val%=n;
        if(op==1){
            pos-=val;
            if(pos<0)pos+=n;
        }
        else{
            cout<<str[(pos+val)%n]<<endl;
        }
    }
}