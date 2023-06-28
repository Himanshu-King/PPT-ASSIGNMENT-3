#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

int threeSumClosest(int nums[], int n, int target) {
    std::sort(nums, nums + n);
    int closestSum = INT_MAX;

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            if (std::abs(currentSum - target) < std::abs(closestSum - target)) {
                closestSum = currentSum;
            }

            if (currentSum < target) {
                left++;
            } else if (currentSum > target) {
                right--;
            } else {
                return target;
            }
        }
    }

    return closestSum;
}

int main() {
    int nums[] = {-1, 2, 1, -4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 1;

    int result = threeSumClosest(nums, n, target);
    std::cout << result << std::endl;

    return 0;
}
