//
// Created by Øyvind Bjøntegaard on 28/11/2022.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


//TASK 5
std::vector<int> operator*(const std::vector<int> &input, int num) {
    std::vector<int> result;
    result.reserve(input.size());
    for (auto &val : input)
        result.emplace_back(val * num);
    return result;
}

std::vector<int> operator*(const std::vector<int> &input1, const std::vector<int> &input2) {
    std::vector<int> result;
    result.reserve(input1.size());
    for (size_t i = 0; i < input1.size() && i < input2.size(); ++i)
        result.emplace_back(input1[i] * input2[i]);
    return result;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
    if (vec.empty()) {
        os << "{}";
        return os;
    }

    os << "{ ";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i + 1 != vec.size())
            os << ", ";
    }
    os << " }";
    return os;
}

int main(){

    // TASK 5
    cout << std::vector<int>() << endl;
    cout << std::vector<float>({1.5, 2.5}) << endl;
    std::vector<int> vec = {1, 2, 3};
    cout << vec << endl;
    cout << vec * 3 << endl;
    cout << vec * vec << endl;

    /*
     * OUTPUT:
     * {}
     * { 1.5, 2.5 }
     * { 1, 2, 3 }
     * { 3, 6, 9 }
     * { 1, 4, 9 }
     */

    return 0;
}