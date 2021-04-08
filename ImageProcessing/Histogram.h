#pragma once
#include <iostream>
class Histogram
{
public:
	Histogram();
	Histogram(unsigned int b);
	~Histogram();
	Histogram(Histogram& other);
	Histogram& operator=(const Histogram& other);
	unsigned int* getHistogram() const;
	unsigned int getBinSize() const;
	friend std::ostream& operator<<(std::ostream& os, const Histogram& h);
private:
	unsigned int* m_histogram;
	unsigned int binSize;
};

