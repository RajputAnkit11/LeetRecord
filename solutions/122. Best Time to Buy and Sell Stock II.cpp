        }
        
        return dp[0][1];
        */
        
        /* space optimization - 1
        int n = prices.size();
        vector<int> ahead (2,0);
        vector<int> cur(2,0);
        ahead[0] = ahead[1] = 0;
​
        int profit;
        for(int ind= n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                if(buy==0){// We can buy the stock
                    profit = max(0+ahead[0], -prices[ind] + ahead[1]);
                }
​
                if(buy==1){// We can sell the stock
                    profit = max(0+ahead[1], prices[ind] + ahead[0]);
                }
                cur[buy]  = profit;
            }
​
            ahead = cur;
        }
        return cur[0];
        */
        
        // space optimization - 2
        int n = prices.size();
        int aheadNotBuy = 0, aheadBuy = 0;
        int curNotBuy, curBuy;
        
        for(int i= n-1; i>=0; i--){
            curNotBuy = max( prices[i] + aheadBuy, aheadNotBuy );
            curBuy = max( -prices[i] + aheadNotBuy, aheadBuy );
            
            aheadNotBuy = curNotBuy;
            aheadBuy = curBuy;
        }
        return aheadBuy;
    }
    
};
