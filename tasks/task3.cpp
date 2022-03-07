#include <iostream>

int get_count_null(long n) {
    int count = 0;

    while(n % 10 == 0) {
        n /= 10;
        count++;
    }

    return count;
}

int main() {
    long n;

    std::cin >> n;

    std::cout << get_count_null(n);

    return 0;
}
