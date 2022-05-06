#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <string>
#include "algos.h"
#include "CPoint.h"
// 6 варик: all_of, is_partitioned, find_backward

CPoint compare_point(2, 4);

template<typename T>
bool predicate(T element) {
    return element <= compare_point;
}

int main() {
    // === VECTOR OF INTEGERS ===
//    std::vector<int> a = {9, 8, 7, 6};
//    std::cout << "--- vector check ---\n";
//    std::cout << all_of(a.begin(), a.end(), predicate<int>);
//    std::cout << "\n";
//    std::cout << is_partitioned(a.begin(), a.end(), predicate<int>);
//    std::cout << "\n";
//    std::cout << a[a.size() - find_backward(a.end(), a.begin(), 6)];

//     === ARRAY OF STRINGS ===
//    std::array<std::string, 4> b = {"a", "s", "ass", "s"};
//    std::cout << "--- array check ---\n";
//    std::cout << all_of(b.begin(), b.end(), predicate<std::string>);
//    std::cout << "\n";
//    std::cout << is_partitioned(b.begin(), b.end(), predicate<std::string>);
//    std::cout << "\n";
//    std::cout << b[b.size() - find_backward(b.end(), b.begin(), "ass")];

    // === VECTOR OF CPoints ===
    std::vector<CPoint> c;
    CPoint point1(1, 2);
    CPoint point2(2, 4);
    c.push_back(point1); c.push_back(point2);
    std::cout << "--- vector of user class check ---\n";
    std::cout << all_of(c.begin(), c.end(), predicate<CPoint>);
    std::cout << "\n";
    std::cout << is_partitioned(c.begin(), c.end(), predicate<CPoint>);
    std::cout << "\n";
    std::cout << c[c.size() - find_backward(c.end(), c.begin(), compare_point)];

    return 0;
}
