//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:

    void solve(int curr, int len, unordered_map<char, int> fmap, char oddChar, string asf, vector<string> &ans)
    {
        // base case
        if (curr > len)
        {
            // generate the rev of asf
            string rev = asf;
            reverse(rev.begin(), rev.end());

            string res = asf;

            if (oddChar != '\0')
            {
                res += oddChar;
            }

            res += rev;

            ans.push_back(res);

            return;
        }

        for (auto ch : fmap)
        {
            int freq = ch.second;
            if (freq > 0)
            {
                ch.second--;
                solve(curr + 1, len, fmap, oddChar, asf + ch.first, ans);
                ch.second++; // backtrack
            }
        }
    }

    vector<string> all_plaindromes(string s)
    {
        vector<string> ans;

        // step 1 - create a freq map of character in string
        unordered_map<char, int> fmap;
        for (char &ch : s)
        {
            fmap[ch]++;
        }

        // step 2 - half the freq of all char , count the no. of chracter with odd freq,
        // also find the new length of string formed
        int oddFreq = 0;
        char oddChar = '\0';
        int len = 0;

        for (auto i : fmap)
        {
            int freq = i.first;

            if (freq % 2 == 1)
            {
                oddChar = i.first;
                oddFreq++;
            }

            i.second = freq / 2;
            len += freq / 2;
        }

        if (oddFreq > 1)
        {
            return ans;
        }

        //{currChar, totalChar, oddChar, asf}
        solve(1, len, fmap, oddChar, "", ans);

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        Solution ob;
        vector<string> ans = ob.all_plaindromes(s);
        cout << "{ ";
        for (auto i : ans)
            cout << i << " ";
        cout << "}";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends