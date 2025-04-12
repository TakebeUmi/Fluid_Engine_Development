#include <algorithm>
#include <numeric>
#include <functional>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T, size_t N>
class Vector final {
    public:
        static_assert(
            N > 0,
            "Size of static-sized vector should be greater than zero."
        );
        static_assert(
            is_floating_point<T>::value,
            "Vector only can be instatinated with floating point types"
        );

        Vector();

        template <typename ...Params>
        explicit Vector( Params... params);

        explicit Vector(const initializer_list<T>& lst);

        Vector(const Vector& other);

        void set(const initializer_list<T>& lst);

        void set(const Vector& other);

        Vector& operator=(const initializer_list<T>& lst);

        Vector& operator=(const Vector& other);

        const T& operator[](size_t i) const;

        T& operator[](size_t);
    
    private:
        array<T,N> _elements;
};

template <typename T> using Vector3 = Vector<T,3>;

typedef Vector3<float> Vector3F;
typedef Vector3<double> Vector3D;

template <typename T>
class Vector<T, 3> final {
    public:
        Vector add(T v)const;
        Vector sub(const Vector& v) const;
        Vector mul(T v) const;
        Vector mul(const Vectopr& v) const;
        Vector div(T v);
        Vector div(const Vector& v) const;
        T x;
        T y;
        T z;
};

template <typename T>
Vector<T,3> Vector<T,3>::add(T v) const {
    return Vector(x + v, y + v, z + v);
}

template <typename T>
Vector<T, 3> Vector<T,3>::add(T v) const {
    return Vector(x + v, y + v, z + v);
}

template <typename T>
Vector<T,3> operator+(const Vector<T,3>& a, T b) {
    return a.add(b);
}

template <typename T>
Vector<T,3> operator+(T a, const Vector<T,3>& b) {
    return b.add(a);
}

template <typename T>
Vector<T,3> operator+(const Vector<T,3>& a, const Vector<T,3>&b) {
    return a.add(b);
}