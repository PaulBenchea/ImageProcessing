#pragma once
#include <iostream>
using namespace std;
class Point
{
public:
	Point();
	Point(unsigned int x, unsigned int y);

	unsigned int getx();
	unsigned int gety();
	friend ostream &operator<<(ostream& os, const Point& p);
	friend istream &operator>>(istream& is, Point& p);
private:
	unsigned int x;
	unsigned int y;
};

