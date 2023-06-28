#include <iostream>
#include <algorithm>

bool canAttendMeetings(int intervals[][2], int length) {
    // Sort the intervals based on the start time
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (intervals[j][0] > intervals[j + 1][0]) {
                std::swap(intervals[j], intervals[j + 1]);
            }
        }
    }

    // Check if there is any overlap between consecutive meetings
    for (int i = 1; i < length; i++) {
        if (intervals[i][0] < intervals[i - 1][1]) {
            return false;
        }
    }

    return true;
}

int main() {
    int intervals[][2] = {{0, 30}, {5, 10}, {15, 20}};
    int length = sizeof(intervals) / sizeof(intervals[0]);

    bool canAttend = canAttendMeetings(intervals, length);

    std::cout << (canAttend ? "true" : "false") << std::endl;

    return 0;
}
