#include "GammaCorection.h"

GammaCorection::GammaCorection() {
	/// <summary>
	/// Defalut constructor
	/// </summary>
	this->g = 1;
}
GammaCorection::GammaCorection(float g) {
	/// <summary>
	/// Default constructor with parameters
	/// </summary>
	/// <param name="g">value to be initialized</param>
	this->g = g;
}

void GammaCorection::process(Image& src, Image& dst) {
	/// <summary>
	/// Applies the GammaCorection operation on the image
	/// </summary>
	/// <param name="src">image to be modified</param>
	/// <param name="dst">resulted image</param>
	dst = src ^ this->g;
}