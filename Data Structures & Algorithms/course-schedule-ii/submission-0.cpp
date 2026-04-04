class Solution {
public: 
    bool dfs(int u, vector<vector<int>> &adj,vector<bool> &vis,vector<bool> &recStack,vector<int> &ans){
        
        if(recStack[u]) return true;
        if(vis[u]) return false;

        vis[u] = true;
        recStack[u] = true;

        for(auto neigh : adj[u]){
            if(dfs(neigh,adj,vis,recStack,ans)){
                return true;
            }
        }
        recStack[u] = false;
         ans.push_back(u);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[v].push_back(u);
        }

        vector<int>ans;
        vector<bool>vis(n,false);
        vector<bool>recStack(n,false);
        bool possible = true;

        for(int i = 0 ; i < n ; i++){
           
            if(!vis[i]){
                if(dfs(i,adj,vis,recStack,ans)){
                    possible = false;
                }
            }
        }
        if(possible){
            reverse(ans.begin(),ans.end());
            return ans;
        }
        return {};
    }
};