#include "/opt/homebrew/include/raylib.h"
#include "Board.hpp"
Board::Board(){
    reset_board();
    }

Color neonPink = { 255, 0, 127, 255 };
Color CyberCyan = { 0, 242, 254, 255 };
Color MatrixGreen = { 57, 255, 20, 255 };

void Board::reset_board(){
    char count = '1';
    for(int r = 0; r < 3; r++){
        for(int c = 0; c < 3; c++){
            grid[r][c] = count;
            count++;
        }
    }
}

bool Board::is_position_available(int position){
    if(position < 1 || position > 9) return false;
    int index = position - 1;
    int rows = index / 3;
    int columns = index % 3;
    if(grid[rows][columns] == 'X' || grid[rows][columns] == 'O'){
        return false;
    }
    else return true;
}

void Board::place_mark(int position, char mark){
    int index = position - 1;
    int rows = index / 3;
    int columns = index % 3;
    grid[rows][columns] = mark;
}

bool Board::check_win(char mark){
    for(int i{}; i < 3; i++){
        if(grid[i][0] == mark && grid[i][1] == mark && grid[i][2] == mark) return true;
        if(grid[0][i] == mark && grid[1][i] == mark && grid[2][i] == mark) return true;
    }
    if (grid[0][0] == mark && grid[1][1] == mark && grid[2][2] == mark) return true;
    if (grid[0][2] == mark && grid[1][1] == mark && grid[2][0] == mark) return true;
    return false;
}

bool Board::check_draw(){
    for(int i{1}; i < 10 ; i++){
        if(is_position_available(i)) return false;
    }
    return true;
}

void Board::render_board(Texture2D xTex, Texture2D oTex){
    DrawLineEx({200.0f, 0.0f}, {200.0f, 600.0f}, 5.0f, neonPink);
    DrawLineEx({400.0f, 0.0f}, {400.0f, 600.0f}, 5.0f, neonPink);
    DrawLineEx({0.0f, 200.0f}, {600.0f, 200.0f}, 5.0f, neonPink);
    DrawLineEx({0.0f, 400.0f}, {600.0f, 400.0f}, 5.0f, neonPink);

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            
            int imageDrawX = (c * 200) + 20;
            int imageDrawY = (r * 200) + 20;

            if (grid[r][c] == 'X') {
                DrawTexture(xTex, imageDrawX, imageDrawY, CyberCyan); 
            } 

            else if (grid[r][c] == 'O') {
                DrawTexture(oTex, imageDrawX, imageDrawY, MatrixGreen);
            }
        }
    }
}