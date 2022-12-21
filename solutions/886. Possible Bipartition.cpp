class Solution {
public:
    bool graphColor(vector<int> adj[], int n, int node, vector<int> &color){
        queue<int>q;
        q.push(node);
        color[node]=1;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int it:adj[cur]){
                if(color[it]==color[cur]){
                    return false;
                }
                if(color[it]==-1){
                    color[it]=1-color[cur];
                    q.push(it);
                }
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        vector<int>color(n+1,-1);
        int m=dislikes.size();
        for(int i=0;i<m;i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!graphColor(adj,i,n,color))
                    return false;
            }
        }
        return true;
    }
};
