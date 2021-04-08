#include "Image.h"
#include "Size.h"
#include "math.h"
#include <exception>
#include <fstream>
#include <iomanip>
using namespace std;

Image::Image() {
	/// <summary>
	/// Default Constructor
	/// </summary>
	this->m_width = 256;
	this->m_height = 256;
	this->m_data = new unsigned char* [m_width];
	for (int i = 0; i < m_width; i++)
		this->m_data[i] = new unsigned char[m_height];
}
Image::Image(unsigned int w, unsigned int h) {
	/// <summary>
	/// Default constructor with parameters
	/// </summary>
	/// <param name="w">width</param>
	/// <param name="h">height</param>
	this->m_width = w;
	this->m_height = h;
	this->m_data = new unsigned char* [w];
	for (int i = 0; i < w; i++)
		this->m_data[i] = new unsigned char[h];
}
Image::Image(const Image& other) {
	/// <summary>
	/// Copy constructor
	/// </summary>
	/// <param name="other">image to be copied</param>
	this->m_width = other.m_width;
	this->m_height = other.m_height;
	this->m_data = new unsigned char* [this->m_width];
	for (int i = 0; i < this->m_width; i++)
	{
		this->m_data[i] = new unsigned char[this->m_height];
		for (int j = 0; j < this->m_height; j++)
			this->m_data[i][j] = other.m_data[i][j];
	}
}
Image::~Image() {
	/// <summary>
	/// Default destructor
	/// </summary>
	Image::release();
}

bool Image::isEmpty() const {
	/// <summary>
	/// Check if a function is empty
	/// </summary>
	/// <returns>true - image is empty
	///			 false - otherwise
	/// </returns>
	if (this->m_width == 0 || this->m_height == 0)
		return true;
	return false;
}
unsigned int Image::width() const{
	/// <summary>
	/// Width getter
	/// </summary>
	/// <returns>the width of the image</returns>
	return this->m_width;
}
unsigned int Image::height() const{
	/// <summary>
	/// Height getter
	/// </summary>
	/// <returns>the height of the image</returns>
	return this->m_height;
}
ostream& operator<<(ostream& os, const Image& dt)
{
	/// <summary>
	/// <<operator
	/// </summary>
	/// <param name="os">input saver</param>
	/// <param name="dt">image from which to read</param>
	/// <returns>The console print of the Image</returns>
	for (int j = 0; j < dt.m_height; j++)
	{
		for (int i = 0; i < dt.m_width; i++)
		{
			os << setw(3);
			os << (int)dt.m_data[i][j] << ' ';
		}
		os << '\n';
	}
	os << '\n';

	return os;
}
bool Image::load(std::string imagePath)
{
	/// <summary>
	/// Load an image from a file
	/// </summary>
	/// <param name="imagePath">file name</param>
	/// <returns>The image saved in the given file</returns>
	ifstream f(imagePath);

	char magic_number[3];
	unsigned int darkest_gray;

	f.getline(magic_number, 3);
	f >> this->m_width >> this->m_height >> darkest_gray;

	this->m_data = new unsigned char* [m_width];
	for (int i = 0; i < m_width; i++)
		this->m_data[i] = new unsigned char[m_height];

	for (int j = 0; j < this->m_height; j++)
	{
		for (int i = 0; i < this->m_width; i++)
		{
			int point;
			f >> point;
			if (point > 255)
				return false;

			this->m_data[i][j] = (unsigned char)point;
		}
	}

	f.close();

	return true;
}

