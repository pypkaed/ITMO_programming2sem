#pragma once

class CPoint {
private:
    int p_x{0}, p_y{0};
public:
    CPoint() = default;
    CPoint(int x, int y) : p_x(x), p_y(y) {};
    ~CPoint() = default;

    bool operator >= (CPoint& compare) const {
        return (this->p_x >= compare.p_x && this->p_y >= compare.p_y);
    }
    bool operator <= (CPoint& compare) const {
        return (this->p_x <= compare.p_x && this->p_y <= compare.p_y);
    }
    bool operator == (CPoint& compare) const {
        return (this->p_x == compare.p_x && this->p_y == compare.p_y);
    }

    friend std::ostream& operator << (std::ostream& os, const CPoint& point) ;
};

std::ostream& operator << (std::ostream& os, const CPoint& point) {
    os << "(" << point.p_x << ", " << point.p_y << ")";
    return os;
}
