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

        void forEachIndex(
            const function<void(size_t, size_t, size_t)>& func )const;
        
        void parallelForEachIndex(
            const function<void(size_t, size_t, size_t)>& func) const;
        
        ArrayAccessor3<T> accessor();
        ConstArrayAccessor3<T> constAccessor() const;

    private:
        Size3 _size;
        vector<T> _data;
};

template <typename T> using Array3 = Array<T,3>;

template <typename T>
T& Array<T,2>::operator()(size_t i, size_t j) {
    return _data[i + _size.x * j];
}

template <typename T>
const T& Array<T, 2>::operator()(size_t i, size_t j) const {
    return _data[i + _size.x * j];
};

template <typename T>
T& Array<T,3>::operator()(size_t i, size_t j, size_t k) {
    _data[i + _size.x * (j + _size.y * k)];
}

template <typename T>
const T& Array<T,3>::operator() (size_t i, size_t j, size_t k)const{
    return _data[i + _size.x * (j + _size.y * k)];
}

template <typename T, size_t N> 
class ArrayAccessor final{};

template <typename T>
class ArrayAccessor<T, 3> final {
    public:
        ArrayAccessor();
        explicit ArrayAccessor(const size3& size, T* const data);

        T& operator()(size_t i, size_t j, size_t k);
        const T& operator()(size_t i, size_t j, size_t k) const;

        Size3 size() const;
        size_t width() const;
        size_t height() const;
        size_t depth() const;
    
    private:
        Size3 _size;
        T* _data;
};

template <typename T> using ArrayAccessor3 = ArrayAccessor<T, 3>;

template <typename T, size_t N>
class ConstArrayAccessor final{};

template <typename T>
class ConstArrayAccessor<T,3> {
    public:
        ConstArrayAccessor<T, 3>();
        explicit ConstArrayAccessor(const Size3& size, const T* data);

        const T& operator()(size_t i, size_t j, size_t k) const;

        Size3 size() const;
        size_t width() const;
        size_t height() const;
        size_t depth() const;
    
        private:
            Size3 _size;
            T* _data;
};

template <typename T> using ConstArrayAccessor3 = ConstArrayAccessor<T,3>;

// template <typename T>
// ArrayAccessor3<T> Array<T,3>::accessor() {
//     return ArrayAccessor3<T>(size(), data());
// } dataを定義しないといけないのでいったんコメントアウト
