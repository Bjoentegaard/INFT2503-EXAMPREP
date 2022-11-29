//
// Created by Øyvind Bjøntegaard on 28/11/2022.
//
#include <iostream>
#include <vector>
using namespace std;

//class Chess {
//public:
//    enum class Player { white,
//        black };
//    static string player_name(Player player) {
//        if (player == Player::white)
//            return "white";
//        else
//            return "black";
//    }
//    function<void(Player winner)> on_victory;
///// In this game, black always wins
//    void play() {
//        if (on_victory)
//            on_victory(Player::black);
//    }
//};

class Chess {
public:
    enum class Player { white,
        black };
    static string player_name(Player player) {
        if (player == Player::white)
            return "white";
        else
            return "black";
    }
    vector<function<void(Player winner)>> on_victory; //EDITED
/// In this game, black always wins
    void play() {
        for (auto &f: on_victory) {
            f(Player::black);
        }
    }
};

int main(){

    cout << "TASK3: " << endl;
    Chess chess;
    chess.on_victory.emplace_back([](Chess::Player winner) {
        cout << Chess::player_name(winner) << " won" << endl;
    });
    chess.on_victory.emplace_back([](Chess::Player winner) {
        cout << Chess::player_name(winner == Chess::Player::white
                                   ? Chess::Player::black
                                   : Chess::Player::white)
             << " lost" << endl;
    });
    chess.play();

    /*
     * OUTPUT:
     * black won
     * white lost
     */


    return 0;
}
