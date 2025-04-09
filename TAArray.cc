#include <iostream>
using namespace std;

#include "TAArray.h"

TAArray::TAArray()

{
    size = 0;
    elements = new TextArea *[MAX_ARR];
}

TAArray::~TAArray()


{
    delete[] elements;
}

bool TAArray::add(TextArea *ta)
{
    if (size >= MAX_ARR)
        return false;

    elements[size] = ta;
    size++;
    return true;
}

bool TAArray::add(TextArea *ta, int index)
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

TextArea *TAArray::get(int index) const
{
    if (index < 0 || index >= size)
        return nullptr;
    return elements[index];
}

TextArea* TAArray::get(const string& id) const {
    for (int i = 0; i < size; ++i) {
        if (elements[i]->getId() == id) {
            return elements[i];
        }
    }
    return nullptr;
}

TextArea *TAArray::remove(int index)
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

TextArea* TAArray::remove(const string& id) {
    for (int i = 0; i < size; ++i) {
        if (elements[i]->getId() == id) {
            return remove(i); 
        }
    }
    return nullptr;
}

void TAArray::print()
{
    cout << endl
         << "TextAreas:" << endl;
    for (int i = 0; i < size; i++)
    {
        elements[i]->print();
    }
    cout << endl;
}
