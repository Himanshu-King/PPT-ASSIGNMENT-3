#include <iostream>

int singleNumber(int nums[], int n) {
    int result = 0;

    for (int i = 0; i < n; i++) {
        result ^= nums[i];
    }

    return result;
}

int main() {
    int nums[] = {2, 2, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int single = singleNumber(nums, n);

    std::cout << "Single number: " << single << std::endl;

    return 0;
}
