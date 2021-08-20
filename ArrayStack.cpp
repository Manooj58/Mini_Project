#include <iostream>
#include "ArrayStack.h"
using namespace std;

ArrayStack::ArrayStack()
{
    data = new int[20];
    rear = -1;
}

ArrayStack::~ArrayStack()
{
    delete[] data;
}

void ArrayStack::push(int element)
{
    rear++;
    data[rear] = element;
}

void ArrayStack::pop()
{
    rear--;
}

int ArrayStack::top()
{

    return data[rear];
}