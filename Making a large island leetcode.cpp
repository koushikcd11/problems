#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int diff[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int largestIsland(vector<vector<int>>&grid){
    int r=grid.size(),c=grid[0].size();
    int num=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==1){
                dfs(grid,i,j,r,c,++num);
            }
        }
    }
    vector<int>iscnt(num+1,0);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]!=0){
                iscnt[grid[i][j]]++;
            }
        }
    }
    int maxcnt=0;
    for(int i=2;i<=num;i++){
        maxcnt=max(maxcnt,iscnt[i]);
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==0){
                int max_c=1;
                set<int> dis;
                for(int k=0;k<4;k++){
                    int ar=diff[k][0]+i;
                    int ac=diff[k][1]+j;
                    if(ar>=0 && ac>=0 && ar<r && ac<c && grid[ar][ac]!=0){
                        dis.insert(grid[ar][ac]);
                    }
                }
                for(int val:dis){
                    max_c+=iscnt[val];
                }
                maxcnt=max(maxcnt,max_c);
            }
        }
    }
    return maxcnt;
}

void dfs(vector<vector<int>>&grid,int i,int j,int r,int c,int id){
    grid[i][j]=id;
    for(int k=0;k<4;k++){
        int ar=i+diff[k][0];
        int ac=j+diff[k][1];
        if(ar>=0 && ac>=0 && ar<r && ac<c && grid[ar][ac]==1){
            dfs(grid,ar,ac,r,c,id);
        }
    }
}