bool Image::save(std::string imagePath)
{
	/// <summary>
	/// Save an image to a file
	/// </summary>
	/// <param name="imagePath">file name</param>
	/// <returns>true - image was saved succesfully
	///			 false - otherwise
	/// </returns>

	ofstream g(imagePath);

	g << "P5\n" << this->m_width << ' ' << this->m_height << '\n' << "255\n";

	for (int i = 0; i < this->m_height; i++)
	{
		for (int j = 0; j < this->m_width; j++)
		{
			int point;
			point = this->m_data[i][j];
			g << point << ' ';
		}
		g << '\n';
	}

	g.close();

	return true;
}
Image Image::zeros(unsigned int width, unsigned int height) {
	/// <summary>
	/// Transforms the whole image pixels into value 0
	/// </summary>
	/// <param name="width">Width of the image</param>
	/// <param name="height">Height of the image</param>
	/// <returns>The resulted image</returns>
	Image image(width, height);
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			image.m_data[i][j] = 0;
	return image;
}
Image Image::ones(unsigned int width, unsigned int height) {
	/// <summary>
	/// Transforms the whole image pixels into value 1
	/// </summary>
	/// <param name="width">Width of the image</param>
	/// <param name="height">Height of the image</param>
	/// <returns>The resulted image</returns>
	Image image(width, height);
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			image.m_data[i][j] = 1;
	return image;
}
Image Image::operator+(const Image& image) {
	/// <summary>
	/// Add operator between two images
	/// </summary>
	/// <param name="image">The image to be added to the initial one</param>
	/// <returns>The resulted image</returns>
	if (this->m_width != image.m_width) {
		throw exception();
	}
	if (this->m_height != image.m_height) {
		throw exception();
	}
	Image new_image(*this);
	for (int i = 0; i < new_image.m_width; i++)
		for (int j = 0; j < new_image.m_height; j++) {
			if (image.m_data[i][j] + new_image.m_data[i][j] > 255)
				new_image.m_data[i][j] = 255;
			else
				new_image.m_data[i][j] += image.m_data[i][j];
		}
	return new_image;
}
Image Image::operator-(const Image& image) {
	/// <summary>
	/// Substract operator between two images
	/// </summary>
	/// <param name="image">The image to be substracted from the initial one</param>
	/// <returns>The resulted image</returns>
	if (this->m_width != image.m_width) {
		throw exception();
	}
	if (this->m_height != image.m_height) {
		throw exception();
	}
	Image new_image(*this);
	for (int i = 0; i < new_image.m_width; i++)
		for (int j = 0; j < new_image.m_height; j++) {
			if (new_image.m_data[i][j] - image.m_data[i][j] < 0)
				new_image.m_data[i][j] = 0;
			else
				new_image.m_data[i][j] -= image.m_data[i][j];
		}
	return new_image;
}
Image Image::operator*(const Image& image) {
	/// <summary>
	/// Multiplication operator between two images
	/// </summary>
	/// <param name="image">The image to be multiplied to the initial one</param>
	/// <returns>The resulted image</returns>
	if (this->m_width != image.m_width) {
		throw exception();
	}
	if (this->m_height != image.m_height) {
		throw exception();
	}
	Image new_image(*this);
	for (int i = 0; i < new_image.m_width; i++)
		for (int j = 0; j < new_image.m_height; j++) {
			if (image.m_data[i][j] * new_image.m_data[i][j] > 255)
				new_image.m_data[i][j] = 255;
			else
				new_image.m_data[i][j] *= image.m_data[i][j];
		}
	return new_image;
}
Image Image::operator+(const unsigned int x) {
	/// <summary>
	/// Add operator between an image and a constant
	/// </summary>
	/// <param name="x">value to be added</param>
	/// <returns>The resulted image</returns>
	Image new_image(*this);
	for (int i = 0; i < new_image.m_width; i++)
		for (int j = 0; j < new_image.m_height; j++) {
			if (new_image.m_data[i][j] + x > 255)
				new_image.m_data[i][j] = 255;
			else
				new_image.m_data[i][j] += x;
		}
	return new_image;
}
Image Image::operator-(const unsigned int x) {
	/// <summary>
	/// Substract operator between an image and a constant
	/// </summary>
	/// <param name="x">value to be substracted</param>
	/// <returns>The resulted image</returns>
	Image new_image(*this);
	for (int i = 0; i < new_image.m_width; i++)
		for (int j = 0; j < new_image.m_height; j++) {
			if (new_image.m_data[i][j] - x < 0)
				new_image.m_data[i][j] = 0;
			else
				new_image.m_data[i][j] -= x;
		}
	return new_image;
}
Image Image::operator*(const unsigned int x) {
	/// <summary>
	/// Multiplication operator between an image and a constant
	/// </summary>
	/// <param name="x">value to be multiplied</param>
	/// <returns>The resulted image</returns>
	Image new_image(*this);
	for (int i = 0; i < new_image.m_width; i++)
		for (int j = 0; j < new_image.m_height; j++) {
			if (new_image.m_data[i][j] * x > 255)
				new_image.m_data[i][j] = 255;
			else
				new_image.m_data[i][j] *= x;
		}
	return new_image;
}
Image Image::operator^ (const unsigned int x) {
	/// <summary>
	/// Power operator between an image and a constant
	/// </summary>
	/// <param name="x">value of the power</param>
	/// <returns>The resulted image</returns>
	Image new_image(*this);
	for (int i = 0; i < new_image.m_width; i++)
		for (int j = 0; j < new_image.m_height; j++) {
			if (pow(new_image.m_data[i][j], x) > 255)
				new_image.m_data[i][j] = 255;
			else if (pow(new_image.m_data[i][j], x) < 0)
				new_image.m_data[i][j] = 0;
			else
				new_image.m_data[i][j] = pow(new_image.m_data[i][j], x);
		}
	return new_image;
}
Image& Image::operator=(const Image& image) {
	/// <summary>
	/// Copy constructor
	/// </summary>
	/// <param name="image">Image to be copied</param>
	/// <returns>The resulted image</returns>
	this->m_height = image.m_height;
	this->m_width = image.m_width;
	this->m_data = new unsigned char* [this->m_width];

	for (int i = 0; i < this->m_width; i++)
	{
		this->m_data[i] = new unsigned char[this->m_height];
		for (int j = 0; j < this->m_height; j++)
			this->m_data[i][j] = image.m_data[i][j];
	}
	return *this;
}

