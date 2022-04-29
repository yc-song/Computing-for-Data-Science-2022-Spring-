#include "shapes.h"
#include <iostream>
#include <stdio.h>
// Fill in here
/** Constructor **/
Shape::Shape(int x, int y) {
	x_pos=x;
	y_pos=y;
}
void Shape::DrawSelf(void) {
	std::cout << "Draw Shape at (" << x_pos << ", " << y_pos << ")" << std::endl;
}
Point::Point(int x, int y) :Shape(x, y) {};

void Point::DrawSelf(void) {
	printf("Draw Point at (%d, %d) \n", x_pos, y_pos);
};
Line::Line(int x, int y) :Shape(x, y) {};
void Line::DrawSelf(void) {
	printf("Draw Line at (%d, %d) \n", x_pos, y_pos);
};
Triangle::Triangle(int x, int y) :Shape(x, y) {};
void Triangle::DrawSelf(void) {
	printf("Draw Triangle at (%d, %d) \n", x_pos, y_pos);
};
Quadrilateral::Quadrilateral(int x, int y) :Shape(x, y) {};
void Quadrilateral::DrawSelf(void) {
	printf("Draw Quadrilateral at (%d, %d) \n", x_pos, y_pos);
};
Equilateral::Equilateral(int x, int y) :Triangle(x, y) {};
void Equilateral::DrawSelf(void) {
	printf("Draw Equilateral at (%d, %d) \n", x_pos, y_pos);
};
Isosceles::Isosceles(int x, int y) :Triangle(x, y) {};
void Isosceles::DrawSelf(void) {
	printf("Draw Isosceles at (%d, %d) \n", x_pos, y_pos);
};
Scalene::Scalene(int x, int y) :Triangle(x, y) {};
void Scalene::DrawSelf(void) {
	printf("Draw Scalene at (%d, %d) \n", x_pos, y_pos);
};
Rectangle::Rectangle(int x, int y) :Quadrilateral(x, y) {};
void Rectangle::DrawSelf(void) {
	printf("Draw Rectangle at (%d, %d) \n", x_pos, y_pos);
};
Square::Square(int x, int y) :Quadrilateral(x, y) {};
void Square::DrawSelf(void) {
	printf("Draw Square at (%d, %d) \n", x_pos, y_pos);
};
