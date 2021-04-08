#pragma once
#include "ImageProcessing.h"
#include "Image.h"

class ImageConvolution: public ImageProcessing
{
public:
	ImageConvolution();
	ImageConvolution(Image k);
	void process(Image& src, Image& dst);
	static unsigned int normalizator(int p);
private:
	Image k;
};

