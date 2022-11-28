//
// Created by Øyvind Bjøntegaard on 28/11/2022.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <thread>
using namespace std;

//TASK 4
void parallell_transform(std::vector<int> &vec, size_t thread_size, const std::function<int(int)> &callback) {
    std::vector<thread> threads;
    threads.reserve(thread_size);
    for (size_t thread_num = 0; thread_num < thread_size; thread_num++) {
        threads.emplace_back([thread_num, thread_size, &vec, &callback]{
            for (size_t i = thread_num; i < vec.size(); i += thread_size)
                vec[i] = callback(vec[i]);
        });
    }
    for (auto &thread : threads) {
        thread.join();
    }
}

int main() {
    //TASK 4
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    parallell_transform(vec, 4, [](int e) {
        return e * 2;
    });
    for (auto &e : vec)
        cout << e << endl;

    /*
     * OUTPUT:
     * 2
     * 3
     * 6
     * 8
     * 10
     * 12
     */

    return 0;
}
