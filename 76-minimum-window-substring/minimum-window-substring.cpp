class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        int l = 0, r = 0;
        int count = 0;
        int minLen = INT_MAX;
        int sIdx = -1;

        int hash[256] = {0};

        // Store frequency of characters in t
        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        while (r < n) {

            if (hash[s[r]] > 0) {
                count++;
            }
            hash[s[r]]--;

            while (count == m) {

                // Update minimum window
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sIdx = l;
                }

                // Remove s[l]
                hash[s[l]]++;

                if (hash[s[l]] > 0) {
                    count--;
                }

                l++;
            }

            r++;
        }

        return sIdx == -1 ? "" : s.substr(sIdx, minLen);
    }
};