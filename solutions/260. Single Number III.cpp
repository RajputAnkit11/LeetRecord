class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        long long int xr = 0;
        for(auto &i : nums){
            xr ^= i;
        }
        
        long long int lowestbit = xr & (~(xr - 1));
        
        vector<int> ans(2,0);
        for(auto &i : nums){
            
            if(i & lowestbit){
                ans[0] ^= i;
            }
            else{
                ans[1] ^= i;
            }
        }
        
​
        return ans;
    }
};
