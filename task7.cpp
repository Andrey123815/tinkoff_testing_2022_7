#include <iostream>
#include <vector>
#include <stack>

/*
 TESTS:

 4 3
 4 3 2 1
 ANSWER:
 4

 6 4
 4 3 2 1 5 6
 ANSWER:
 1

 6 2
 4 3 2 1 5 6
 ANSWER:
 6

 6 4
 4 3 2 1 5 6
 ANSWER:
 1

 10 4
 8 7 6 4 5 3 2 9 8 1
 ANSWER:
 28
 */

struct pair {
    int elem;
    int index;
};

void clear(std::stack<pair> &st) {
    while (!st.empty()) {
        st.pop();
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::stack<pair> st;

    std::vector<int> vec(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }

    int count_groups = 0;

    for (int base_elem = 0; base_elem < n; ++base_elem) {
        clear(st);
        auto stack_start_index = base_elem + 1;
        st.push({vec[base_elem], base_elem});

        while (!st.empty() && n - stack_start_index + st.size() >= k) {

            for (int i = stack_start_index; i < n; ++i) {
                if ((st.top().elem > vec[i] && st.size() != k - 1)) {
                    st.push({vec[i], i});
                } else if (st.top().elem > vec[i]) {
                    count_groups++;
                }
            }

            if (!st.empty()) {
                stack_start_index = st.top().index + 1;
                st.pop();
            } else {
                break;
            }
        }
    }

    std::cout << count_groups;

    return 0;
}
