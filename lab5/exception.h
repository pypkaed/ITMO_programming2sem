#pragma once
#include <string>

class baseException {
protected:
    std::string Error;
public:
    virtual std::string what() = 0;
};

class isEmptyException : public baseException {
public:
    isEmptyException();
    ~isEmptyException() = default;
    std::string what() override;
};

class overflowException : public baseException {
public:
    overflowException();
    ~overflowException() = default;
    std::string what() override;
};