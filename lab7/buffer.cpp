#include "circle_buff.h"
#include <algorithm>

int main() {
    Circle_buff<int> buf(5);

    buf.push_front(1);
    buf.show();
    buf.push_front(2);
    buf.show();
    buf.push_front(3);
    buf.show();
    buf.push_front(4);
    buf.show();
    buf.push_front(5);
    buf.show();
    buf.push_front(6);
    buf.show();
    buf.push_front(7);
    buf.show();

    buf.push_back(8);
    buf.show();
    buf.push_back(9);
    buf.show();
    buf.push_back(10);
    buf.show();

    buf[3] = 11;
    buf.push(12, 2);
    buf.show();

    buf.resize(15);
    buf.show();
    buf.push_back(13);
    buf.show();
    buf.resize(4);
    buf.show();
    buf.push_back(14);
    buf.show();
    buf.push_front(15);
    buf.show();
    buf.pop_front();
    buf.show();
    buf.pop_back();
    buf.show();
    buf.push_back(16);
    buf.show();

    for_each(buf.begin(), buf.end(), [](const int &n) { std::cout << n << " "; });

    return 0;
}