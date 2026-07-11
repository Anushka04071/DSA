class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(128, 0);
        int maxLen = 0;
        
        for (int l = 0, r = 0; r < s.length(); ++r) {
            ++count[s[r]];
            while (count[s[r]] > 1) {
                --count[s[l]];
                ++l;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
