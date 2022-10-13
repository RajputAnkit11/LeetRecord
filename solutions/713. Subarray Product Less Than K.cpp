class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int start = 0, end = 0;
        long long int product = nums[0];
        int count = 0;
        
        while(start<n and end<n){
            if(product < k){
                end++;
                // if(end >= start){
                    count += end - start;
                // }
                
                if(end<n){
                    product *= nums[end];
                }
            }
            else{
                product /= nums[start];
                start++;
            }
        }
        
        return count;
    }
};
