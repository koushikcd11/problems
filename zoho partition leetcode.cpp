#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    string str;
    cin>>str;
    int c=str.length()-1,n=stoi(str);
    vector<int> res;
    
    for(char ch:str){
        int t=ch-'0';
        for(int i=0;i<t;i++){
            if(i<res.size()){
                res[i]+=pow(10,c);
            }
            else{
                res.push_back(pow(10,c));
            }
        }
        c--;
    }
    for(int i=0;i<res.size();i++){
        if(i>0)cout<<" + ";
        cout<<res[i];
    }
}