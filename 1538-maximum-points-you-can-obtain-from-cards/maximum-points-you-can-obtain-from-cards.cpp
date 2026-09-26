class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        
        int sum = 0;
        int n = arr.size();

        for(int i = 0; i<k ; i++) {
            sum += arr[i];
        }
        int maxLen = sum;
        for(int i =1; i<=k ; i++) {
            sum = sum - arr[k-i] + arr[n-i];
            maxLen = max(maxLen, sum);
        }
        return maxLen;
    }
};