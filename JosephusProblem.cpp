// Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.
// After each operation, the count will start from k+1th person. The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle, you are the last one remaining and survive.

//Amazon Microsoft

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    int josephus(int n, int k)
    {
       //base case
       if(n == 1){
           return 1; // if one person remains then he is the survivor
       }
       //after fisrt kill, calculate the ans from remaining n - 1 persons
       int x = josephus(n - 1, k);
       
       //transform the ans you get
       int  y = (x + k) % n;
       
       return (y == 0) ? n : y;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends