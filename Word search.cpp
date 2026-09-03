#include <iostream>
#include <vector>
using namespace std;

bool exist(vector<vector<char>>& board, string word) {
    int n=board.size();
    int m=board[0].size();
    bool b=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==word[0]){
                if(dfs(board,i,j,n,m,word,1)) return true;
            }
            
        }
    }
    return false;
}
bool dfs(vector<vector<char>> &board,int i,int j,int n,int m,string word,int idx){
    if(idx==word.length()){
        return true;
    }
    char c=board[i][j];
    board[i][j]='_';
    int diff[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    bool b=false;
    for(int k=0;k<4;k++){
        int ar=i+diff[k][0];
        int ac=j+diff[k][1];
        if(ar>=0 && ac>=0 && ar<n && ac<m && word[idx]==board[ar][ac]){
            if(dfs(board,ar,ac,n,m,word,idx+1)){
                return true;
            }
        }
    }
    board[i][j]=c;
    return false;
}