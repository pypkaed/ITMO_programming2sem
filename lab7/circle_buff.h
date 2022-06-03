#pragma once
#include <iostream>
#include <iterator>

template<typename T>
class Circle_buff {
private:
    T *arr;
    int capacity;
    int curr_size;
    int front, rear;
public:
    explicit Circle_buff(int capacity_) {
        arr = new T[capacity_];
        capacity = capacity_;
        curr_size = 0;
        front = rear = 0;
    }
    Circle_buff(const Circle_buff& copy_buff) {
        capacity = copy_buff.capacity;
        curr_size = copy_buff.curr_size;
        arr = copy_buff.arr;
    }
    ~Circle_buff() { delete[] arr; }

    // --- ITERATOR ---
    class Iterator : public std::iterator<std::random_access_iterator_tag, T> {
    private:
        T *pointer;
    public:
        Iterator() : pointer{nullptr} {}
        explicit Iterator(T* pos) {
            pointer = pos;
        }
        ~Iterator() = default;

        T& operator* () { return *pointer; }
        T* operator-> () { return pointer; }
        Iterator& operator++ () {
            pointer++;
            return *this;
        }
        Iterator& operator-- () {
            pointer--;
            return *this;
        }
        Iterator& operator- (const int n) {
            pointer -= n;
            return *this;
        }
        Iterator& operator+ (const int n) {
            pointer += n;
            return *this;
        }
        Iterator& operator- (const Iterator& n) {
            pointer -= n;
            return *this;
        }
        Iterator& operator+ (const Iterator& n) {
            pointer += n;
            return *this;
        }
        bool operator== (const Iterator& iterator) {
            return pointer == iterator.pointer;
        }
        bool operator!= (const Iterator& iterator) {
            return pointer != iterator.pointer;
        }
        bool operator> (const Iterator& iterator) {
            return pointer > iterator.pointer;
        }
        bool operator< (const Iterator& iterator) {
            return pointer < iterator.pointer;
        }
        bool operator>= (const Iterator& iterator) {
            return pointer >= iterator.pointer;
        }
        bool operator<= (const Iterator& iterator) {
            return pointer <= iterator.pointer;
        }
    };

    T& operator [] (const int &index) {
        int tmp = front + index;
        if (tmp > capacity)
            tmp -= capacity + 1;
        return arr[tmp];
    }
    Iterator begin() {
        return Iterator(arr);
    }
    Iterator end() {
        return Iterator(arr + capacity);
    }

    bool empty() {
        return (curr_size == 0);
    };
    void show() {
        if (empty()) {
            std::cout << "Empty\n";
            return;
        }
        for (auto i = front; i != rear; i++) {

            std::cout << arr[i] << " ";
            if (i == capacity)
                i = -1;
        }
        std::cout << "\n";
    };
    int Capacity() { return capacity; }
    int size() { return curr_size; }

    void push_back(const T &element) {
        if (curr_size < capacity) {
            arr[rear++] = element;
            curr_size++;
            return;
        }

        arr[rear] = element;
        if (curr_size < capacity)
            curr_size++;

        if (front == capacity)
            front = 0;
        else front++;
        if (rear == capacity)
            rear = 0;
        else rear++;
    }
    void push_front(const T &element) {
        if (curr_size < capacity) {
            if (front == 0)
                front = capacity;
            else
                front--;
            arr[front] = element;
            if (curr_size < capacity)
                curr_size++;
            return;
        }

        T tmp = arr[rear];
        if (rear == 0)
            rear = capacity;
        else
            rear--;
        arr[rear] = tmp;
        if (front == 0)
            front = capacity;
        else
            front--;
        arr[front] = element;
        if (curr_size < capacity)
            curr_size++;
    }
    void push(const T &element, const int& index) {
        int tmp = front + index;
        if (tmp > capacity)
            tmp -= capacity + 1;
        arr[tmp] = element;
    }
    void resize(const int& new_size) {
        if (new_size == capacity) return;
        T* tmp_arr = new T[new_size];
        if (new_size > capacity) {
            int curr = 0;
            for (int i = front; i != rear; i++, curr++) {
                tmp_arr[curr] = arr[i];
                if (i == capacity)
                    i = -1;
            }
            front = 0;
            rear = curr;
            arr = tmp_arr;
            capacity = new_size;
        }
        else {
            int curr = 0;
            for (int i = front; i != rear && curr != new_size; i++, curr++) {
                tmp_arr[curr] = arr[i];
                if (i == capacity)
                    i = -1;
            }
            front = 0;
            rear = curr;
            arr = tmp_arr;
            capacity = new_size;
        }
    }
};