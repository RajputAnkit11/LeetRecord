class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int,int> map;
        map[0] = -1;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int rem = sum % k;
            
            if(map.count(rem%k)){
                int subArrayLen = i - map[rem];
                if(subArrayLen >= 2) return true;
            }
            else map[rem%k] = i;
            
        }
        return false;
​
    }
};
