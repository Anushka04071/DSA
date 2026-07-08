#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            // Find the smaller height which acts as the bottleneck
            int current_height = std::min(height[left], height[right]);
            int current_width = right - left;
            
            // Calculate current area and update the maximum
            int current_area = current_height * current_width;
            max_water = std::max(max_water, current_area);
            
            // Move the pointer pointing to the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};
