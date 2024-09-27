#include <iostream>
#include <vector> // for moveZeros
#include <algorithm> // for maxZeroLength

using namespace std;

int f(int* n, int m) {
    *n = 10;
    m = 10;

    return *n + m;
}

void moveZeroes(vector<int>& nums) {
    int lastNonZeroFoundAt = 0; // Position to place the non-zero element
    // Move all non-zero elements to the beginning of the array
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) nums[lastNonZeroFoundAt++] = nums[i];
    }

    // Fill the rest of the array with zeros
    for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
        nums[i] = 0;
    }
}

int maxZeroLength(const vector<int>& nums, int n, int index, int currentCount = 0, int maxCount = 0) {
    // Base case: if we've reached the end of the array
    if (index == n) return max(currentCount, maxCount);

    // If the current element is 0, increment the current count
    if (nums[index] == 0) {
        currentCount++;
        maxCount = max(maxCount, currentCount);
    }
    else {
        // If the current element is not 0, reset the current count to 0
        currentCount = 0;
    }

    // Recurse for the next element
    return maxZeroLength(nums, n, index + 1, currentCount, maxCount);
}

int main()
{
    cout << "Hello World!";

    return 0;
}
