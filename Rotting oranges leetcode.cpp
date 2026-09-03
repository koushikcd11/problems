#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int row=grid.size();
    int col=grid[0].size();
    queue<pair<int,int>> q;
    int oranges=0,days=-1;   
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==2) q.push({i,j});
            if(grid[i][j]!=0) oranges++;
        }
    }
    if(oranges==0) return 0;
    int diff[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
    while(!q.empty()){
        int siz=q.size();
        oranges-=siz;
        while(siz--){
            auto[r,c]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int ar=r+diff[k][0];
                int ac=c+diff[k][1];
                if(ar>=0 && ar<row && ac>=0 && ac<col && grid[ar][ac]==1){
                    grid[ar][ac]=2;
                    q.push({ar,ac});
                }
            }
        }
        days++;
    }
    return oranges==0?days:-1;
}