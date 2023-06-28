#include <iostream>
#include <algorithm>

void nextPermutation(int nums[], int n) {
    int i = n - 2;

    // Find the first decreasing element from the right
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        int j = n - 1;
        // Find the smallest element greater than nums[i] in the subarray nums[i+1:]
        while (j >= 0 && nums[j] <= nums[i]) {
            j--;
        }

        // Swap nums[i] and nums[j]
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Reverse the subarray nums[i+1:] to get the next permutation
    std::reverse(nums + i + 1, nums + n);
}

int main() {
    int nums[] = {1, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);

    std::cout << "Current permutation: ";
    for (int i = 0; i < n; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    nextPermutation(nums, n);

    std::cout << "Next permutation: ";
    for (int i = 0; i < n; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
