class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int mini = prices[0];

        for(int i = 0  ; i < n ; i++){
            if(mini < prices[i]){
                ans = max(ans,prices[i]-mini);
            }else{
                mini = prices[i];
            }
        }
        return ans;
    }
};
