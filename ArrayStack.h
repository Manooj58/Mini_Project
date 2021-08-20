#pragma once

#include <iostream>
using namespace std;

class ArrayStack
{
private:
    int array_size;
    int *data;
    int rear;

public:
    ArrayStack();
    ~ArrayStack();
    void push(int element);
    void pop();
    int top();
};
