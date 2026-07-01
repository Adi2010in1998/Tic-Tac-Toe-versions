#include "Player.hpp"
#include <string>
Player::Player(std::string playerName, char playerMark){
    name = playerName;
    mark = playerMark;
}
Player::Player(){
    name = "Nameless";
    mark = ' ';
}
std::string Player::get_name(){
    return name;
}
char Player::get_mark(){
    return mark;
}