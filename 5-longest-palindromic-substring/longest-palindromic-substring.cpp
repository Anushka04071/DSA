#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLength = 1;

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            // Return the length of the found palindrome
            return right - left - 1;
        };

        for (int i = 0; i < s.length(); i++) {
            // Case 1: Odd length palindromes (e.g., "aba", center is 'b')
            int len1 = expandAroundCenter(i, i);
            
            // Case 2: Even length palindromes (e.g., "abba", center is between 'b' and 'b')
            int len2 = expandAroundCenter(i, i + 1);
            
            int len = std::max(len1, len2);
            
            // Update the maximum window indices if a longer palindrome is found
            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};
