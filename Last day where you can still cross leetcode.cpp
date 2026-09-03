#include <iostream>
#include <vector>
using namespace std;

int conv(int row,int col,int C){
    return row*C+col+1;
}

int find(vector<int> &ldr,int t){
    if(ldr[t]!=t){
        ldr[t]=find(ldr,ldr[t]);
    }
    return ldr[t];
}

void join(vector<int> &ldr,int l,int r){
    ldr[find(ldr,l)]=find(ldr,r);
}

int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    vector<int> ldr(row*col+2);
    vector<bool> water(row*col+2,false);
    for(int i=0;i<row*col+2;i++){
        ldr[i]=i;
    }
    int diff[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    int days=0;
    for(vector<int> cell:cells){
        int r=cell[0];
        int c=cell[1];
        r--,c--;
        water[conv(r,c,col)]=true;
        for(int i=0;i<8;i++){
            int ar=r+diff[i][0];
            int ac=c+diff[i][1];
            if(ar>=0 && ac>=0 && ar<row && ac<col && water[conv(ar,ac,col)]){
                join(ldr,conv(r,c,col),conv(ar,ac,col));
            }
        }
        if(c==0){
            join(ldr,0,conv(r,c,col));
        }
        else if(c==col-1){
            join(ldr,row*col+1,conv(r,c,col));
        }
        if(find(ldr,0)==find(ldr,row*col+1)){
            break;
        }
        days++;
    }
    return days;
}