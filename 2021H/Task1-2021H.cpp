//
// Created by Øyvind Bjøntegaard on 28/11/2022.
//
#include <iostream>
using namespace std;

//TASK 1
bool starts_with(const char *str, const char *test) noexcept {
    for (; *test != '\0'; ++test) {
        if (*str == '\0')
            return false;
        if (*str != *test)
            return false;
        ++str;
    }
    return true;
}

bool starts_with(const string &str, const char *test) noexcept {
    return starts_with(str.c_str(), test);
}

int main(){
    //TASK 1
    cout << "TASK1: " << endl;
    cout << starts_with("", "") << endl;
    cout << starts_with(string(""), "") << endl;
    cout << starts_with("This is a test", "This") << endl;
    cout << starts_with(string("This is a test"), "This") << endl;
    cout << starts_with("This is a test", "Test") << endl;
    cout << starts_with(string("This is a test"), "Test") << endl;
    cout << starts_with("This", "This is a test") << endl;
    cout << starts_with(string("This"), "This is a test") << endl;

    /*
     * OUTPUT:
     * 1
     * 1
     * 1
     * 1
     * 0
     * 0
     * 0
     * 0
     */

    return 0;
}