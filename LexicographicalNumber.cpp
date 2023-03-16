// Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

// You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> ans;
    //function for dfs
    void solve(int i, int n){
        //base case
        if(i > n){
            return;
        }

        //push the ith number into ans
        ans.push_back(i);
        // make recursive call for its families(1 - 9)
        for(int j = 0; j < 10; j++){
            solve(10 * i + j, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        //make recursive call for first 1 - 9 Numbers
        for(int i = 1; i < 10; i++){
            solve(i, n);
        }

        return ans;
    }
};

int main(){
    
    return 0;
}