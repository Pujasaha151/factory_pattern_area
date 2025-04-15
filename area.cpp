#include<iostream>
#ifndef SHAPES_H
#define SHAPES_H
#include <cmath>

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};
