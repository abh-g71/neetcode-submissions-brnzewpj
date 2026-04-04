class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int n = piles.size();
        int res = INT_MAX;

        while(low <= high){
            int k = low + (high - low) /2;
            long long hours = 0;
            for(int i = 0 ; i < n ; i++){
                  hours += (piles[i] + k-1)/k; 
            }
            
            if(hours > h){
                low = k+1;
            }
            else{
                res = k;
                high = k-1;
            }
        }
        return res;
    }
};
