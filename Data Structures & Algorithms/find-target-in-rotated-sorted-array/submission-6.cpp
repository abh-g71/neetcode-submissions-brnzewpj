class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0 ;
        int end = nums.size()-1;

        while(left <= end){
            int mid = left +(end-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            

           
            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target < nums[mid]){
                    end = mid-1;
                }
                else{
                left = mid+1;
            }
            }
            else{
                if(nums[mid] < target && nums[end] >= target){
                    left = mid+1;
                }else{
                    end = mid-1;
                }
            }

            
        }
        return -1;
    }
};
