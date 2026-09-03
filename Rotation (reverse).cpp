#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    string str;
    cin>>str;
    int pos=0;
    while(m--) {
        int op, val;
        cin>>op>>val;
        val%=n;
        if (op==1) {
            pos=(pos+val)%n;
        }
        else{
            cout<<str[(pos+val)%n]<<endl;
        }
    }
}