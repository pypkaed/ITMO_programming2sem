#include "exception.h"

isEmptyException::isEmptyException() {
    Error = "Queue is empty!\n";
}

std::string isEmptyException::what() {
    return Error;
}

overflowException::overflowException() {
    Error = "Queue overflow!\n";
}

std::string overflowException::what() {
    return Error;
}
