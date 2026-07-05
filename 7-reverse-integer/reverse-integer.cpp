class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            
            // Check for overflow before multiplying by 10
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
                return 0;
            }
            
            ans = ans * 10 + pop;
        }
        
        return ans;
    }
};
