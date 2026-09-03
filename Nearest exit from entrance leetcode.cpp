#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int row=maze.size();
    int col=maze[0].size();
    queue<tuple<int,int,int>> q;
    q.push({entrance[0],entrance[1],0});
    maze[entrance[0]][entrance[1]] = '!';
    int diff[5]={0,-1,0,1,0};
    while(!q.empty()){
        auto[r,c,s]=q.front();
        q.pop();
        if((r==0 || r==row-1 || c==0 || c==col-1)&& maze[r][c]!='!'){
            return s;
        }
        for(int i=0;i<4;i++){
            int ar=r+diff[i],ac=c+diff[i+1];
            if(ar>=0 && ar<row && ac>=0 && ac<col && maze[ar][ac]=='.'){
                maze[ar][ac]='+';
                q.push({ar,ac,s+1});
            }
        }
    }
    return -1;
}