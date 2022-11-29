//
// Created by Øyvind Bjøntegaard on 28/11/2022.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//TASK 2
class Button{
public :
    Button(std::string label_, std::function<void()> on_click_) : label(std::move(label_)), on_click(std::move(on_click_)){}
    virtual ~Button(){};

    std::string label;
    std::function<void()> on_click;
    virtual std::string string() const = 0;

    virtual void activate(){
        if (on_click)
            on_click();
    }

    friend ostream &operator<<(ostream& stream, const Button& button){
        return stream << button.string();
    }
};

class ToggleButton : public Button {
public:
    bool value;
    ToggleButton(std::string label, bool default_value, std::function<void()> on_click) : Button(std::move(label), std::move(on_click)), value(default_value){}

    void activate() override {
        value = !value;
        Button::activate();
    }
    std::string string() const override {
        return "ToggleButton, label:" + label + ", value: " + (value ? "toggled" : "not toggled");
    }
};

class LinkButton : public Button {
public:
    std::string link;
    LinkButton(std::string label, std::string link_, std::function<void()> on_click) : Button(std::move(label), std::move(on_click)), link(std::move(link_)){}

    void activate() override {
        Button::activate();
    }
    std::string string() const override {
        return "LinkButton, label: " + label + ", link: " + link;
    }

};

int main(){
    cout << "TASK2: " << endl;
    //TASK 2
    std::vector<std::unique_ptr<Button>> buttons;
    buttons.emplace_back(std::make_unique<ToggleButton>("Toggle something", true, [] {
        cout << "Toggled something" << endl;
    }));
    buttons.emplace_back(std::make_unique<LinkButton>("Link to somewhere","https://ntnu.no", [] {
        cout << "Opened link" << endl;
    }));
    for (auto &button : buttons) {
        cout << *button << endl;
        button->activate();
        cout << *button << endl;
    }

    /*
     * ToggleButton, label: Toggle something, value: toggled
     * Toggled something
     * ToggleButton, label: Toggle something, value: not toggled
     * LinkButton, label: Link to somewhere, link: https://ntnu.no
     * Opened link
     * LinkButton, label: Link to somewhere, link: https://ntnu.no
     */
    return 0;
}