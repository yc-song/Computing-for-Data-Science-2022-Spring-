#include <cstdlib>
#include <iostream>
#include <math.h>
#include "mycode.h"
#include <stdio.h>
// Fill in
Shape::Shape(float x) { length = x; };
Square::Square(float x) : Shape(x) {};
Equilateral::Equilateral(float x) : Shape(x) {};

float Shape::area() { return 0; };
float Square::area() { return length*length; };
float Equilateral::area() { return sqrtf(3)*powf(length, 2)/4; };
void Shape::print() {
	printf("This is Shape. Area is %f\n", area());
}
void Square::print() { printf("This is Square. Area is %f\n", area()); }
void Equilateral::print() { printf("This is Equilateral. Area is %f\n", area()); }