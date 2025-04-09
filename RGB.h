#ifndef RGB_H
#define RGB_H

class RGB
{
public:
    int red, green, blue;

    RGB(int red, int green, int blue);

    void print() const;

    RGB getColour() const;

    unsigned long getColour();

    void setColour(const RGB &color);

    static RGB WHITE();
    static RGB BLACK();
    static RGB RED();
    static RGB GREEN();
    static RGB BLUE();
};

#endif
