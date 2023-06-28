#include <iostream>
#include <vector>
#include <algorithm>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** fourSum(int nums[], int n, int target, int& resultSize) {
    qsort(nums, n, sizeof(int), compare);
    int maxResultSize = n * (n - 1) * (n - 2) * (n - 3) / (4 * 3 * 2);
    int** result = new int*[maxResultSize];
    int count = 0;

    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue; // Skip duplicates
        }

        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue; // Skip duplicates
            }

            int left = j + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[j] + nums[left] + nums[right];

                if (currentSum == target) {
                    result[count] = new int[4];
                    result[count][0] = nums[i];
                    result[count][1] = nums[j];
                    result[count][2] = nums[left];
                    result[count][3] = nums[right];
                    count++;

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) {
                        left++; // Skip duplicates
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--; // Skip duplicates
                    }
                } else if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    resultSize = count;
    return result;
}

int main() {
    int nums[] = {1, 0, -1, 0, -2, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 0;
    int resultSize;

    int** result = fourSum(nums, n, target, resultSize);

    for (int i = 0; i < resultSize; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Clean up memory
    for (int i = 0; i < resultSize; i++) {
        delete[] result[i];
    }
    delete[] result;

    return 0;
}
