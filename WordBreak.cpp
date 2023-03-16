//Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.

//Amazon Microsoft Google

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    bool solve(string &s,unordered_set<string> &dict, int idx){
        
        if(s.length() == idx){
            return true;
        }
        
        string tmp = "";
        
        for(int i = idx; i < s.length(); i++){
            tmp.push_back(s[i]);
            
            if(dict.find(tmp) != dict.end() ){
                if(solve(s, dict, i + 1)){
                    return true;
                }
            }
        }
        return false;
    }
    
    int wordBreak(string A, vector<string> &B) {
        unordered_set<string> dict;
        
        for(int i = 0; i < B.size(); i++){
            dict.insert(B[i]);
        }
        
        bool ans = solve(A, dict, 0);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends