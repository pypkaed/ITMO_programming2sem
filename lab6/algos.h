#pragma once
#include <exception>

template <typename iterator, typename Func>
bool all_of(const iterator& begin, const iterator& end, Func predicate) {
    for (iterator curr = begin; curr != end; curr++) {
        if (!predicate(*curr))
            return false;
    }
    return true;
}

template <typename iterator, typename Func>
bool is_partitioned(const iterator& begin, const iterator& end, Func predicate) {
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
iterator find_backward(const iterator& begin, const iterator& end, element el) {
    for (iterator curr = end; curr != begin; curr--) {
        if (*curr == el)
            return curr;
    }

    if (*begin == el)
        return begin;

    return end;
}