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
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        // 0 means cant buy, 1 means can buy 
        int canBuy = 1; 
        return helper(0,canBuy,prices,dp);
    }
};
