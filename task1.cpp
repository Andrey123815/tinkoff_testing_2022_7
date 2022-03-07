#include <iostream>

int main () {
    int a, b, n;
    std::cin >> a >> b >> n;
    std::cout << (a > b / n ? "Yes" : "No");
    return 0;
}
