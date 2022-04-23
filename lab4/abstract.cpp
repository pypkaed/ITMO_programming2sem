#include "abstract.h"
#include <iostream>
using namespace std;

double Rectangle::square() {
    return sqrt(a.x * a.x + a.y * a.y) * sqrt(b.x * b.x + b.y * b.y);
}

double Parallelogram::square() {
    double sinA = sqrt(1 - ((a.x * b.x) * (a.y + b.y)) / (sqrt(a.x * a.x + a.y * a.y) * sqrt(b.x * b.x + b.y * b.y)));
    return sqrt(sqrt(a.x * a.x + a.y * a.y) * sqrt(b.x * b.x + b.y * b.y) - sinA * sinA);
}

double Rectangle::perimeter() {
    return 2 * (sqrt(a.x * a.x + a.y * a.y) + sqrt(b.x * b.x + b.y * b.y));
}

double Parallelogram::perimeter() {
    return 2 * (sqrt(a.x * a.x + a.y * a.y) + sqrt(b.x * b.x + b.y * b.y));
}

double Rectangle::mass() const {
    return mas;
}

double Parallelogram::mass() const {
    return mas;
}

CVector2D Rectangle::position() {
    CVector2D centerMass;
    centerMass.x = (a.x + b.x + c.x + d.x) / 4;
    centerMass.y = (a.y + b.y + c.y + d.y) / 4;
    return centerMass;
}

CVector2D Parallelogram::position() {
    CVector2D centerMass;
    centerMass.x = (a.x + b.x + c.x + d.x) / 4;
    centerMass.y = (a.y + b.y + c.y + d.y) / 4;
    return centerMass;
}

bool IPhysObject::operator==(const IPhysObject &ob) const {
    return mass() == ob.mass();
}

bool IPhysObject::operator<(const IPhysObject &ob) const {
    return mass() < ob.mass();
}


void Rectangle::draw() {
    cout << classname() << '\n';
    cout << mass() << '\n';
    cout << size() << '\n';
    cout << square() << '\n';
    cout << perimeter() << '\n' << '\n';
}

void Parallelogram::draw() {
    cout << classname() << '\n';
    cout << mass() << '\n';
    cout << size() << '\n';
    cout << square() << '\n';
    cout << perimeter() << '\n' << '\n';
}

void Rectangle::initFromDialogue() {
    cout << "Enter first vector: ";
    cin >> a.x >> a.y;
    cout << "Enter second vector: ";
    cin >> b.x >> b.y;
    cout << "Enter third vector: ";
    cin >> c.x >> c.y;
    cout << "Enter fourth vector: ";
    cin >> d.x >> d.y;
    cout << "Enter the mass of figure: ";
    cin >> mas;
}

void Parallelogram::initFromDialogue() {
    cout << "Enter first vector: ";
    cin >> a.x >> a.y;
    cout << "Enter second vector: ";
    cin >> b.x >> b.y;
    cout << "Enter third vector: ";
    cin >> c.x >> c.y;
    cout << "Enter fourth vector: ";
    cin >> d.x >> d.y;
    cout << "Enter the mass of figure: ";
    cin >> mas;
}

const char *Rectangle::classname() {
    return name;
}

const char *Parallelogram::classname() {
    return name;
}

unsigned int Rectangle::size() {
    return sizeof(*this);
}

unsigned int Parallelogram::size() {
    return sizeof(*this);
}