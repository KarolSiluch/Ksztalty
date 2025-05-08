#pragma once

class Figure {
public:
    ~Figure() = default;
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    bool operator==(const Figure& f) const;
};

// -------------------------------
class Triangle : public Figure {
private:
    double ai;
    double bi;
	double ci;

public:
	Triangle(double a, double b, double c);
    double area() const override;
    double perimeter() const override;
};

// -------------------------------
class Rectangle : public Figure {
private:
    double widthi;
    double heighti;

public:
    Rectangle(double width, double height);
    double area() const override;
    double perimeter() const override;
};

// -------------------------------
class Circle : public Figure {
private:
    double radiusi;
public:
    Circle(double radius);
    double area() const override;
    double perimeter() const override;
};
