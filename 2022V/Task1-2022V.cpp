//
// Created by Øyvind Bjøntegaard on 28/11/2022.
//

#include <iostream>
#include <vector>
using namespace std;

//TASK 1

int times_two(int value){
    return value * 2;
}

double times_two(double value){
    return value * 2;
}

string times_two(string value){
    return value + value;
}

vector<int> times_two(const vector<int> &vec){
    vector<int> result;
    result.reserve(vec.size());
    for (auto e: vec)
        result.emplace_back(e * 2);
    return result;
}
ostream &operator<<(ostream &stream, const vector<int> &vec){
    stream << "{ ";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i != 0)
            stream << ", ";
        stream << vec[i];
    }
    return stream << " }";
}


int main(){

    //TASK 1
    cout << "TASK1: " << endl;
    cout << times_two(2) << endl;
    cout << times_two(2.25) << endl;
    cout << times_two("test") << endl;
    cout << times_two(vector<int>{1, 2, 3}) << endl;

    /*
     * OUPUT:
     * 4
     * 4.5
     * testtest
     * { 2, 4, 6 }
     */
    return 0;
}