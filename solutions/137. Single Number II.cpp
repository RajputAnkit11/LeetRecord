class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int bits[32] = {0};
        
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            
            for(int j =31;j>=0;j--){
                if( 1 & (x>>j)){
                    bits[j]++;
                    bits[j] %= 3;
                }
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<32;i++){
            // cout<<bits[i];
            if(bits[i] == 1){
                ans += 1<<i;
            }
        }
        
        return ans;
    }
};
