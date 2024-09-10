#pragma once
#include <iostream>
class Point {
private:
	double x, y;
public:
	Point(double x, double y) { // Конструктор
		this->x = x;
		this->y = y;
	}
	void print() {
		std::cout << "x = " << x << " y = " << y << std::endl;
	}
};
