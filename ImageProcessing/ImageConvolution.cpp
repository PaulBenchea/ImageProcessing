#include "ImageConvolution.h"
ImageConvolution::ImageConvolution() {
	/// <summary>
	/// Default constructor
	/// </summary>
	this->k = Image().ones(256, 256);
}
ImageConvolution::ImageConvolution(Image k) {
	/// <summary>
	/// Default constructor with parameters
	/// </summary>
	/// <param name="k">Image to be initialized</param>
	this->k = k;
}
void ImageConvolution::process(Image& src, Image& dst) {
	/// <summary>
	/// Applies the ImageConvolution operation
	/// </summary>
	/// <param name="src">Initial Image</param>
	/// <param name="dst">Resulted Image</param>
	for (int i = 0; i<src.width() - this->k.width() + 1; i++)
		for (int j = 0; j < src.height() - this->k.height() + 1; j++) {
			int calculate = 0;
			for (int u = 0; u < this->k.width(); u++)
				for (int v = 0; v < this->k.height(); v++)
					calculate += this->k.at(u, v) * src.at(i + u, j + v);
			dst.at(i, j) = ImageConvolution().normalizator(calculate);
		}
}

unsigned int ImageConvolution::normalizator(int p) {
	/// <summary>
	/// Normalize a point if out of index
	/// </summary>
	/// <param name="p">The value of the given point</param>
	/// <returns>The new value of the given point</returns>
	if (p < 0)
		return 0;
	else if (p > 255)
		return 255;
	else
		return p;
}