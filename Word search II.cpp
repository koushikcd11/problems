#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    TrieNode* children[26] = {nullptr};
    string word = "";
};

class Solution {
public:
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string word : words) {
            TrieNode* curr = root;
            for (char ch : word) {
                int idx = ch - 'a';
                if (!curr->children[idx]) {
                    curr->children[idx] = new TrieNode();
                }
                curr = curr->children[idx];
            }
            curr->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node,vector<string>& result) {
        char ch = board[r][c];
        if (ch == '#' || !node->children[ch - 'a']) {
            return;
        }
        node = node->children[ch - 'a'];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";
        }
        board[r][c] = '#';
        int diff[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

        for (int i = 0; i < 4; i++) {
            int nr = r + diff[i][0];
            int nc = c + diff[i][1];

            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size()) {
                dfs(board, nr, nc, node, result);
            }
        }
        board[r][c] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board,vector<string>& words) {
        vector<string> result;
        TrieNode* root = buildTrie(words);

        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, root, result);
            }
        }
        return result;
    }
};