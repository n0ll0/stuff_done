#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

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
            int height = h[dq.back()];
            dq.pop_back();
            int width = dq.empty() ? i : i - dq.back() - 1;
            max_area = max(max_area, min(width, height) * min(width, height));
        }
        dq.push_back(i);
    }
    while (!dq.empty()) {
        int height = h[dq.back()];
        dq.pop_back();
        int width = dq.empty() ? n : n - dq.back() - 1;
        max_area = max(max_area, min(width, height) * min(width, height));
    }
    int side_length = 0;
    while (max_area > side_length * side_length) {
        side_length++;
    }
    cout << side_length << endl;

    return 0;
}