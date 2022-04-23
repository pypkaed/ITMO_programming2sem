#include <iostream>
#include "overloading.h"

using namespace std;

int main() {
    Complex c(1, 2), c2(3, 4);
    c.display();
    c = c + c2;
    c.display();
    c = c * 3.0;
    c.display();
    c = c * c2;
    c.display();
    cout << double(c) << '\n' << '\n';
Stack s(5);
s << 2;
s << 6;
s.show();
s >> 1;
s.show();

    return 0;
}