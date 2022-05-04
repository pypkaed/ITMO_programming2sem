#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <set>
#include <string>
#include "algos.h"
// 6 варик: all_of, is_partitioned, find_backward

template<typename T>
bool predicate(T element) {
    return element <= 8;
}

int main() {
    // === VECTOR OF INTEGERS ===
    std::vector<int> a = {9, 8, 7, 6};
    std::cout << "--- vector check ---\n";
    std::cout << all_of(a.begin(), a.end(), predicate<int>);
    std::cout << "\n";
    std::cout << is_partitioned(a.begin(), a.end(), predicate<int>);
    std::cout << "\n";
    std::cout << a[a.size() - find_backward(a.end(), a.begin(), 6)];

    // === ARRAY OF STRINGS ===
//    std::array<std::string, 4> b = {"a", "s", "ass", "s"};
//    std::cout << "--- array check ---\n";
//    std::cout << all_of(b.begin(), b.end(), predicate<std::string>);
//    std::cout << "\n";
//    std::cout << is_partitioned(b.begin(), b.end(), predicate<std::string>);
//    std::cout << "\n";
//    std::cout << b[b.size() - find_backward(b.end(), b.begin(), "ass")];


    return 0;
}