#pragma once
#include "Image.h"
#include "ImageProcessing.h"

class GammaCorection: public ImageProcessing
{
public:
	GammaCorection();
	GammaCorection(float g);
	void process(Image& src, Image& dst);
private:
	float g;
};

