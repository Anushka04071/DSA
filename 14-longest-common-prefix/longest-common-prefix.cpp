#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        // Handle empty input edge case
        if (strs.empty()) return "";
        
        // Iterate through each character of the first string
        for (int i = 0; i < strs[0].length(); ++i) {
            char currentChar = strs[0][i];
            
            // Compare currentChar with the same position in all other strings
            for (int j = 1; j < strs.size(); ++j) {
                // If string j is shorter than current index or characters don't match
                if (i == strs[j].length() || strs[j][i] != currentChar) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};
