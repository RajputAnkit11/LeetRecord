class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();
        vector<int> xorsum(n,0);
        xorsum[0] = arr[0];
        
        for(int i=1;i<n;i++){
            xorsum[i] = xorsum[i-1]^arr[i]; 
        }
        
        vector<int> ans;
        
        for(auto &i : queries){
            int l = i[0];
            int r = i[1];
            
            if(l != 0) ans.push_back( xorsum[l-1] ^ xorsum[r] );
            else ans.push_back( xorsum[r] );
            
        }
        
        return ans;
    }
};
