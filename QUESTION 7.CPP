#include <iostream>
#include <string>

void addRange(std::string result[], int& count, int start, int end) {
    if (start == end) {
        result[count++] = std::to_string(start);
    } else {
        result[count++] = std::to_string(start) + "->" + std::to_string(end);
    }
}

void findMissingRanges(int nums[], int length, int lower, int upper, std::string result[], int& count) {
    int prev = lower - 1;  // Initialize the previous number as lower-1

    for (int i = 0; i <= length; i++) {
        int current = (i == length) ? upper + 1 : nums[i];  // Handle the case when i reaches length

        if (current - prev > 1) {
            addRange(result, count, prev + 1, current - 1);
        }

        prev = current;
    }
}

int main() {
    int nums[] = {0, 1, 3, 50, 75};
    int length = sizeof(nums) / sizeof(nums[0]);
    int lower = 0;
    int upper = 99;

    std::string result[100];
    int count = 0;

    findMissingRanges(nums, length, lower, upper, result, count);

    std::cout << "Missing Ranges:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << result[i] << std::endl;
    }

    return 0;
}
