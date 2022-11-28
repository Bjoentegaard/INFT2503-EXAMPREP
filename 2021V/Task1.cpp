#include <iostream>
#include <vector>
using namespace std;


//TASK 1
int getAnswer(){
    return 42;
}
void getAnswer(int& num){
    num = 42;
}
void getAnswer(int *&num){
    num = new int(42);
}
void getAnswer(const std::function<void(int)> &callback) {
    callback(42);
}



int main() {

    //TASK 1
    cout << getAnswer() << endl;
    int answer1;
    getAnswer(answer1);
    cout << answer1 << endl;
    int *answer2;
    getAnswer(answer2);
    cout << *answer2 << endl;
    delete answer2;
    getAnswer([](int answer) {
        cout << answer << endl;
    });
    /*
     * Output:
     * 42
     * 42
     * 42
     * 42
     */


    return 0;
}
