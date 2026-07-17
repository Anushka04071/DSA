#include <vector>
#include <string>

class Solution {
private:
    // Lookup table for digit-to-letter mappings matching a phone keypad
    const std::vector<std::string> phoneMap = {
        "",     "",     "abc",  "def", 
        "ghi",  "jkl",  "mno",  "pqrs", 
        "tuv",  "wxyz"
    };

    void backtrack(const std::string& digits, int index, std::string& current, std::vector<std::string>& result) {
        // Base case: if the current combination is complete, save it
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get the letters corresponding to the current digit
        std::string letters = phoneMap[digits[index] - '0'];
        
        // Loop through all letters mapped to the current digit
        for (char letter : letters) {
            current.push_back(letter);             // Choose
            backtrack(digits, index + 1, current, result); // Recurse
            current.pop_back();                    // Unchoose (Backtrack)
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        
        // Handle empty input edge case
        if (digits.empty()) {
            return result;
        }
        
        std::string current = "";
        backtrack(digits, 0, current, result);
        return result;
    }
};
