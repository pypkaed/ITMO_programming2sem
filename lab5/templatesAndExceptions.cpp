// 3: C, G
// C: меняет значения двух переменных одного типа местами (swap)
// парам шаблона: тип переменных
// G: очередь из макс N элементов типа T: int N, class T
// exceptions: переполнение очереди. изъятие элем из пустой очереди
#include <iostream>
#include "templates.h"


int main() {
    // testing the template function (swap)
    int a = 0, b = 124;
    std::cout << "before: " << a << ", " << b << '\n';
    swap(a, b);
    std::cout << "after: " << a << ", " << b << '\n';
    char *c = "first", *d = "second";
    std::cout << "before: " << c << ", " << d << '\n';
    swap<char*>(c, d);
    std::cout << "after: " << c << ", " << d << '\n';

    // testing the template class (queue)
    myQueue<int, 5> Q;
    myQueue<char*, 2> U;
    Q.push(4);
    U.push(c);
    std::cout << Q.pop() << "\n";
    std::cout << U.pop() << "\n";
    std::cout << Q.pop() << "\n";
}