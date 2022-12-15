#include<bits/stdc++.h>
using namespace std;

void floodFill(vector<vector<int>> maze, int row, int col, string asf, vector<vector<bool>> visited){
    //if maze element went outside or has obstacles or already visited
    //handling negative base cases
    if(row < 0 || col < 0 || row == maze.size() || col == maze[0].size() || maze[row][col] == 1 || visited[row][col] == 1){
        return;
    }
    //target reach
    if(row == maze.size() - 1 && col == maze[0].size() - 1){
        cout<<"Target reach : " <<asf<<endl;
        return;
    }
    
    //moves and mark visited
    visited[row][col] = true;
    floodFill(maze, row - 1, col, asf + "t", visited);
    floodFill(maze, row, col - 1, asf + "l", visited);
    floodFill(maze, row + 1, col, asf + "d", visited);
    floodFill(maze, row, col + 1, asf + "r", visited);
    //remove visited after all moves
    visited[row][col] = false;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> maze = 
    {{0,0,0,0},
    {0,1,0,1},
    {0,1,0,0},
    {0,0,0,0}};

    vector<vector<bool>> visited(n, vector<bool>(n,false));
    floodFill(maze, 0, 0, "", visited);
    return 0;
}