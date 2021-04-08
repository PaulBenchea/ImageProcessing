#pragma once
class Size {
private:
	unsigned int m_width;
	unsigned int m_heigth;
public:
	Size();
	Size(unsigned int width, unsigned int heigth);
	unsigned int getWidth() const;
	unsigned int getHeight() const;
};
