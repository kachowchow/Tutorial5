#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <string>
#include "RGB.h"
#include "defs.h"
#include <X11/Xlib.h>

using namespace std;

class TextArea
{
public:
    TextArea(int x, int y, int width, int height, string id, string label, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());

    TextArea(Rectangle dimensions, string id, string label, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());

    string getId() const { return id; }
    string getText() const { return text; }
    Rectangle getDimensions() const { return dimensions; }
    RGB getFill() const { return fill; }
    RGB getBorder() const { return border; }

    //int getWidth() const { return dimensions.getWidth(); }
    //int getHeight() const { return dimensions.getHeight(); }

    //void setHeight(int height) { dimensions.setHeight(height); }

    void setText(const string &newText) { text = newText; }
    void setDimensions(const Rectangle &newDimensions) { dimensions = newDimensions; }
    void setFill(const RGB &newFill) { fill = newFill; }
    void setBorder(const RGB &newBorder) { border = newBorder; }

    // void draw(Display *display, Window win, GC gc, int x, int y);

    bool overlaps(TextArea &ta);

    void print() const;

private:
    Rectangle dimensions;
    string text;
    string id;
    RGB fill;
    RGB border;
};

#endif
