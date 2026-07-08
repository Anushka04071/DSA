#include <string>
#include <vector>

class Solution {
private:
    std::vector<std::vector<int>> memo;

    bool dfs(int i, int j, const std::string& s, const std::string& p) {
        // Base case: if pattern is fully consumed, string must also be fully consumed
        if (j == p.length()) {
            return i == s.length();
        }

        // Return cached result if already computed
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        // Check if the current characters match
        bool first_match = (i < s.length() && (p[j] == s[i] || p[j] == '.'));

        // Handle the wildcard character '*'
        if (j + 1 < p.length() && p[j + 1] == '*') {
            // Choice 1: Ignore the '*' and its preceding character (match 0 times)
            // Choice 2: Use the '*' if current characters match (move string pointer forward)
            memo[i][j] = dfs(i, j + 2, s, p) || (first_match && dfs(i + 1, j, s, p));
        } else {
            // Regular match without wildcard
            memo[i][j] = first_match && dfs(i + 1, j + 1, s, p);
        }

        return memo[i][j];
    }

public:
    bool isMatch(std::string s, std::string p) {
        // Initialize memoization matrix with -1 (unvisited)
        // Dimensions: (s.length() + 1) x (p.length() + 1)
        memo.assign(s.length() + 1, std::vector<int>(p.length() + 1, -1));
        return dfs(0, 0, s, p);
    }
};
