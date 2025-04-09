#ifndef TEXTAREAARRAY_H
#define TEXTAREAARRAY_H

#define MAX_ARR 64

#include "TextArea.h"

class TextAreaArray
{
public:
    TextAreaArray();
    ~TextAreaArray();

    bool add(TextArea *ta);
    bool add(TextArea *ta, int index);
    TextArea *get(int index);
    TextArea *remove(int index);

    bool isFull() { return size == MAX_ARR; }
    int getSize() { return size; }
    void print();

private:
    TextArea **elements;
    int size;
};

#endif