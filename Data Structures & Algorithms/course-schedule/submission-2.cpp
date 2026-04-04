class Solution {
public:
    bool dfs(int src,vector<vector<int>> &adj,vector<bool> &vis,vector<bool> &recStack){
        if(recStack[src]) return true;

        if(vis[src]) return false;

        vis[src] = true;
        recStack[src] = true;

            for(auto neigh : adj[src]){
                
                    if(dfs(neigh,adj,vis,recStack)){
                        return true;
                    }
            }
            recStack[src] = false;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            
        }

        vector<bool>vis(V,false);
        vector<bool>recStack(V,false);

        for(int i = 0 ; i < V ;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,recStack)){
                    cout<<"cycle exist";
                    return false;
                }
            }
        }
        return true;
    }
};
