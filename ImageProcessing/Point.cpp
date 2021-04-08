#include "Point.h"
#include <iostream>

using namespace std;

Point::Point()
{
	/// <summary>
	/// Default constructor
	/// </summary>
	this->x = 0;
	this->y = 0;
}
Point::Point(unsigned int x, unsigned int y)
{
	/// <summary>
	/// Default constructor with parameters
	/// </summary>
	/// <param name="x">value of the point on the x-axis</param>
	/// <param name="y">value of the point on the y-axis</param>
	this->x = x;
	this->y = y;
}
unsigned int Point::getx(){
	/// <summary>
	/// Getter of the value of the point on the x-axis
	/// </summary>
	/// <returns>The value of the given coordinate</returns>
	return this->x;
}
unsigned int Point::gety(){
	/// <summary>
	/// Getter of the value of the point on the y-axis
	/// </summary>
	/// <returns>The value of the given coordinate</returns>
	return this->y;
}
ostream &operator<<(ostream& os, const Point& p) {
	/// <summary>
	/// Output operator
	/// </summary>
	/// <param name="os">output saver</param>
	/// <param name="dt">point from which to read</param>
	/// <returns>The console output of the Point</returns>
	os << "Point (" << p.x << "," << p.y << ")\n";
	return os;
}
istream &operator>>(istream& is, Point& p) {
	/// <summary>
	/// Input operator
	/// </summary>
	/// <param name="is">input saver</param>
	/// <param name="p">point from which to read</param>
	/// <returns>The input</returns>
	cout << "Give x coordinate: ";
	is >> p.x;
	cout << "Give y coordinate: ";
	is >> p.y;
	return is;
}
