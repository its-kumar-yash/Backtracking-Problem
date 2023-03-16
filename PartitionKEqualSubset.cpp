//Given an integer array a[ ] of N elements and an integer K, the task is to check if the array a[ ] could be divided into K non-empty subsets with equal sum of elements.
// Note: All elements of this array should be part of exactly one partition.

//Amazon

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool solve(int idx, int a[], int n, vector<int> &sums, int k, int ssf){
        
        //base case
        if(idx == n){
            if(ssf == k){
                for(int i = 0; i < k - 1; i++){
                    //check if all sums are equal or not
                    if(sums[i] != sums[i + 1]){
                        return false;
                    }
                }
                return true;
            }
            return false;
        }
        
        
        //possible options
        // - either existing non empty set
        // - new set
        for(int j = 0; j < k; j++){
            //if set is non empty
            if(sums[j] > 0){
                sums[j] += a[idx];
                if(solve(idx + 1, a, n, sums, k, ssf)){
                    return true;
                }
                //backtrack
                sums[j] -= a[idx];
            }
            //if set is empty
            else{
                sums[j] += a[idx];
                if(solve(idx + 1, a, n, sums, k, ssf + 1)){
                    return true;
                }
                //backtrack
                sums[j] -= a[idx];
                break;
            }
        }
        
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {   
        //in sum array
        //each index represent the sum of kth partition
        vector<int> sums(k, 0);
        
        //{idx, arr, n, sums, k , set so far}
        return solve(0, a, n, sums, k , 0);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends