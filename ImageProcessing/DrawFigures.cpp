#include <math.h>
#include "DrawFigures.h"
void drawCircle(Image& img, Point center, int radius, unsigned char color) {
	/// <summary>
	/// Draw a circle over an image
	/// </summary>
	/// <param name="img">Image on which to draw</param>
	/// <param name="center">Center of the circle</param>
	/// <param name="radius">Radius of the circle</param>
	/// <param name="color">Color to be drawed</param>
	for (int i = 0; i < img.width(); i++)
		for (int j = 0; j < img.height(); j++)
			if (radius == (int)d(center.getx(), center.gety(), i, j))
				img.at(i, j) = color;
}

void drawLine(Image& img, Point p1, Point p2, unsigned char color) {
	/// <summary>
	/// Draw a line over an image
	/// </summary>
	/// <param name="img">Image on which to draw</param>
	/// <param name="p1">First point of the line</param>
	/// <param name="p2">Second point of the line</param>
	/// <param name="color">Color to be drawed</param>
	for (int i = 0; i < img.width(); i++)
		for (int j = 0; j < img.height(); j++)
			if (d(p1.getx(), p1.gety(), p2.getx(), p2.gety()) == d(p1.getx(), p1.gety(), i, j) + d(i, j, p2.getx(), p2.gety()))
				img.at(i, j) = color;
}

void drawRectangle(Image& img, Rectangle r, unsigned char color) {
	/// <summary>
	/// Draw a rectangle over an image
	/// </summary>
	/// <param name="img">Image on which to draw</param>
	/// <param name="r">Rectangle</param>
	/// <param name="color">Color to be drawed</param>
	Point pt1(r.getx(), r.gety());
	Point pt2(r.getx(), r.gety() + r.getHeight());
	Point pt3(r.getx() + r.getWidth(), r.gety() + r.getHeight());
	Point pt4(r.getx() + r.getWidth(), r.gety());
	drawLine(img, pt1, pt2, color);
	drawLine(img, pt2, pt3, color);
	drawLine(img, pt3, pt4, color);
	drawLine(img, pt4, pt1, color);
}
void drawRectangle(Image& img, Point tl, Point br, unsigned char color) {
	/// <summary>
	/// Draw a rectangle over an image
	/// </summary>
	/// <param name="img">Image on which to draw</param>
	/// <param name="tl">First point</param>
	/// <param name="br">Second point</param>
	/// <param name="color">Color to be drawed</param>
	Point pt1(tl.getx(), tl.gety());
	Point pt2(tl.getx(), tl.gety() - br.gety());
	Point pt3(br.getx() - tl.getx(), tl.gety() - br.gety());
	Point pt4(br.getx(), br.gety());
	drawLine(img, pt1, pt2, color);
	drawLine(img, pt2, pt3, color);
	drawLine(img, pt3, pt4, color);
	drawLine(img, pt4, pt1, color);
}
float d(int x, int y, int p, int q)
{
	/// <summary>
	/// Computed the distance between two points
	/// </summary>
	/// <param name="x">x-coordinate of the point</param>
	/// <param name="y">y-coordinate of the point</param>
	/// <param name="p">x-coordinate of the point</param>
	/// <param name="q">x-coordinate of the point</param>
	/// <returns>the resulted distance</returns>
	return sqrt(pow(p - x, 2) + pow(y - q, 2));
}