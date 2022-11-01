class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> greater(n,n),ans(n);
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                greater[i]=st.top();
            }
            
            st.push(i);
        }
        // for(auto i: greater){
        //     cout<<i<<" ";
        // }
        for(int i=0;i<n;i++){
            int l=greater[i]+1;
            
            while(l<n && nums[i]>=nums[l]){
                l=greater[l];
            }
            if(l>=n){
              ans[i]=-1;
            }
            else {
              ans[i]=nums[l];
            }
        }
        
        return ans;
    }
};
