class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int>freq1;
        unordered_map<int,int>freq2;
        if(s.size() != t.size()){
            return false;
        }
        for(auto i : s){
            freq1[i]++;
            
        }
        for(auto i : t){
            freq2[i]++;  
        }
        for(auto i : freq1){
            if(i.second != freq2[i.first]){
                return false;
            }
        }
        return true;
      
    }
};
