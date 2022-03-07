#include <iostream>
#include <algorithm>
#include <string>
#include <map>

void comparator(std::string ch, int &first, int &second, int &count) {
    switch(ch[0]) {
        case '>':
            first++;
            break;
        case '<':
            second++;
            break;
        case '=':
            first++;
            second++;
            count++;
            break;
        default:
            std::cout << "wrong operator";
            break;
    }
}

int main() {
    std::string ch1, ch2, ch3;

    std::cin >> ch1 >> ch2 >> ch3;

    if (ch1 == ch2 && ch1 == "=") {
        std::string s = "abc";
        do {
            std::cout << s << "\n";
        } while(std::next_permutation(s.begin(), s.end()));
        return 0;
    }

    int a = 0;
    int b = 0;
    int c = 0;
    int count = 0;

    comparator(ch1, a, b, count);
    comparator(ch2, a, c, count);
    comparator(ch3, b, c, count);

    std::map<int, std::string> mp;

    if (count == 0) {
        mp[a] = "a";
        mp[b] = "b";
        mp[c] = "c";
        std::cout << mp[0] << mp[1] << mp[2];
        return 0;
    }

    mp[a] = "a";

    if (mp.find(b) != mp.end()) {
        mp[a] = "ab";
        mp[c] = "c";
    } else {
        mp[a] = "a";
        mp[b] = "bc";
    }

    std::string s, s_perm;

    if (mp[1].length() > 1) {
        s_perm = mp[1];
        s = mp[2];
        do {
            std::cout << s_perm + s << "\n";
        } while(std::next_permutation(s_perm.begin(), s_perm.end()));
        return 0;
    }

    s_perm = mp[2];
    s = mp[1];

    do {
        std::cout << s + s_perm << "\n";
    } while(std::next_permutation(s.begin(), s.end()));

    return 0;
}

