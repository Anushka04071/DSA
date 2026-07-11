#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Base case: If only 1 row or string is shorter than numRows, no change needed
        if (numRows <= 1 || s.length() <= numRows) {
            return s;
        }
        
        // Use a vector of strings to represent each row
        std::vector<std::string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;
        
        // Iterate through each character in the string
        for (char c : s) {
            rows[currentRow] += c;
            
            // Reverse direction when hitting the top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move up or down based on direction flag
            currentRow += goingDown ? 1 : -1;
        }
        
        // Combine all row strings into the final result
        std::string result;
        for (const std::string& row : rows) {
            result += row;
        }
        
        return result;
    }
};
