#include <iostream>

int* plusOne(int digits[], int n, int& resultSize) {
    int carry = 1;

    for (int i = n - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
        
        if (carry == 0) {
            break;
        }
    }

    if (carry > 0) {
        resultSize = n + 1;
        int* result = new int[resultSize];
        result[0] = carry;
        for (int i = 0; i < n; i++) {
            result[i + 1] = digits[i];
        }
        return result;
    }

    resultSize = n;
    return digits;
}

int main() {
    int digits[] = {1, 2, 3};
    int n = sizeof(digits) / sizeof(digits[0]);

    std::cout << "Original number: ";
    for (int i = 0; i < n; i++) {
        std::cout << digits[i];
    }
    std::cout << std::endl;

    int resultSize = 0;
    int* result = plusOne(digits, n, resultSize);

    std::cout << "Incremented number: ";
    for (int i = 0; i < resultSize; i++) {
        std::cout << result[i];
    }
    std::cout << std::endl;


    return 0;
}
