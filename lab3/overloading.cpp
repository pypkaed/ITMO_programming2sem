#include "overloading.h"
#include <cmath>
#include <iostream>

// --- 1: Complex ---

// --- operators ---
Complex Complex::operator *(double f) {
    Re *= f;
    return *this;
}
Complex Complex::operator *(Complex c) {
    return Complex(Re * c.Re - Im * c.Im, Re * c.Im + Im * c.Re);
}
Complex Complex::operator +(Complex c) {
    Re = (Re + c.Re);
    Im = (Im + c.Im);
    return *this;
}
Complex::operator double() {
    module = sqrt(Re * Re + Im * Im);
    return module;
}

// --- methods ---
void Complex::display() {
    cout << Re << " + " << Im << "i\n";
}

// --- 5: Stack ---

// --- methods ---
bool Stack::push(int pushed_element) {
    if (maxn == n + 1) return false;
    n++;
    arr[n] = pushed_element;
    return true;
}
bool Stack::empty() {
    return n < 0;
}
bool Stack::pop() {
    if (n < 0) return false;
    n--;
    return true;
}
void Stack::show() {
    for (int i = 0; i <= n; i++)
        cout << arr[i] << " ";
    cout << '\n';
}

// --- operators ---
Stack Stack::operator <<(int num) {
    this->push(num);
    return *this;
}
Stack Stack::operator >> (int times) {
    while (times != 0) {
        this->pop();
        times--;
    }
    return *this;
}
