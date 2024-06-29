class Solution {
public:
    int searchInsert(vector<int>& nums, int x) {
        int l = 0;
        int r = nums.size()-1;
        
        // if(x<v[0]) return -1;
        int ans = -1;
        
        while(l<=r){
            int mid = (l+r)/2;
​
            if(nums[mid] > x){
                ans = mid;
                 r = mid-1;
            }
            else if(nums[mid] < x){
                l = mid+1;
            }
            else{
                return mid;
            }
        }
        
         return ans==-1 ? l : ans;
    }
};
