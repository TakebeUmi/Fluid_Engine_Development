#include <iostream>
#include <chrono>
#include <functional>
using namespace std;

class test_class_1 {
    private:
        int base;
        
    public:
        test_class_1(int baseValue) : base(baseValue) {};
        int operator() (int i) const {
            return base + i;
        }
        int adding(function<void(int,int)>& func) const;
};



int main(){
    //using A = B;の使い方。Bという既存の方をAとおく
    // using INT = int;
    // INT a = 4;
    //typedef A B;Aという既存の型にBという名前を与える
    // typedef INT Int;
    //C++11以降ではusingの使用が推奨される。usingを使うとtemplateを使用して型の定義ができる
    test_class_1 add3(3);
    cout << "3 + 5 = " << add3(5) << endl;
    test_class_1 adding_(3);
    int result = adding_.adding([] (int x,int y) {
        return x + y;
    });
    int a = 3;
    int b = 4;
    cout << adding_.adding(a,b) << endl;
    return 0;

};