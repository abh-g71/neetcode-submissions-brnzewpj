class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int>st(nums.begin(),nums.end());
        int ans = 1;
        

        if(nums.empty()) return 0;

        int count =1;
       for(int i = 0 ;i < n ; i++){
        int x = nums[i];
        if(st.find(x-1) == st.end()){

            while(st.find(x+1) != st.end()){
                count++;
                x++;
            }
        }
        ans = max(ans,count);
        count=1;
       }
        ans = max(count,ans);
        return ans;
    }
};
