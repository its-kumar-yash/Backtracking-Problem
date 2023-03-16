//The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
// Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens’ placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].

// Microsoft Amazon

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> originalChess;
    
    bool isSafe(vector<vector<int>> &board, int row, int col, int n){
        //now for same row check if any queen is present
        int i = row, j = col;
        while(j >= 0){
            if(board[i][j] == 1){
                return false;
            }
            j--;
        }
        
        //for left upper diagonal
        i = row, j = col;
        while(i >= 0 && j >= 0){
            if(board[i][j] == 1){
                return false;
            }
            i--;
            j--;
        }
        
        //condition3 - backward diagonal 
        i = row, j = col;
        while(i < n && j >= 0){
            if(board[i][j] == 1){
                return false;
            }
            i++;
            j--;
        }

        
        return true;
    }
    
    
    void solve(vector<int> &chessRow, int col, int n, vector<vector<int>> &board){
        //base case
        if(col == n){
            originalChess.push_back(chessRow);
            return;
        }
        
        //now check if placing a queen is safe in each row of every column??
        for(int row = 0; row < n; row++){
            if(isSafe(board , row, col, n)){
                
                chessRow.push_back(row + 1);
                board[row][col] = 1;
                
                solve(chessRow, col + 1, n, board);
                
                board[row][col] = 0; //Backtracking
                chessRow.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n, vector<int>(n , 0));
        vector<int> chessRow;
        
        solve(chessRow, 0, n, board);
        
        return originalChess;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends