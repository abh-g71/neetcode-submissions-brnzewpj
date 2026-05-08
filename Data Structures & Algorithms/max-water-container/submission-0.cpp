class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size()-1;
        int ans = 0;

        while(l < r){
            int maxi = max(heights[l],heights[r]);
            if(heights[l]<=heights[r]){
                ans = max(ans,heights[l] * (r-l));
                l++;
            }
            if(heights[l]>heights[r]){
                ans = max(ans,heights[r] * (r-l));
                r--;
            }
        }
        return ans;
    }
};
