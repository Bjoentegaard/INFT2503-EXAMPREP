//
// Created by Øyvind Bjøntegaard on 28/11/2022.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//TASK 3
template <typename T>
class Angle{
public:
    T value;

    Angle(int value_) : value(value_ % 360) {}
    Angle(double value_) : value(fmod(value_, 3.14159265359)) {}

    friend std::ostream &operator<<(std::ostream &os, Angle<T> angle){
        return os << angle.value;
    }
};


int main(){
    //TASK 3
    Angle<int> angle1(30);
    cout << angle1 << endl;
    Angle<int> angle2(390);
    cout << angle2 << endl;
    Angle<double> angle3(3.14159265359 / 2);
    cout << angle3 << endl;
    Angle<double> angle4(3.14159265359 * 1.5);
    cout << angle4 << endl;

    /*
     * OUTPUT:
     * 30
     * 30
     * 1.5708
     * 1.5708
     */

    return 0;
}