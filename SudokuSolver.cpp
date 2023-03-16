//Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.

//Amazon Microsoft Flipkart

#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    bool isSafe(int row, int col, int grid[N][N], int val){
        for(int i = 0; i < N; i++){
            //row check
            if(grid[row][i] == val){
                return false;
            }
            
            //col check
            if(grid[i][col] == val){
                return false;
            }
            
            //check 3*3 grid
            if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val){
                return false;
            }
            
        }
        
        return true;
    }
    
    
    
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int row = 0; row < N; row++){
            for(int col = 0; col < N; col++){
                //check cell empty
                if(grid[row][col] == 0){
                    //try all possible values in the cell (0 - 9)
                    for(int val = 0; val <= 9; val++){
                        //check ki value ko dalna possible h ki nhi
                        if(isSafe(row, col, grid, val)){
                            grid[row][col] = val;
                            
                            
                            if(SolveSudoku(grid) == true){
                                return true;
                            }
                            else{
                               //backtrack
                                grid[row][col] = 0; 
                            }
                            
                        }
                    }
                    //saari values check kr li
                    return false;
                }
            }
        }
        
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends