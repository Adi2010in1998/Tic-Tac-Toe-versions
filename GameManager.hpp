#pragma once
#include "Board.hpp"
#include "Player.hpp"
extern "C" {
    #include "/opt/homebrew/include/raylib.h"
}
class GameManager{
    private:
        Board game_board;
        Player p1;
        Player p2;
        Player *current_player;
        std::string status_text;
        Texture2D xTexture;
        Texture2D oTexture;
        Vector2 get_mouse_coordinates();
        int get_valid_move();
        void switch_turn();
        void init_window();
        void update_window();
        Texture2D load_and_resize(std::string);
        bool game_active{true};
    public:
        GameManager();
        void play_game();
};