#pragma once
#include <iostream>
using namespace std;

class Stack {
private:
    int n; // current size
    int maxn; // max size
    int *arr; //указатель на массив неопр. размера
public:
    // --- constructors ---
    Stack() {}; // default
    Stack(Stack &obj) : n(obj.size()), maxn(obj.max_size()), arr(nullptr) { // copy
        if (maxn) {
            arr = new int[maxn]();
            for (int i = 0; i < maxn; i++)
                arr[i] = obj.arr[i];
        }
    };
    Stack(int t) { // max n
        arr = new int[t]();
        maxn = t;
        n = -1;
    };

    // --- methods ---
    bool push(int);
    bool pop();
    int top();
    int size();
    bool empty();
    void show();
    int max_size();

    // --- menu ---
   static bool Menu();
};