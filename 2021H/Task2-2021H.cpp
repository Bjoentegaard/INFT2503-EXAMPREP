//
// Created by Øyvind Bjøntegaard on 28/11/2022.
//
#include <iostream>
#include <vector>
using namespace std;


//TASK 2
class Animal{
public:
    virtual string produce() = 0;
    virtual ~Animal(){};
};

class Cow : public Animal{
public:
    string produce() override {
        return "milk";
    }
};
class Sheep : public Animal{
public:
    string produce() override {
        return "wool";
    }
};
class Chicken : public Animal{
public:
    string produce() override {
        return "egg";
    }
};


class Farm{
public:
    vector<unique_ptr<Animal>> animals;

    void add_animal(const string &animal_name){
        if (animal_name == "cow")
            animals.emplace_back(new Cow);
        else if (animal_name == "sheep")
            animals.emplace_back(new Sheep);
        else if (animal_name == "chicken")
            animals.emplace_back(new Chicken);
    };
};

int main(){
    //Task 2
    cout << "TASK2: " << endl;
    Farm farm;
    farm.add_animal("chicken");
    farm.add_animal("chicken");
    farm.add_animal("chicken");
    farm.add_animal("cow");
    farm.add_animal("sheep");
    farm.add_animal("sheep");
    cout << "Farm production: " << endl;
    for (auto &animal : farm.animals)
        cout << animal->produce() << endl;

    /*
     * OUTPUT:
     * Farm production:
     * egg
     * egg
     * egg
     * milk
     * wool
     * wool
     */

    return 0;
}
