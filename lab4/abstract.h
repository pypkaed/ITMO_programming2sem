#pragma once
#include <iostream>
#include <cmath>

// --- abstract classes ---
class IGeoFig {
public:
    virtual double square() = 0;
    virtual double perimeter() = 0;
};

class CVector2D {
public:
    double x = 0, y = 0;
};

class IPhysObject {
public:
    // масса, кг
    virtual double mass() const = 0;
    // координаты центра масс, м
    virtual CVector2D position() = 0;
    // сравнение по массе
    bool operator==(const IPhysObject &ob) const;
    bool operator<(const IPhysObject &ob) const;
};

class IPrintable {
public:
    // вывести параметры фигуры
    virtual void draw() = 0;
};

class IDialogInitiable {
    // задать параметры объекта через консоль
    virtual void initFromDialogue() = 0;
};

class BaseCObject {
public:
    // имя класса
    virtual const char* classname() = 0;
    // размер занимаемой памяти
    virtual unsigned int size() = 0;
};

class Figure : public IGeoFig, public IPhysObject,
        public IPrintable, public IDialogInitiable, public BaseCObject {

};

// --- rectangle ---
class Rectangle : public Figure {
public:
    Rectangle() {
        this->initFromDialogue();
    };
    ~Rectangle() = default;
    double square() override;
    double perimeter() override;
    double mass() const override;
    CVector2D position() override;

    void draw() override;
    void initFromDialogue() override;
    const char* classname() override;
    unsigned int size() override;

private:
    CVector2D a, b, c, d;
    const char* name = "Rectangle";
    double mas = 0;
};

// --- parallelogram ---
class Parallelogram : public Figure {
public:
    Parallelogram() {
        this->initFromDialogue();
    };
    ~Parallelogram() = default;
    double square() override;
    double perimeter() override;
    double mass() const override;
    CVector2D position() override;

    void draw() override;
    void initFromDialogue() override;
    const char* classname() override;
    unsigned int size() override;

private:
    CVector2D a, b, c, d;
    const char* name = "Parallelogram";
    double mas = 0;
};