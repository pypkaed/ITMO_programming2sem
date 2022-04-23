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
    swap(a, b);
    char *c = "first", *d = "second";
    swap<char*>(c, d);

    // testing the template class (queue)
    myQueue<int, 5> Q;
    myQueue<char*, 2> U;
    Q.push(4);
    U.push(c);
    std::cout << Q.pop() << "\n";
    std::cout << U.pop() << "\n";
    std::cout << Q.pop() << "\n";
}