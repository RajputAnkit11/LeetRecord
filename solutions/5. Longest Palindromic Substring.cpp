class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n];
        
        int start = 0,len = 0;
        
        for(int gap = 0;gap<n;gap++){
            for(int i=0,j=gap; j<n; i++,j++){
                if(gap == 0){
                    dp[i][j] = true;
                }
                else if(gap == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
                else{
                    if(s[i] == s[j] and dp[i+1][j-1] == true){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
                
                if(dp[i][j] == true){
                    len = gap + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, len);
    }
};
