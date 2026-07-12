#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        // Sort the array to efficiently apply the two-pointer technique
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Initialize closest sum with a baseline value
        int closest_sum = nums[0] + nums[1] + nums[2];
        
        // Fix the first element of the triplet
        for (int i = 0; i < n - 2; ++i) {
            // Optimization: skip duplicate elements to avoid redundant processing
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = n - 1;
            
            // Move two pointers from opposite ends
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                
                // If an exact match is found, return it immediately
                if (current_sum == target) {
                    return current_sum;
                }
                
                // If current_sum is closer to the target, update closest_sum
                if (std::abs(current_sum - target) < std::abs(closest_sum - target)) {
                    closest_sum = current_sum;
                }
                
                // Shift pointers based on how the sum compares to the target
                if (current_sum < target) {
                    ++left; 
                } else {
                    --right;
                }
            }
        }
        
        return closest_sum;
    }
};
