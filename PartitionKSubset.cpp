#include<bits/stdc++.h>
using namespace std;

void solve(int idx, int n, int k, int ssf, vector<vector<int>> &ans){
    if(idx > n){
        if(ssf == k){
            for(auto i : ans){
                for(auto j : i){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
        return;
    }
    
    //possible options
    // - either existing non empty set
    // - new set
    for(int j = 0; j < ans.size(); j++){
        // if set is already filled 
        if(ans[j].size() > 0){
            ans[j].push_back(idx);
            solve(idx + 1, n, k, ssf, ans);
            ans[j].pop_back();
        }
        //empty set
        else{
            ans[j].push_back(idx);
            solve(idx + 1, n, k, ssf + 1, ans);
            ans[j].pop_back();
            break;
        }
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<vector<int>> ans;

    for(int i = 0; i < k; i++){
        ans.push_back({});
    }

    //{idx , n, k, setSoFar, ans}
    solve(1, n, k, 0,  ans);

    return 0;
}