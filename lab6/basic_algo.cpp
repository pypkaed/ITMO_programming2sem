#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "algos.h"
#include "CPoint.h"
// 6 варик: all_of, is_partitioned, find_backward

CPoint compare_point(2, 4);

int main() {
    // === VECTOR OF INTEGERS ===
        std::vector<int> a = {9, 8, 7, 6};
        std::cout << "--- vector of ints check ---\n";

        // --- all_of check (should return FALSE) ---
        std::cout << all_of(a.begin(), a.end(), [](int el) { // lambda function
            return el <= 6;
        });
        std::cout << "\n";

        // --- is_partitioned check (should return FALSE) ---
        std::cout << is_partitioned(a.begin(), a.end(), [](int el) {
            return el >= 6;
        });
        std::cout << "\n";

        // --- find_backward check (should return Not found) ---
        auto it1 = find_backward(a.begin(), a.end(), 2);
        if (it1 == a.end())
            std::cout << "Not found" << std::endl;
        else
            std::cout << *it1 << std::endl;

//     === ARRAY OF STRINGS ===
        std::array<std::string, 4> b = {"a", "s", "ass", "s"};
        std::cout << "--- array of strings check ---\n";

        // --- all_of check (should return FALSE) ---
        std::cout << all_of(b.begin(), b.end(), [](std::string el) {
            return el <= "as";
        });
        std::cout << "\n";

        // --- is_partitioned check (should return TRUE) ---
        std::cout << is_partitioned(b.begin(), b.end(), [](std::string el) {
            return el <= "as";
        });
        std::cout << "\n";

        // --- find_backward check (should return "ass") ---
        auto it2 = find_backward(b.begin(), b.end(), "ass");
        if (it2 == b.end())
            std::cout << "Not found" << std::endl;
        else
            std::cout << *it2 << std::endl;

    // === VECTOR OF CPoints ===
        std::vector<CPoint> c;
        CPoint point1(1, 2); CPoint point2(2, 4);
        c.push_back(point1);       c.push_back(point2);
        std::cout << "--- vector of user class check ---\n";

        // --- all_of check (should return TRUE) ---
        std::cout << all_of(c.begin(), c.end(), [](CPoint el) {
            return el <= compare_point;
        });

        // --- is_partitioned check (should return FALSE) ---
        std::cout << "\n";
        std::cout << is_partitioned(c.begin(), c.end(), [](CPoint el) {
            return el <= compare_point;
        });
        std::cout << "\n";

        // --- find_backward check (should return (2, 4)) ---
        auto it3 = find_backward(c.begin(), c.end(), compare_point);
        if (it3 == c.end())
            std::cout << "Not found" << std::endl;
        else
            std::cout << *it3 << std::endl;

    return 0;
}