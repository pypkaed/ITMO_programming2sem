#pragma once
#include "exception.h"
#include <iostream>

template<typename T>
void swap(T &a, T &b) {
    std::cout << "before: " << a << ", " << b << '\n';
    T temp = a;
    a = b;
    b = temp;
    std::cout << "after: " << a << ", " << b << '\n';
}

template<typename T, size_t N>
class myQueue {
private:
    T* arr;
    int back_id, front_id;
public:
    myQueue() {
        arr = new T[N];
        back_id = 0;
        front_id = 1;
    };
    ~myQueue() {
        delete[] arr;
    };
    void push(T);
    T pop();
    bool empty();
};

template<typename T, size_t N>
void myQueue<T, N>::push(T element) {
    if (back_id < N) {
        back_id++;
        arr[back_id] = element;
    }
    else
        throw overflowException();
}

template<typename T, size_t N>
T myQueue<T, N>::pop() {
    if (!empty()) {
        T key = arr[front_id];
        front_id++;
        return key;
    }
    else
        throw isEmptyException();
}

template<typename T, size_t N>
bool myQueue<T, N>::empty() {
    return (back_id < front_id);
}