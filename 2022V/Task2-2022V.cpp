//
// Created by Øyvind Bjøntegaard on 28/11/2022.
//
#include <iostream>
#include <vector>
using namespace std;

//TASK 2 A
class Build {
public:
    virtual ~Build() {}
    virtual string build() = 0;
};

class ProgrammingLanguage{
    unique_ptr<Build> _build;
public:
    ProgrammingLanguage() {}
    ProgrammingLanguage(unique_ptr<Build> build) : _build(std::move(build)){}

    virtual ~ProgrammingLanguage(){}
    virtual string print_line(const string &str) = 0;
    virtual string for_each(const string &e, const string &vec) = 0;

    string build(){
        return _build->build();
    }
};

class Cpp : public ProgrammingLanguage {
public:
    Cpp(){}
    Cpp(unique_ptr<Build> build) : ProgrammingLanguage(std::move(build)){}

    string print_line(const string &str) override {
        return "cout << \"" + str + "\" << endl;";
    };

    string for_each(const string &e, const string &vec) override {
        return "for(auto &" + e + ": " + vec +") {}";
    };
};

class Rust : public ProgrammingLanguage {
public:
    Rust() {}
    Rust(unique_ptr<Build> build) : ProgrammingLanguage(std::move(build)){}

    string print_line(const string &str) override {
        return "println!(\"" + str + "\");";
    };

    string for_each(const string &e, const string &vec) override {
        return "for " + e + " int &" + vec +" {}";
    };
};

//TASK 2 B
class CMake : public Build {
public:
    string build() override {
        return "cmake --build .";
    }
};

class Meson : public Build {
public:
    string build() override {
        return "meson compile -C .";
    }
};

class Cargo : public Build {
public:
    string build() override {
        return "cargo build";
    }
};


int main(){

    //TASK 2 A
    cout << "TASK2 A: " << endl;
    vector<unique_ptr<ProgrammingLanguage>> programming_languagesA;
    // Uncommenting the following line should cause compilation error:
    //programming_languagesA.emplace_back(make_unique<ProgrammingLanguage>());
    programming_languagesA.emplace_back(make_unique<Cpp>());
    programming_languagesA.emplace_back(make_unique<Rust>());
    for (auto &programming_language : programming_languagesA) {
        cout << programming_language->print_line("Hello World") << endl;
        cout << programming_language->for_each("e", "vec") << endl
             << endl;
    }

    /*
     * OUTPUT:
     * cout << "Hello World" << endl;
     * for(auto &e: vec) {}
     * println!("Hello World");
     * for e in &vec {}
     */


    //TASK 2 B
    cout << "TASK2 B: " << endl;
    vector<unique_ptr<ProgrammingLanguage>> programming_languagesB;
    programming_languagesB.emplace_back(make_unique<Cpp>(make_unique<CMake>
                                                                ()));
    programming_languagesB.emplace_back(make_unique<Cpp>(make_unique<Meson>
                                                                ()));
    programming_languagesB.emplace_back(make_unique<Rust>
                                               (make_unique<Cargo>()));
    for (auto &programming_language : programming_languagesB) {
        cout << programming_language->build() << endl;
    }

    /*
     * OUTPUT:
     * cmake --build .
     * meson compile -C .
     * cargo build
     */

    return 0;
}