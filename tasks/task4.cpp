#include <iostream>
#include <vector>

const char BASE_SYMBOL = 'a';

int main() {
    int n = 0;
    std::cin >> n;

    std::vector<std::vector<char>> matrix_strings(n/2 + 1, std::vector<char>(n));

    for (int row = 0; row < n/2 + 1; ++row) {
        for (int i = 0; i < n/2 + 1; ++i) {
            matrix_strings[row][i] = (char(BASE_SYMBOL + abs(row-i)));
        }
        for (int end = n - 1, start = 0; start < n/2; end--, start++) {
            matrix_strings[row][end] = matrix_strings[row][start];
        }
    }

    for (int i = 0; i < n/2 + 1; ++i) {
        for (int j = 0 ; j < n; ++j) {
            std::cout << matrix_strings[i][j];
        }
        std::cout << "\n";
    }

    for (int i = n/2 - 1; i >= 0; --i) {
        for (int j = 0 ; j < n; ++j) {
            std::cout << matrix_strings[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}
