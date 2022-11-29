//
// Created by Øyvind Bjøntegaard on 28/11/2022.
//
#include <iostream>
#include <vector>
#include <thread>


using namespace std;


//TASK 4
vector<int> parallell_transform(const vector<int> &a, const vector<int> &b, const std::function<int(int, int)> &callback){
    vector<int> result(a.size());
    std::vector<thread> threads;
    auto thread_size = thread::hardware_concurrency();
    threads.reserve(thread_size);
    for (size_t thread_num = 0; thread_num < thread_size; ++thread_num) {
        threads.emplace_back([thread_num, thread_size, &result, &a, &b, &callback]{
            for (size_t i = thread_num; i < a.size(); i+=thread_size)
                result[i] = callback(a[i], b[i]);
        });
    }
    for (auto &thread : threads)
        thread.join();
    return result;
}

ostream &operator<<(ostream &stream, const vector<int> &vec) {
    stream << "{ ";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i != 0)
            stream << ", ";
        stream << vec[i];
    }
    return stream << " }";
}

int main(){
    //TASK 4
    cout << "TASK4: " << endl;
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 4, 5, 6};
    cout << parallell_transform(a, b, [](int a_element, int b_element) {
        return a_element + b_element;
    }) << endl;

    cout << parallell_transform(a, b, [](int a_element, int b_element) {
        return a_element * b_element;
    }) << endl;

    /*
     * OUTPUT:
     * { 3, 5, 7, 9, 11 }
     * { 2, 6, 12, 20, 30 }
     */

    return 0;
}