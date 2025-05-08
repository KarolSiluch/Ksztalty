#include <iostream>
#include "../KształtyLib/Figure.h"
#include "../KształtyLib/List.h"
#include <algorithm>

int main() {
    Triangle t1(3, 4, 5);
    Rectangle p1(2, 8);
    Circle c1(sqrt(6));

	List<Figure> list;
    list.add(&t1);
	list.add(&p1);
	list.add(&c1);

	for (auto figure : list) {
		std::cout << "Pole figury: " << figure->area() << std::endl;
	}
}
