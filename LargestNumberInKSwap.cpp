//Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.

//Amazom Microsoft Google Inc


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    
    void solve(string str, int k, string &maxi, int i){
        //target condition
        maxi = max(maxi, str);

        //base case        
        if(k == 0 || i == str.length()){
            return ;
        }
        
        
        //for every index we have n - 1 options to swap
        for(int j = i; j < str.length(); j++){
            //edge case
            //skip if
            if(j  == i){
                solve(str, k, maxi, i + 1);
            }
            
            //swap only if
            if(i != j && str[i] < str[j]){
                    
                swap(str[i], str[j]);
                    
                solve(str, k - 1, maxi, i + 1);
                    
                swap(str[i], str[j]);//backtracking
            }
        }
        
        
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {   
        string maxi = "";
        
        solve(str, k, maxi , 0);
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends