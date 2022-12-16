#include<bits/stdc++.h>
using namespace std;


void displayKnight(vector<vector<int>> chess){
    for(int i = 0; i < chess.size(); i++){
        for(int j = 0; j < chess.size(); j++){
            cout<<chess[i][j]<<" ";
        }
    }
}

void knightTour(vector<vector<int>> chess, int row, int col, int move){
    if(row < 0 || col < 0 || row >= chess.size() || col >= chess.size() || chess[row][col] > 0){
        return;
    }

    if(move == chess.size()*chess.size()){
        chess[row][col] = move;
        displayKnight(chess);
        chess[row][col] = 0;
        return;
    }
    
    chess[row][col] = move;
    knightTour(chess, row - 2, col + 1, move + 1);
    knightTour(chess, row - 1, col + 2, move + 1);
    knightTour(chess, row + 1, col + 2, move + 1);
    knightTour(chess, row + 2, col + 1, move + 1);
    knightTour(chess, row + 2, col - 1, move + 1);
    knightTour(chess, row + 1, col - 2, move + 1);
    knightTour(chess, row - 1, col - 2, move + 1);
    knightTour(chess, row - 2, col - 1, move + 1);
    chess[row][col] = 0;
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> chess(n, vector<int> (n, 0));

    knightTour(chess, 2, 3, 1);

    return 0;
}