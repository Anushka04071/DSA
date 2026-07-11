#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
        // Step 1: Sort the array to handle duplicates and enable two-pointer logic
        std::sort(nums.begin(), nums.end());
        
        // Step 2: Iterate through the array to fix the first element
        for (int i = 0; i < n - 2; ++i) {
            // Optimization: If the current number is positive, the sum cannot be 0
            if (nums[i] > 0) break;
            
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Step 3: Use two pointers for the remaining subarray
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the second element
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicates for the third element
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    // Move both pointers inward
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++; // Sum is too small; move left pointer rightward
                } 
                else {
                    right--; // Sum is too large; move right pointer leftward
                }
            }
        }
        return result;
    }
};
