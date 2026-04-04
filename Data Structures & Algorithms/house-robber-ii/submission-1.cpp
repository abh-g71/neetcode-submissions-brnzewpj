class Solution {
public:
    int solve(int i, int n, vector<int>& nums){
        
       int prev1 = 0;
       int prev2 = 0;

       for(int start  = i ; start <= n; start++){
        int pick = nums[start] + prev2;
        int notPick = prev1;

        int curr = max(pick,notPick);

        prev2 = prev1;
        prev1 = curr;
       }
        
       
       return prev1;

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];
        
        
        int x = solve(0,n-2,nums);
        int y = solve(1,n-1,nums);

        
        return max(x,y);

    }
};
