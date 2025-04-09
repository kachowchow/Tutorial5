#include <iostream>
#include <iomanip>
#include "TextArea.h"

using namespace std;

TextArea::TextArea(int x, int y, int width, int height, string id, string label, RGB fill, RGB border)
    : dimensions(x, y, width, height), id(id), text(label), fill(fill), border(border) {}

TextArea::TextArea(Rectangle dimensions, string id, string label, RGB fill, RGB border)
    : dimensions(dimensions), id(id), text(label), fill(fill), border(border) {}

void TextArea::draw(Display *display, Window win, GC gc, int x, int y)
{

    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);
    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);
    XSetForeground(display, gc, BlackPixel(display, DefaultScreen(display)));
    XDrawString(display, win, gc, x + 5, y + 20, text.c_str(), text.length());
}

bool TextArea::overlaps(TextArea &ta)
{
    return dimensions.overlaps(ta.getDimensions());
}

void TextArea::print() const
{
    cout << left << setw(20) << "TextArea id:" << id << endl;
    cout << left << setw(20) << "Preferred location:" << dimensions.x << ", " << dimensions.y << endl;
    cout << left << setw(20) << "Size:" << dimensions.width << ", " << dimensions.height << endl;
    cout << left << setw(20) << "Text:" << text << endl;
}
