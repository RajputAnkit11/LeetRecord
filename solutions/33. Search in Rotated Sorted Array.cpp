class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
​
        while(l<=r){
            int mid = l+ (r-l)/2;
​
            if(nums[mid] == target) return mid;
​
            // step 1: first find which side is sorted - left or right 
            // step 2: then find target exist in sorted side or not
            // step 3: reduce the array accordingly
​
            if(nums[l] <= nums[mid]){ // if left is sorted
                if(target >= nums[l] and target <= nums[mid]){ // target resides inside sorted side
                    r = mid-1;
                }
                else{ // target resides inside non-sorted side
                    l = mid+1;
                }
            }
            else if(nums[r] >= nums[mid]){ // if right is sorted
                if(target >= nums[mid] and target <= nums[r]){ // target resides inside sorted side
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
        }
​
        return -1;
    }
};
