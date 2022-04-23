#pragma once
using namespace std;

class Complex {
private:
    double Im, Re, module;
public:
    // --- constructors ---
    Complex() {};
    Complex(double a) {
        Re = a;
        Im = 0;
    }
    Complex(double a, double b) {
        Re = a;
        Im = b;
    }

    // --- operators ---
    Complex operator *(double f);
    Complex operator *(Complex c);
    Complex operator +(Complex c);
    operator double();

    // --- methods ---
    void display();
};

class Stack {
private:
    int n; // current size
    int maxn; // max size
    int *arr; //указатель на массив неопр. размера
public:
    // --- constructors ---
    Stack() {}; // default
    Stack(int t) { // max n
        arr = new int[t]();
        maxn = t;
        n = -1;
    };

    // --- operators ---
    Stack operator << (int num); // push
    Stack operator >> (int times); // pop

    // --- methods ---
    bool push(int);
    bool pop();
    bool empty();
    void show();
};