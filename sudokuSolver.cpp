#include <bits/stdc++.h>
using namespace std;

void displaySudoku(vector<vector<int>>&puzzle){
    for (int i = 0; i < puzzle.size(); i++){
        for (int j = 0; j < puzzle[0].size(); j++){
            cout << puzzle[i][j] << " ";
        }
        cout<<endl;
    }
}

bool isPossible(vector<vector<int>> puzzle, int row, int col, int val){
    // condition 1 - search in row
    for (int i = 0; i < puzzle.size(); i++){
        if (puzzle[i][col] == val){
            return false;
        }
    }
    // condition 2 - search in col
    for (int i = 0; i < puzzle[0].size(); i++){
        if (puzzle[row][i] == val){
            return false;
        }
    }
    // condition 3 - search in box
    int smi = row / 3 * 3;
    int smj = col / 3 * 3;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (puzzle[i + smi][j + smj] == val){
                return false;
            }
        }
    }

    return true;
}

void sudokuSolver(vector<vector<int>> &puzzle, int row, int col){
    if (row == puzzle.size()){   
        displaySudoku(puzzle);
        return;
    }

    // Next Pointers
    int nextRow = 0;
    int nextCol = 0;
    if (col < puzzle.size()){
        nextRow = row;
        nextCol = col + 1;
    }
    else{
        nextRow = row + 1;
        nextCol = 0;
    }

    if (puzzle[row][col] != 0){
        sudokuSolver(puzzle, nextRow, nextCol);
    }
    else{
        // possible options
        for (int i = 0; i <= 9; i++){
            if (isPossible(puzzle, row, col, i)){
                puzzle[row][col] = i;
                sudokuSolver(puzzle, nextRow, nextCol);
                puzzle[row][col] = 0;
            }
        }
    }
}


int main()
{

    vector<vector<int>> puzzle ={
        {
             {3, 0, 6, 5, 0, 8, 4, 0, 0},
             {5, 2, 0, 0, 0, 0, 0, 0, 0},
             {0, 8, 7, 0, 0, 0, 0, 3, 1},
             {0, 0, 3, 0, 1, 0, 0, 8, 0},
             {9, 0, 0, 8, 6, 3, 0, 0, 5},
             {0, 5, 0, 0, 9, 0, 6, 0, 0},
             {1, 3, 0, 0, 0, 0, 2, 5, 0},
             {0, 0, 0, 0, 0, 0, 0, 7, 4},
             {0, 0, 5, 2, 0, 6, 3, 0, 0}
        }
    };

    sudokuSolver(puzzle, 0, 0);
    return 0;
}