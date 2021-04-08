#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(){
	/// <summary>
	/// Default constructor
	/// </summary>
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
}
Rectangle::Rectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height){
	/// <summary>
	/// Default constructor with parameters as coordinates and width, height
	/// </summary>
	/// <param name="x">The value of the rectangle on the x-axis</param>
	/// <param name="y">The value of the rectangle on the y-axis</param>
	/// <param name="width">The width of the rectangle</param>
	/// <param name="height">The height of the rectangle</param>
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}
Rectangle::Rectangle(Point p, Point q)
{
	/// <summary>
	/// Default constructor with parameters as two points
	/// </summary>
	/// <param name="p">First point</param>
	/// <param name="q">Second point</param>
	this->x = p.getx();
	this->y = p.gety();

	this->width = q.getx() - p.getx();
	this->height = p.gety() - q.gety();
}
int absolute(int x) {
	/// <summary>
	/// Returns the absolute value of a constant
	/// </summary>
	/// <param name="x">Value of the constant</param>
	/// <returns>The absolute value of x</returns>
	if (x < 0)
		return -x;
	return x;

}

Rectangle Rectangle::operator|(Rectangle rectangle) {
	/// <summary>
	/// Applies the union operation
	/// </summary>
	/// <param name="rectangle">Rectangle to be united with the initial one</param>
	/// <returns>Resulted rectangle</returns>
	Rectangle resulted_rectangle;

	if (this->x < rectangle.x) {
		resulted_rectangle.x = this->x;
		resulted_rectangle.width = (rectangle.x + rectangle.width) - this->x;
	}
	else {
		resulted_rectangle.x = rectangle.x;
		resulted_rectangle.width = (this->x + this->width) - rectangle.x;
	}

	if (this->y > rectangle.y) {
		resulted_rectangle.y = this->y;
		resulted_rectangle.height = this->y - (rectangle.y - rectangle.height);
	}
	else {
		resulted_rectangle.y = rectangle.y;
		resulted_rectangle.height = rectangle.y - (this->y - this->height);
	}

	return resulted_rectangle;
}

Rectangle Rectangle::operator&(Rectangle rectangle) {
	/// <summary>
	/// Applies the intersection operator
	/// </summary>
	/// <param name="rectangle">Rectangle to be intersected to the initial one</param>
	/// <returns>Resulted rectangle</returns>
	Rectangle resulted_rectangle;

	if (absolute(this->y - rectangle.y) > this->height && absolute(rectangle.y - this->y) > rectangle.height) {
		return resulted_rectangle;
	}

	if (absolute(rectangle.x - this->x) > this->width && absolute(this->x - rectangle.x) > rectangle.width) {
		return resulted_rectangle;
	}
	if (this->y - rectangle.y < this->height) {
		resulted_rectangle.height = this->height - (this->y - rectangle.y);
	}
	else {
		resulted_rectangle.height = rectangle.height - (rectangle.y - this->y);
	}

	if (rectangle.x - this->x < this->width) {
		resulted_rectangle.width = this->width - (rectangle.x - this->x);
	}
	else {
		resulted_rectangle.width = rectangle.width - (this->x - rectangle.x);
	}

	if (this->x > rectangle.x) {
		resulted_rectangle.x = this->x;
	}
	else {
		resulted_rectangle.x = rectangle.x;
	}

	if (this->y > rectangle.y) {
		resulted_rectangle.y = rectangle.y;
	}
	else {
		resulted_rectangle.y = this->y;
	}

	return resulted_rectangle;
}
unsigned int Rectangle::getx() {
	/// <summary>
	/// Rectangle getter
	/// </summary>
	/// <returns>The x coordinate</returns>
	return this->x;
}
unsigned int Rectangle::gety() {
	/// <summary>
	/// Rectangle getter
	/// </summary>
	/// <returns>Rectangle height</returns>
	return this->y;
}
unsigned int Rectangle::getWidth() {
	/// <summary>
	/// Rectangle getter
	/// </summary>
	/// <returns>Rectangle width</returns>
	return this->width;
}
unsigned int Rectangle::getHeight() {
	/// <summary>
	/// Rectangle getter
	/// </summary>
	/// <returns>The y coordinate</returns>
	return this->height;
}
ostream& operator<<(ostream& os, const Rectangle& rect) {
	/// <summary>
	/// Output operator
	/// </summary>
	/// <param name="os">output saver</param>
	/// <param name="dt">rectangle from which to read</param>
	/// <returns>The console output of the Rectangle</returns>
	os << "Rectangle (" << rect.x << "," << rect.y << ") of width " << rect.width << " and height " << rect.height << '\n';
	return os;
}
istream& operator>>(istream& is, Rectangle& rect) {
	/// <summary>
	/// Input operator
	/// </summary>
	/// <param name="is">input saver</param>
	/// <param name="p">point from which to read</param>
	/// <returns>The input</returns>
	cout << "Give x coordinate: ";
	is >> rect.x;
	cout << "Give y coordinate: ";
	is >> rect.y;
	cout << "Give width: ";
	is >> rect.width;
	cout << "Give height: ";
	is >> rect.height;
	return is;
}
Rectangle Rectangle::operator+(int value) {
	/// <summary>
	/// Add operator
	/// </summary>
	/// <param name="value">Value to be added to the rectangle</param>
	/// <returns>The resulted rectangle</returns>
	Rectangle resulted_rectangle(this->x + value, this->y + value, this->width, this->height);
	return resulted_rectangle;
}
Rectangle Rectangle::operator-(int value) {
	/// <summary>
	/// Substract operator
	/// </summary>
	/// <param name="value">Value to be substracted from the rectangle</param>
	/// <returns>The resulted rectangle</returns>
	Rectangle resulted_rectangle(this->x - value, this->y - value, this->width, this->height);
	return resulted_rectangle;
}
