class Solution {
public:
    long long solve(int i,int j,vector<int>& robot,vector<long long>& v,vector<vector<long long>> &dp){
        if(i == robot.size()) return 0;
        if(j == v.size()) return 10e16;
        if(dp[i][j] != -1) return dp[i][j];
        
        long long t = abs(robot[i]-v[j]) + solve(i+1,j+1,robot,v,dp);
        long long nt = solve(i,j+1,robot,v,dp);
        
        return dp[i][j] = min(t,nt);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = factory.size();
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        
        vector<long long> v;
        for(int i=0;i<n;i++){
            long long a = factory[i][0];
            long long b = factory[i][1];
            while(b--){
                v.push_back(a);
            }
        }
        
        vector<vector<long long>> dp(robot.size()+1,vector<long long>(v.size()+1,-1));
        solve(0,0,robot,v,dp);
        return dp[0][0];
    }
};
