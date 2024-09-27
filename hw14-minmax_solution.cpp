#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the minimum and maximum of a vector using divide and conquer
std::vector<int> findMinMax(const std::vector<int>& nums, int left, int right) {
    if (left == right) {
        // Only one element
        return { nums[left], nums[left] };
    }

    if (right == left + 1) {
        // Two elements
        if (nums[left] < nums[right]) {
            return { nums[left], nums[right] };
        }
        else {
            return { nums[right], nums[left] };
        }
    }

    // Divide the array into two halves
    int mid = left + (right - left) / 2;

    std::vector<int> leftMinMax = findMinMax(nums, left, mid);
    std::vector<int> rightMinMax = findMinMax(nums, mid + 1, right);

    // Combine the results
    int minVal = std::min(leftMinMax[0], rightMinMax[0]);
    int maxVal = std::max(leftMinMax[1], rightMinMax[1]);

    return { minVal, maxVal };
}

int main() {
    std::vector<int> nums = { 3, 5, 1, 8, 2, 7, 6, 4 };
    std::vector<int> result = findMinMax(nums, 0, nums.size() - 1);

    std::cout << "Minimum: " << result[0] << std::endl;
    std::cout << "Maximum: " << result[1] << std::endl;

    return 0;
}
