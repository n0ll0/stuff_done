#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Read in the array of heights
    int h[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    // Initialize a deque to store the indices of the bars
    deque<int> dq;
    int max_area = 0;

    // Iterate through the array of heights
    for (int i = 0; i < n; i++) {
        // Pop elements from the back of the deque if they are no longer useful
        while (!dq.empty() && h[dq.back()] >= h[i]) {
            dq.pop_back();
        }

        // Push the current index onto the deque
        dq.push_back(i);

        // Calculate the area of the rectangle using the height at the index and the width
        int width = i - dq.front() + 1;
        max_area = max(max_area, (int) h[dq.front()] * width);
    }
    int ans = 0;
    for(; max_area > 0; max_area -= ans++) {}
    cout << ans-2 << endl;

    return 0;
}