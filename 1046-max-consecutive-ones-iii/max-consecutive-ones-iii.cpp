class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int count = 0;
        int maxi = 0;
        int n = nums.size();

        for(int right =0; right<n; right++) {
            if(nums[right] == 0)
                count++;
            
            while(count>k) {
                if(nums[left] ==0) {
                    count--;
                }
                left++;
            }
            maxi = max(maxi, right-left+1);
        }
        return maxi;
    }
};