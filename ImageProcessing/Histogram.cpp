#include "Histogram.h"
#include <iostream>
using namespace std;
Histogram::Histogram() {
	/// <summary>
	/// Default constuctor
	/// </summary>
	this->binSize = 16;
	this->m_histogram = new unsigned int[binSize];
	for (int i = 0; i < binSize; i++)
		this->m_histogram[i] = 0;
}
Histogram::Histogram(unsigned int b)
{
	/// <summary>
	/// Default constuctor with parameters
	/// </summary>
	/// <param name="b">Binsize to be intialized with</param>
	this->binSize = b;
	this->m_histogram = new unsigned int[b];
	for (int i = 0; i < b; i++)
		this->m_histogram[i] = 0;
}
Histogram::Histogram(Histogram& other) {
	/// <summary>
	/// Default copy constuctor
	/// </summary>
	/// <param name="other">The histogram to be copied to the inital one</param>
	this->binSize = other.binSize;
	this->m_histogram = new unsigned int[this->binSize];
	for (int i = 0; i < this->binSize; i++)
		this->m_histogram[i] = other.m_histogram[i];
}
Histogram& Histogram::operator=(const Histogram& h) {
	/// <summary>
	/// Copy constructor
	/// </summary>
	/// <param name="image">Image to be copied</param>
	/// <returns>The resulted image</returns>
	this->binSize = h.binSize;
	this->m_histogram = new unsigned int[this->binSize];
	for (int i = 0; i < this->binSize; i++)
	{
		this->m_histogram[i] = h.m_histogram[i];
	}
	return *this;
}
Histogram::~Histogram() {
	/// <summary>
	/// Default destructor
	/// </summary>
	delete[] this->m_histogram;
}
unsigned int* Histogram::getHistogram() const{
	/// <summary>
	/// Histogram getter
	/// </summary>
	/// <returns>The whole histogram</returns>
	return this->m_histogram;
}
unsigned int Histogram::getBinSize() const {
	return this->binSize;
}
ostream& operator<<(ostream& os, const Histogram& h)
{
	/// <summary>
	/// Output operator
	/// </summary>
	/// <param name="os">output saver</param>
	/// <param name="dt">histogram from which to read</param>
	/// <returns>The console print of the Histogram</returns>
	os << "Histogram\n";
	for (int i = 0; i < h.binSize; i++)
		os << h.m_histogram[i] << " ";

	return os;
}