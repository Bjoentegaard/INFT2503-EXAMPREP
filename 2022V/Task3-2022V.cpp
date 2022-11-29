//
// Created by Øyvind Bjøntegaard on 28/11/2022.
//
#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class Angle{
public:
    T value;

    Angle(int value_) : value(value_ % 360) {}
    Angle(double value_) : value(fmod(value_, 3.14159265359)) {}

    template<typename T2>
    friend Angle<T> operator + (const Angle<T> &angle, T2 value_){
        return Angle<T>(angle.value + static_cast<T>(value_));
    }

    friend std::ostream &operator<<(std::ostream &os, Angle<T> angle){
        return os << angle.value;
    }
};

int main(){

    //TASK 3
    cout << "TASK3: " << endl;
    cout << Angle<int>(30) << endl;
    cout << (Angle<int>(30) + 360) << endl;
    cout << (Angle<int>(30) + 3.14159265359) << endl;
    cout << Angle<double>(3.14159265359 / 2) << endl;
    cout << (Angle<double>(3.14159265359 / 2) + 3.14159265359) << endl;
    cout << (Angle<double>(3.14159265359 / 2) + 3) << endl;

    /*
     * OUTPUT:
     * 30
     * 30
     * 33
     * 1.5708
     * 1.5708
     * 1.4292
     */


    return 0;
}