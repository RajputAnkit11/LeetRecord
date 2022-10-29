class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // if we consider selling on ith day then we must buy on the 
        // min price before ith day i.e. [0...i-1]
        int profit = 0;
        int mn = prices[0];
        
        for(int i=1;i<prices.size();i++){
            int sell = prices[i] - mn;
            profit = max(profit,sell);
            
            mn = min(mn,prices[i]);
        }
        
        return profit;
    }
};
