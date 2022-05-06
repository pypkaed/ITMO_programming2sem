#pragma once
#include <exception>

template <typename iterator, typename type>
bool all_of(const iterator& begin, const iterator& end, bool (&predicate)(type)) {
    for (iterator curr = begin; curr != end; curr++) {
        if (!predicate(*curr))
            return false;
    }
    return true;
}

template <typename iterator, typename type>
bool is_partitioned(const iterator& begin, const iterator& end, bool (&predicate)(type)) {
    bool equal = true;
    iterator bend;
    for (iterator curr = begin + 1; equal; curr++) {
        if (predicate(*curr) != predicate(*(curr - 1))) {
            equal = false;
            bend = curr;
        }
    }
    for (iterator curr = bend; curr != end - 1; curr++) {
        if (predicate(*curr) != predicate(*(curr + 1))) {
            return false;
        }
    }
    return true;
}

template <typename iterator, typename element>
int find_backward(const iterator& end, const iterator& begin, element el) {
    int pos = 0;
    for (iterator curr = end; curr != begin; curr--) {
        if (*curr == el)
            return pos;
        pos++;
    }
    try {
        if (*begin == el) return pos;
        else throw (el);
    }
    catch(element el) { std::cout << "No element " << el << " found"; exit(1);}
}
