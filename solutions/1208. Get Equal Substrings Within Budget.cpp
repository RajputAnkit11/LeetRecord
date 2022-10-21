class Solution {
public:
    int largestSubArrayTargetSum(vector<int> &nums, int target){
        int n = nums.size();
        
        int ans = 0, sum = 0;
        int i=0, j=0;
        
        while(j<n){
            sum += nums[j];
            j++;
            while(sum>target){
                sum -= nums[i];
                i++;
            }
            if(sum <= target){
                ans = max(ans,j-i);    
            }
        }
        return ans;
    }
    
    int equalSubstring(string s, string t, int maxCost) {
        
        int n = s.length();
        
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            nums[i] = abs(s[i]-t[i]);
        }
        
        return largestSubArrayTargetSum(nums,maxCost);
    }
};
