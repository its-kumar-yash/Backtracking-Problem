//Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
//Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

// Expected Time Complexity: O((3N^2)).
// Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths

//Amazon Microsoft

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>> &m, int row, int col, string psf, vector<vector<bool>> &visited, vector<string> &ans, int n){
        
        //base case
        if(row == n - 1 && col == n - 1){
            ans.push_back(psf);
            return;
        }
        
        
        if(row < 0 || row >= n || col < 0 || col >= n || visited[row][col] == 1 || m[row][col] == 0){
            return;
        }
        
        visited[row][col] = 1;
        solve(m, row + 1, col, psf + "D", visited, ans, n); //Down
        solve(m, row, col - 1, psf + "L", visited, ans, n); //Left
        solve(m, row, col + 1, psf + "R", visited, ans, n); //Right
        solve(m, row - 1, col, psf + "U", visited, ans, n); //Upper
        visited[row][col] = 0; // backtracking
        
        
    }
    
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0] == 0 || m[n - 1][n - 1] == 0){
            return {"-1"};
        }
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        string psf = "";
        int row = 0, col = 0;
        
        
        solve(m, row, col, psf, visited, ans, n);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends