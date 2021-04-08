#pragma once
#include "Point.h"
#include <iostream>
using namespace std;
class Rectangle
{
public:
	Rectangle();
	Rectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
	Rectangle(Point p, Point q);
	friend ostream& operator<<(ostream& os, const Rectangle& rect);
	friend istream& operator>>(istream& is, Rectangle& rect);
	Rectangle operator|(Rectangle rectangle);
	Rectangle operator&(Rectangle rectangle);
	Rectangle operator+(int value);
	Rectangle operator-(int value);
	unsigned int getx();
	unsigned int gety();
	unsigned int getWidth();
	unsigned int getHeight();
private:
	unsigned int x;
	unsigned int y;
	unsigned int width;
	unsigned int height;
};