unsigned char* Image::row(int y) {
	/// <summary>
	/// Returns a given row
	/// </summary>
	/// <param name="y">The row to be returned</param>
	/// <returns>The row at index y</returns>
	return this->m_data[y];
}
unsigned char& Image::at(Point pt)
{
	/// <summary>
	/// Returns a point of a given point coordinates
	/// </summary>
	/// <param name="pt">Point to be returned</param>
	/// <returns>The adress of the required point</returns>
	return this->m_data[pt.getx()][pt.gety()];
}
unsigned char& Image::at(unsigned int x, unsigned int y)
{
	/// <summary>
	/// Returns a point of a given coordinates
	/// </summary>
	/// <param name="x">the index on x-axis</param>
	/// <param name="y">the index on y-axis</param>
	/// <returns>The adress of the point at the required coordinates</returns>
	return this->m_data[x][y];
}

Size Image::size() const{
	/// <summary>
	/// Returns the size of the image
	/// </summary>
	/// <returns>A class Size which memorize the width and the height</returns>
	return Size(this->m_width, this->m_height);
}

void Image::release() {
	/// <summary>
	/// Release the memory alocated for the image
	/// </summary>
	for (int i = 0; i < this->m_width; i++)
		delete[] this->m_data[i];
	delete[] this->m_data;
}
bool Image::getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
	/// <summary>
	/// Get an given rectangle at some given coordinated
	/// </summary>
	/// <param name="roiImg">The image in which the rectangle will be memorized</param>
	/// <param name="x">The coordinate on the x-axis</param>
	/// <param name="y">The coordinate on the y-axis</param>
	/// <param name="width">The width of the rectangle</param>
	/// <param name="height">The height of the rectangle</param>
	/// <returns>true - operation was succesfully executed
	///		     false - otherwise
	/// </returns>
	if (x + width > this->m_width || x <0) 
		return false;
	if (y + height > this->m_height || y < 0)
		return false;
	roiImg.m_width = width;
	roiImg.m_height = height;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			roiImg.m_data[i][j] = this->m_data[i + x][j + y];
	return true;
}
bool Image::getROI(Image& roiImg, Rectangle roiRect) {
	/// <summary>
	/// Get an given rectangle at some given coordinated
	/// </summary>
	/// <param name="roiImg">The image in which the rectangle will be memorize</param>
	/// <param name="roiRect">The rectangle to be returned</param>
	/// <returns>true - operation was succesfully executed 
	///			 false - otherwise
	/// </returns>
	if (roiRect.getx() + roiRect.getWidth() > this->m_width || roiRect.getx()  <0 )
		return false;
	if (roiRect.gety() + roiRect.getHeight() > this->m_height || roiRect.gety() < 0)
		return false;
	roiImg.m_width = roiRect.getWidth();
	roiImg.m_height = roiRect.getHeight();
	for (int i = 0; i < roiRect.getHeight(); i++)
		for (int j = 0; j < roiRect.getWidth(); j++)
			roiImg.m_data[i][j] = this->m_data[i + roiRect.getx()][j + roiRect.gety()];
	return true;
}
bool Image::operator==(const Image& other) {
	/// <summary>
	/// Equality operator
	/// </summary>
	/// <param name="other">The image to be compared with the initial image</param>
	/// <returns>true - images are equal
	///			 false - otherwise
	/// </returns>
	if (this->m_height != other.m_height)
		return false;
	if (this->m_width != other.m_width)
		return false;
	for (int i = 0; i < this->m_width; i++)
		for (int j = 0; j < this->m_height; j++)
			if (this->m_data[i][j] != other.m_data[i][j])
				return false;
	return true;
}
Histogram Image::histogram() {
	Histogram h;
	int pozition;
	for(int i = 0; i<this->m_width; i++)
		for (int j = 0; j < this->m_height; j++) {
			pozition = (int)this->m_data[i][j];
			h.getHistogram()[pozition]++;
		}
	return h;
}