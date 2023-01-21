#include <iostream>
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

    int max_side = 0;
    int left = 0, right = n - 1;
    while (left < right) {
        int width = right - left + 1;
        int height = min(h[left], h[right]);
        max_side = max(max_side, min(width, height));
        if (h[left] < h[right]) {
            left++;
        } else {
            right--;
        }
    }

    cout << max_side << endl;

    return 0;
}