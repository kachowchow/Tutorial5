#include <iostream>
using namespace std;

#include "TAArray.h"

TextAreaArray::TextAreaArray()
{
    size = 0;
    elements = new TextArea *[MAX_ARR];
}

TextAreaArray::~TextAreaArray()
{
    delete[] elements;
}

bool TextAreaArray::add(TextArea *ta)
{
    if (size >= MAX_ARR)
        return false;

    elements[size] = ta;
    size++;
    return true;
}

bool TextAreaArray::add(TextArea *ta, int index)
{
    if (size >= MAX_ARR || index < 0 || index > size)
        return false;

    for (int i = size; i > index; i--)
    {
        elements[i] = elements[i - 1];
    }

    elements[index] = ta;
    size++;
    return true;
}

TextArea *TextAreaArray::get(int index)
{
    if (index < 0 || index >= size)
        return nullptr;
    return elements[index];
}

TextArea *TextAreaArray::remove(int index)
{
    if (index < 0 || index >= size)
        return nullptr;

    TextArea *ta = elements[index];
    while (index < size - 1)
    {
        elements[index] = elements[index + 1];
        index++;
    }
    size--;
    return ta;
}

void TextAreaArray::print()
{
    cout << endl
         << "TextAreas:" << endl;
    for (int i = 0; i < size; i++)
    {
        elements[i]->print();
    }
    cout << endl;
}
