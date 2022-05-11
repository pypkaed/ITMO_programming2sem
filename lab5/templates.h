#pragma once
#include "exception.h"
#include <iostream>
// queue fix: push(5) pop(5) - should work and not exit
template<typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T, size_t N>
class myQueue {
private:
    T* arr;
    int back_id, front_id;
    int capacity, count;
public:
    myQueue() {
        arr = new T[N];
        capacity = N;
        back_id = 0;
        front_id = 1;
        count = 0;
    };
    ~myQueue() {
        delete[] arr;
    };
    void push(T);
    T pop();
    bool empty();
    bool full();
};

template<typename T, size_t N>
void myQueue<T, N>::push(T element) {
    if (full())
        throw overflowException();

    back_id = (back_id + 1) % capacity;
    arr[back_id] = element;
    count++;
}

template<typename T, size_t N>
T myQueue<T, N>::pop() {
    if (empty())
        throw emptyException();

    T key = arr[front_id];
    front_id = (front_id + 1) % capacity;
    count--;
    return key;
}

template<typename T, size_t N>
bool myQueue<T, N>::empty() {
    return (count == 0);
}

template<typename T, size_t N>
bool myQueue<T, N>::full() {
    return (count == capacity);
}

