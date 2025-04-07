#pragma once
#include <iostream>
using namespace std;

template <typename T, size_t N>
class Array final {};

template <typename T>
class Array<T, 1> final {
    public:
        Array();
        T& operator[](size_t i);
        const T& operator[](size_t i) const;
}