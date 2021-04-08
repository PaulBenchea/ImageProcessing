#include "Size.h"
Size::Size()
{
	/// <summary>
	/// Default constructor
	/// </summary>
	this->m_heigth = 0;
	this->m_width = 0;
}
Size::Size(unsigned int width, unsigned int heigth)
{
	/// <summary>
	/// Default constructor with parameters
	/// </summary>
	/// <param name="width">Width of the image</param>
	/// <param name="heigth">Height of the image</param>
	this->m_heigth = width;
	this->m_width = heigth;
}
unsigned int Size::getWidth() const{
	/// <summary>
	/// Width getter
	/// </summary>
	/// <returns>width</returns>
	return this->m_width;
}
unsigned int Size::getHeight() const{
	/// <summary>
	/// Height getter
	/// </summary>
	/// <returns>height</returns>
	return this->m_heigth;
}