#pragma once
#include "Image.h"
#include "ImageProcessing.h"

class BrightnessContrast: public ImageProcessing
{
public:
	BrightnessContrast();
	BrightnessContrast(int beta, unsigned int alpha);
	void process(Image& src, Image& dst);
private:
	int beta;
	unsigned int alpha;
};

