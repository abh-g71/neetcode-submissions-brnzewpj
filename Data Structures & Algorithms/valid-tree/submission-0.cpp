class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int valid = edges.size();
        if(valid != n-1){
            return false;
        }

        vector<vector<int>>adj(n);

        for(auto i : edges){
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n,false);

        queue<int>q;
        q.push(0);
        vis[0] = true;

        while(!q.empty()){
            int f = q.front();
            q.pop();

            for(auto nei : adj[f]){
                if(!vis[nei]){
                    vis[nei] = true;
                    q.push(nei);
                }
            }

        }
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
