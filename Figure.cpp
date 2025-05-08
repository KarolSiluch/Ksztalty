#include "figure.h"
#include <algorithm>
#include <stdexcept>


bool Figure::operator==(const Figure& f) const {
    return std::abs(this->area() - f.area()) < 5 * std::numeric_limits<double>::epsilon();
}

// -------------------------------
Triangle::Triangle(double a, double b, double c) : ai(a), bi(b), ci(c) {
	if (a + b <= c || a + c <= b || b + c <= a) {
		throw std::invalid_argument("Invalid triangle sides");
	}
}

double Triangle::area() const {
	double s = (ai + bi + ci) / 2;
	return sqrt(s * (s - ai) * (s - bi) * (s - ci));
	
}

double Triangle::perimeter() const {
	return ai + bi + ci;
}

// -------------------------------
Rectangle::Rectangle(double width, double height) : widthi(width), heighti(height) {
	if (width <= 0 || height <= 0)
		throw std::invalid_argument("Invalid rectangle dimensions");
}

double Rectangle::area() const {
    return widthi * heighti;
}

double Rectangle::perimeter() const {
	return 2 * (widthi + heighti);
}

// -------------------------------
Circle::Circle(double radius) : radiusi(radius) {
	if (radius <= 0)
		throw std::invalid_argument("Invalid circle radius");
}

double Circle::area() const {
	return 3.14 * pow(radiusi, 2);
}

double Circle::perimeter() const {
	return 2 * 3.14 * radiusi;
}
