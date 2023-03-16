// Given a list of words, list of  single letters (might be repeating) and score of every character.

// Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).

// It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.

 

//TC - > 2^N
//SC - > 26 -> C


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<string>& words, vector<int>& freq, vector<int>& score, int idx){

        //base case
        if(idx == words.size()){
            return 0; // when you reach the last word
        }

        //word not included in the final set
        //recursive call to exclude the particular word
        int scoreNot = 0 + solve(words, freq, score, idx + 1);

        //word included
        int scoreWord = 0;
        string word = words[idx];
        bool flag = true; // true if include call can be made

        for(int i = 0; i < word.length(); i++){
            char ch = word[i];

            if(freq[ch - 'a'] == 0){
                flag = false; // when freq of letters become zero no more include calls can be made
            }

            freq[ch - 'a']--; //otherwise decrease the freq
            scoreWord += score[ch - 'a']; //add the score to the score word
        }

        int scoreYes = 0; // score in inclusive call
        if(flag){
            scoreYes = scoreWord + solve(words, freq, score, idx + 1);
        }

        //backtracking - by restoring the frequency
        for(int i = 0; i < word.length(); i++){
            char ch = word[i];
            freq[ch - 'a']++;
        }

        //return the score which ever is maximum
        return max(scoreNot, scoreYes);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);
        //create freq array
        for (auto &c : letters) {
            freq[c-'a']++;
        }
        
        return solve(words, freq, score, 0);
    }   
};



int main(){
    
    return 0;
}