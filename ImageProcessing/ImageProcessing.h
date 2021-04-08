#pragma once
#include "Image.h"
using namespace std;
class ImageProcessing
{
public:
	virtual void process(Image& src, Image& dst);
};

