class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;


        for(auto i : strs){
            string temp = i;
            sort(temp.begin(),temp.end());

            mp[temp].push_back(i);
        }

        for(auto &i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
