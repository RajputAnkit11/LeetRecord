class Solution {
public:
    int helper(int i,int canBuy, vector<int>&prices, vector<vector<int>>&dp){
        
        if(i == prices.size()){
            return 0;
        }
        
        if(dp[i][canBuy] != -1) return dp[i][canBuy];
        
        int profit = INT_MIN;
        if(canBuy == 1){
            // buying
            profit = max( -prices[i] + helper(i+1,0,prices,dp),
                          0 + helper(i+1,1,prices,dp) );
        }
        else{
            // selling
            profit = max( prices[i] + helper(i+1,1,prices,dp),
                          helper(i+1,0,prices,dp) );
        }
        
        return dp[i][canBuy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        // // 0 means cant buy, 1 means can buy 
        // int canBuy = 1; 
        // return helper(0,canBuy,prices,dp);
        
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        dp[n][0] = dp[n][1] = 0;
        
        for(int i=n-1;i>=0;i--){
            for(int canBuy=0;canBuy<=1;canBuy++){
                int profit = INT_MIN;
                if(canBuy){
                    profit = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
                }
                else{
                    profit = max(prices[i] + dp[i+1][1], dp[i+1][0]);
                }
                dp[i][canBuy] = profit;
            }
        }
        
        return dp[0][1];
    }
    
};
