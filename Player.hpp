#pragma once
#include <string>
class Player{
    private:
        std::string name{};
        char mark{};
    public:
        Player();
        Player(std::string playerName, char playerMark);
        std::string get_name();
        char get_mark();
};
