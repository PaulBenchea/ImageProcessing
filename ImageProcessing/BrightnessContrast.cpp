#include "BrightnessContrast.h"
BrightnessContrast::BrightnessContrast() {
	/// <summary>
	/// Default constructor
	/// </summary>
	this->alpha = 1;
	this->beta = 0;
}
BrightnessContrast::BrightnessContrast(int beta, unsigned int alpha) {
	/// <summary>
	/// Default Constructor with parameters
	/// </summary>
	/// <param name="beta">beta value</param>
	/// <param name="alpha">alpha value</param>
	this->alpha = alpha;
	this->beta = beta;
}
void BrightnessContrast::process(Image& src, Image& dst) {
	/// <summary>
	/// Applies the brightness contrast operation
	/// </summary>
	/// <param name="src">Initial image</param>
	/// <param name="dst">Resulted image</param>
	dst = src * this->alpha + this->beta;
}