class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> map;
        
        for(int i=0;i<n;i++){
            int temp = target - nums[i];
            
            if(map.count(temp)){
                vector<int> ans;
                ans.push_back(i);
                ans.push_back(map[temp]);
                return ans;
            }
            
            map[nums[i]] = i;
        }
        return {};
    }
};
