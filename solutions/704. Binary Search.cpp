class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size()-1;
        int mid;
        
        while(left<=right){
            
            mid = left + (right-left)/2; //left mid
            
            if (target > nums[mid]) {
                left = mid + 1;
            } else if(target < nums[mid]) {
                right = mid-1; 
            }
            else{
                return mid;
            }
        }
        
        return -1;
    }
};
