//
// Created by Øyvind Bjøntegaard on 28/11/2022.
//
#include <iostream>
#include <vector>
using namespace std;

//TASK 5
class Find {
public:
    std::function<bool(int)> func;
    Find(const std::function<bool(int)> &func) : func(func) {}
};

std::unique_ptr<int> operator|(const std::vector<int> &input, const Find &find){
    std::vector<int> result;
    for (auto &e : input) {
        if (find.func(e))
            return std::make_unique<int>(e);
    }
    return nullptr;
}

class Reduce {
public:
    std::function<int(int, int)> func;
    int initial_value;
    Reduce(const std::function<int(int, int)> &func, int initial_value) : func(func), initial_value(initial_value) {}
};

int operator | (const std::vector<int> &input, const Reduce &reduce){
    int previous_value = reduce.initial_value;
    for (auto &e : input) {
        previous_value = reduce.func(previous_value, e);
    }
    return previous_value;
}



int main(){
    //TASK 5
    cout << "TASK 5: " << endl;
    vector<int> vec = {1, 2, 3};
    cout << *(vec | Find([](int value) { return value > 1; })) << endl;
    cout << (vec | Find([](int value) { return value == 5; })) << endl;
    cout << (vec | Reduce(
            [](int previous_value, int current_value) {
                return previous_value + current_value;
            },
            0 /* initial value */))
         << endl;
    cout << (vec | Reduce(
            [](int previous_value, int current_value) {
                return previous_value + 2 * current_value;
            },
            5 /* initial value */))
         << endl;


    /*
     * OUTPUT:
     * 2
     * 0x0
     * 6
     * 17
     */

    return 0;
}
