#pragma once

// Fill in
class Shape {
public:
	Shape(float);
	virtual float area();
	void print();
protected:
	float length;
};

class Square : public Shape {
public:
	float area();
	Square(float x);
	void print(void);
};

class Equilateral : public Shape {
public:
	float area();
	Equilateral(float x);
	void print(void);
};