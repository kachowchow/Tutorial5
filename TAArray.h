#ifndef TAARRAY_H
#define TAARRAY_H

#define MAX_ARR 64

#include "TextArea.h"

class TAArray
{
public:
    TAArray();
    ~TAArray();

    bool add(TextArea *ta);
    bool add(TextArea *ta, int index);
    TextArea *get(int index) const;
    TextArea* get(const string& id) const;
    TextArea *remove(int index);
    TextArea* remove(const string& id);


    bool isFull() { return size == MAX_ARR; }
    int getSize() { return size; }
    void print();

private:
    TextArea **elements;
    int size;
};

#endif