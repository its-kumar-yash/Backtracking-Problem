#include<bits/stdc++.h>
using namespace std;

bool isQueenSafe(vector<vector<int>> chess, int row, int col){
    //condition1
    for(int i = row - 1, j = col; i >= 0; i--){
        if(chess[i][j] == 1){
            return false;
        }
    }

    //condition2
    for(int i = row - 1, j = col - 1; i >= 0 && j <= 0; j--, i--){
        if(chess[i][j] == 1){
            return false;
        }
    }

    //condition3
    for(int i = row - 1, j = col + 1; i >= 0 && j < chess.size() ; j++, i--){
        if(chess[i][j] == 1){
            return false;
        }
    }


    return true;
}

void printNQueens(vector<vector<int>> chess, string ans, int row){

    if(row == chess.size()){
        cout<<ans<<endl;
        return;
    }

    for(int col = 0; col < chess.size(); col++){
        if(isQueenSafe(chess, row, col) == true){
            chess[row][col] = 1;
            printNQueens(chess, ans + to_string(row) + "-" + to_string(col) + ",", row + 1);
            chess[row][col] = 0;
        }
    }
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>> chess(n, vector<int> (n, 0));

    printNQueens(chess, "", 0);
    return 0;
}