//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if(i!=A.size()-1) cout << A[i]<< " ";
            else cout << A[i];
        }
        cout << endl;
    }
};



class Solution {
  public:
    //using visited set to avoid TLE
    //it will make sure that we do not made recursive calls
    // for same string again and again
    unordered_set<string> visited;

    //function to find the number of invalid parenthesis in the string
    //the size of the stack will represent the number of invalid parenthesis
    int getMin(string s){
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(ch == '('){
                st.push(ch);
            }
            else if( ch == ')'){
                if(st.size() == 0){
                    st.push(ch);
                }
                else if(st.top() == '('){
                    st.pop();
                }
                else if(st.top() == ')'){
                    st.push(ch);
                }
            }
        }
        
        return st.size();
        
    }
    
    
    void solve(string s, int minRemovalAllowed, vector<string> &ans){
        //edge case
        if(minRemovalAllowed < 0){
            return;
        }
        
        //base case
        //removal == 0
        if(minRemovalAllowed == 0){
            //int isValid = getMin(s);
            //also when string isValid
            if(getMin(s) == 0){
                ans.push_back(s);
            }
            
            return;
        }
        
        //for every char
        for(int i = 0; i < s.length(); i++){
            
            if(s[i] != ')' && s[i] != '('){
                continue;
            }
            
            //perform removal
            string left = s.substr(0, i);
            string right = s.substr(i + 1);
            //craete temp ans
            string tempAns = left + right;
            
            //check if this is already visited
            if(visited.find(tempAns) == visited.end()){
                visited.insert(tempAns);
                //is not already visited
                //make recursive call
                solve(tempAns, minRemovalAllowed - 1, ans);
            }
            
            
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        int minRemovalAllowed = getMin(s);
        
        solve(s, minRemovalAllowed , ans);

        sort(ans.begin(), ans.end());

        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        string s; 
        cin>>s;
        
        Solution obj;
        vector<string> res = obj.removeInvalidParentheses(s);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends