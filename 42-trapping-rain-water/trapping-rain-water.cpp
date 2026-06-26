class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = 0;
        int rmax = 0;

        int l =0;
        int r =height.size()-1;
        int ans = 0;

        while(l <= r) {

            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if(lmax < rmax){
                ans+= lmax - height[l];
                l++;
            }
                

            else {
                ans+= rmax - height[r];
                r--;
            }
            

        }
        return ans;


        // int n = height.size();
        // vector<int> prefix(n, 0);
        // vector<int> suffix(n, 0);
        // int total =0;

        // prefix[0] = height[0];
        // suffix[n-1]= height[n-1];

        // for(int i =1; i<n; i++) {
        //     prefix[i] = max(prefix[i-1],height[i]);
        // }

        // for(int i =n-2; i>= 0; i--) {
        //     suffix[i] = max(suffix[i+1], height[i]);
        // }

        // for(int i=0; i<n; i++) {
        //     int leftM= prefix[i];
        //     int rightM= suffix[i];

        //     if(height[i] <leftM && height[i] < rightM)
        //         total += min(leftM, rightM) - height[i];

        // }
        // return total;
    }
};