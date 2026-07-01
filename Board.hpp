#pragma once
extern "C" {
    #include "/opt/homebrew/include/raylib.h"
}
class Board{
    private:
        char grid[3][3];
    public:
        Board();
        void reset_board();
        void place_mark(int position, char mark);
        void render_board(Texture2D xTex, Texture2D oTex);
        bool is_position_available(int position);
        bool check_win(char mark);
        bool check_draw();
};