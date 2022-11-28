//
// Created by Øyvind Bjøntegaard on 28/11/2022.
//
#include <iostream>
using namespace std;

//TASK 4
class Meter{
public:
    const static unsigned int multiplier = 1;
};

class Kilometer{
public:
    const static unsigned int multiplier = 1000;
};

template<class T>
class Distance {
public:
    unsigned int meters;

    Distance(unsigned int units) : meters(units * T::multiplier){}

    Distance &operator += (unsigned int units) {
        this->meters += units * T::multiplier;
        return *this;
    }

    Distance operator+(const Distance<Meter> &other) {
        auto result = *this;
        result.meters += other.meters;
        return result;
    }

    friend ostream &operator<<(ostream &stream, const Distance<T> &distance) {
        return stream << distance.meters << "m";
    }
};




int main(){
    //TASK 4
    Distance<Meter> meters(2);
    meters += 3;
    Distance<Kilometer> kilometers(2);
    kilometers += 3;
    cout << "5 meters: " << meters << endl;
    cout << "5 kilometers: " << kilometers << endl;
    cout << "5 kilometers + 5 meters: " << kilometers + meters << endl;

    /*
     * OUTPUT:
     * 5 meters: 5m
     * 5 kilometers: 5000m
     * 5 kilometers + 5 meters: 5005m
     */

    return 0;
}