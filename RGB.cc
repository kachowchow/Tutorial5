#include "RGB.h"
#include <iostream>

using namespace std;

RGB::RGB(int red, int green, int blue)
    : red(red), green(green), blue(blue) {}

void RGB::print() const
{
    cout << "RGB(" << red << ", " << green << ", " << blue << ")" << endl;
}

RGB RGB::getColour() const
{
    return *this;
}

unsigned long RGB::getColour()
{
    return (red << 16) | (green << 8) | blue;
}

void RGB::setColour(const RGB &color)
{
    red = color.red;
    green = color.green;
    blue = color.blue;
}

RGB RGB::WHITE()
{
    return RGB(255, 255, 255);
}

RGB RGB::BLACK()
{
    return RGB(0, 0, 0);
}

RGB RGB::RED()
{
    return RGB(255, 0, 0);
}

RGB RGB::GREEN()
{
    return RGB(0, 255, 0);
}

RGB RGB::BLUE()
{
    return RGB(0, 0, 255);
}
