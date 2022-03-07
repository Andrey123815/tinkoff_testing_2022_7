#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    int count = 0;
    std::cin >> n >> k;
    std::vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }

    do {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i] * (i + 1);
        }
        if (sum % k == 0) {
            ++count;
        }
    } while(std::next_permutation(arr.begin(), arr.end()));

    std::cout << count;
    return 0;
}
