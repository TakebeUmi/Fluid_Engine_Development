#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T, size_t N>
class Array final {};

template <typename T>
class Array<T, 1> final {
    public:
        Array();
        T& operator[](size_t i);
        const T& operator[](size_t i) const;

        Size3 size() const;
        size_t width() const;
        size_t height() const;

    private:
        Size2 _size;
        vector<T> _data;
};

template <typename T> using Array1 = Array<T,1>;

template <typename T>
class Array<T,2> final {
    public:
        Array();

        T& operator() (size_t i, size_t j);
        const T& operator()(size_t i, size_t j) const;
        Size3 size() const;
        size_t width() const;
        size_t height() const;

        private:
            Size2 _size;
            vector<T> _data;
};

template <typename T> using Array2 = Array<T,2>;

template <typename T>
class Array<T,3> final{
    public:
        Array();

        T& operator()(size_t i, size_t j, size_t k);
        const T& operator()(size_t i, size_t j, size_t k) const;

        Size3 size() const;
        size_t width() const;
        size_t height() const;
        size_t depth() const;

    private:
        Size3 _
}