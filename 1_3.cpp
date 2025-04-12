using namespace std;
#include <cstdio>
#include <algorithm>
#include <chrono>
#include <string>
#include <thread>
#include <cmath>
#include <array>
template <typename T, size_t N>
class Vector final {
    public:
    static_assert(
        N > 0,
        "Size of static-sized vector should be greater than zero."
    );
    static_assert(
        std::is_floating_point<T>::value,
        "Vector only can be instantiated with floating point types"
    );
    
    Vector();

    template <typename... Params>
    explicit Vector(Params... params);

    explicit Vector(const std::initializer_list<T>& lst);

    Vector(const Vector& other);

    void set(const std::initializer_list<T>& lst);

    void set(const Vector& other);

    Vector& operator=(const std::initializer_list<T>& lst);

    Vector& operator=(const Vector& other);

    const T& operator[] (std::size_t i) const;

    T& operator[] (std::size_t);

    private:
    std::array<T,N> _elements;
};
//結局はstd::arrayの応用

//使用例
// Vector<float, 3> v1;   // サイズ3のfloat型ベクトル（OK）
// Vector<double, 5> v2;  // サイズ5のdouble型ベクトル（OK）
// Vector<int, 3> v3;     // エラー: int型は許可されない
// Vector<float, 0> v4;   // エラー: サイズは正の値でなければならない

