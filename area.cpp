#include<iostream>
#ifndef SHAPES_H
#define SHAPES_H
#include <cmath>
#include <memory>
#include <string>
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
//Testing


TEST(ShapeAreaTest, CircleArea) {
    auto shape = ShapeFactory::createShape("circle", 2.0);
    EXPECT_NEAR(shape->area(), M_PI * 4, 1e-6);
}

TEST(ShapeAreaTest, SquareArea) {
    auto shape = ShapeFactory::createShape("square", 3.0);
    EXPECT_DOUBLE_EQ(shape->area(), 9.0);
}

TEST(ShapeAreaTest, RectangleArea) {
    auto shape = ShapeFactory::createShape("rectangle", 2.0, 5.0);
    EXPECT_DOUBLE_EQ(shape->area(), 10.0);
}
