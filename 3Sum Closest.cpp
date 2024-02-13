#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int solution(std::vector<int>& arr, int x) {
    std::sort(arr.begin(), arr.end());
    int closestSum = INT_MAX;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = arr[i] + arr[left] + arr[right];
            if (std::abs(x - closestSum) > std::abs(x - currentSum)) {
                closestSum = currentSum;
            }

            if (currentSum < x) {
                left++;
            } else {
                right--;
            }
        }
    }
    return closestSum;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, -5};
    int x = 10;
    int result = solution(arr, x);
    std::cout << "Closest sum: " << result << std::endl;
    return 0;
}

