#include<iostream>
#ifndef SHAPES_H
#define SHAPES_H
#include <cmath>
#include <memory>
#include <string>
#include <gtest/gtest.h>
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
};

class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};




class ShapeFactory {
public:
    static std::unique_ptr<Shape> createShape(const std::string& type, double a, double b = 0) {
        if (type == "circle") {
            return std::make_unique<Circle>(a);
        } else if (type == "square") {
            return std::make_unique<Square>(a);
        } else if (type == "rectangle") {
            return std::make_unique<Rectangle>(a, b);
        } else {
            return nullptr;
        }
    }
};

#endif // SHAPEFACTORY_H



