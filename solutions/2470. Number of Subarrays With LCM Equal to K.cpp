class Solution {
public:
    int gcd(unsigned int a, unsigned int b)
    {
      if (b == 0)
        return a;
      return gcd(b, a % b);
    }
​
    int lcm(unsigned int a, unsigned int b)
    {
        return (a / gcd(a, b)) * b;
    }
    
    
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            int prev = nums[i];
            for(int j=i;j<n;j++){
                
                int curr = lcm(prev,nums[j]);
                if(curr == k){
                    cnt++;
                }
                prev = curr;
            }
        }
        
        return cnt;
    }
};
