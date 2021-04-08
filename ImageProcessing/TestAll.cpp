#include "TestAll.h"
#include <assert.h>
#include <math.h>


void testImage() {
	Image img1, img2, img3, img4, imgsum, imgproduct, imgsubstract, imgpower;
	Image imgsum2, imgproduct2, imgsubstract2, img7, img8, img9;
	img1.load("test.txt");
	img2.load("test2.txt");
	img3.load("test5.txt");
	img4.load("test4.txt");
	img7.load("test7.txt");

	imgsum = img1 + img1;
	imgproduct = img1 * img1;
	imgsubstract = img1 - img1;
	assert(img2 == imgsum);
	assert(img3 == imgproduct);
	assert(img4 == imgsubstract);
	imgpower = img1 ^ 2;
	assert(imgpower == imgproduct);
}
void testRectangle() {
	Rectangle rect(1, 5, 5, 4), rect2(3, 3, 2, 0), rect3, rect4;
	//cout << rect;
}
void testBrightnessContrast() {
	Image image1, image2;
	Image test;
	BrightnessContrast b(2, 1);
	image1.load("test.txt");
	image2.load("test.txt");
	test.load("test3.txt");
	b.process(image1, image2);
	assert(image2 == test);
}
void testGammaCorection() {
	Image image1, image2;
	Image test;
	GammaCorection g(2);
	image1.load("test.txt");
	image2.load("test.txt");
	test.load("test6.txt");
	g.process(image1, image2);
	assert(image2 == test);

}
void testAll() {
	testRectangle();
	testImage();
	testBrightnessContrast();
	testGammaCorection();
}