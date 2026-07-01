extern "C" {
   #include <raylib.h>
}
#include "GameManager.hpp"
#include <string>
Color ObsidianBlack = { 10, 10, 15, 255 };
Color CyberpunkHUD  = { 0, 242, 254, 255 };

GameManager::GameManager(){
    p1 = Player("Player 1", 'X');
    p2 = Player("Player 2", 'O');
    current_player = &p1;
    status_text = "<<PLAYER - 1'S TURN[X]>>";
    init_window();
}

Texture2D GameManager::load_and_resize(std::string filePath){
    Image img = LoadImage(filePath.c_str());
    ImageResize(&img, 160, 160);
    Texture2D tex = LoadTextureFromImage(img);
    UnloadImage(img);
    return tex; 
}

void GameManager::init_window(){
    InitWindow(600, 650, "CYBERPUNK TIC-TAC-TOE v3.0");
    SetTargetFPS(60);
    xTexture = load_and_resize("x_asset.png"); 
    oTexture = load_and_resize("o_asset.png");
}

Vector2 GameManager::get_mouse_coordinates(){
    return GetMousePosition();
}

int GameManager::get_valid_move(){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        Vector2 mouse_pos = get_mouse_coordinates();
        if(mouse_pos.x >= 0 && mouse_pos.x <= 600 && mouse_pos.y >= 0 && mouse_pos.y<= 600){
            int col = (int)mouse_pos.x / 200;
            int row = (int)mouse_pos.y / 200;
            return (row * 3) + col + 1;
        }
    }
    return -1;
}

void GameManager::switch_turn(){
    (current_player == &p1) ? (current_player = &p2) : (current_player = &p1);
    status_text = current_player->get_name() + "'S TURN [" + current_player->get_mark() + "]";
}

void GameManager::play_game(){
    game_board.reset_board();
    while(!WindowShouldClose()){
        update_window();
    }
    UnloadTexture(xTexture);
    UnloadTexture(oTexture);
    CloseWindow();
}

void GameManager::update_window() {
    if (game_active) {
        int chosenMove = get_valid_move();
        
        if (chosenMove != -1 && game_board.is_position_available(chosenMove)) {
            game_board.place_mark(chosenMove, current_player->get_mark());

            if (game_board.check_win(current_player->get_mark())) {
                status_text = current_player->get_name() + " WINS!!!";
                game_active = false; 
            } 
            else if (game_board.check_draw()) {
                status_text = "NO-ONE WINS!!!";
                game_active = false; 
            } 
            else {
                switch_turn(); 
            }
        }
    }
    BeginDrawing();
    ClearBackground(ObsidianBlack);
    game_board.render_board(xTexture, oTexture);
    DrawText(status_text.c_str(), 20, 615, 22, CyberpunkHUD);
    EndDrawing();
}
