class Solution {
public:
    
    bool dfs(int node, vector<int>& vis,
             vector<vector<int>>& adj,
             string& ans) {

        vis[node] = 1;

        for (auto neigh : adj[node]) {

            if (vis[neigh] == 1)
                return true; // cycle

            if (vis[neigh] == 0) {
                if (dfs(neigh, vis, adj, ans))
                    return true;
            }
        }

        vis[node] = 2;
        ans += (node + 'a');

        return false;
    }

    string foreignDictionary(vector<string>& words) {

        unordered_set<char> chars;

        // Collect all characters
        for (auto& word : words) {
            for (char c : word) {
                chars.insert(c);
            }
        }

        vector<vector<int>> adj(26);

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {

            string& w1 = words[i];
            string& w2 = words[i + 1];

            int len = min(w1.size(), w2.size());

            bool found = false;

            for (int j = 0; j < len; j++) {

                if (w1[j] != w2[j]) {

                    adj[w1[j] - 'a'].push_back(w2[j] - 'a');

                    found = true;
                    break;
                }
            }

            // Invalid prefix case
            if (!found && w1.size() > w2.size()) {
                return "";
            }
        }

        vector<int> vis(26, 0);
        string ans;

        for (char c : chars) {

            if (vis[c - 'a'] == 0) {

                if (dfs(c - 'a', vis, adj, ans)) {
                    return "";
                }
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};