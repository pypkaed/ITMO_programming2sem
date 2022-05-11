#pragma once
#include <string>

class emptyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Queue is empty.";
    }
};

class overflowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Queue overflow.";
    }
};
