# 🌆 Cyberpunk Tic-Tac-Toe v3.0

A stylish, neon-infused Tic-Tac-Toe game built in C++ using the **Raylib** graphics library. Features an unbeatable AI opponent powered by the **Minimax Algorithm**.

## 🚀 Features
* **Cyberpunk Aesthetic**: Customized HUD colors (Neon Pink, Cyber Cyan, Matrix Green).
* **Smart AI**: Powered by a recursive Minimax decision tree.
* **Natively Compiled**: Smooth 60 FPS performance.

## 🛠️ Prerequisites
You need a C++ compiler and the Raylib library installed on your system.

### macOS Installation
```bash
brew install raylib
```

## 🏗️ Compilation & Running

Open your terminal in the project directory and run the following command:

```bash
g++ -std=c++17 *.cpp -I(brew --prefix)/include -L(brew --prefix)/lib -lraylib -o cyberpunk_game && ./cyberpunk_game
```

## 📂 Project Structure
* `main.cpp` - Entry point.
* `GameManager` - Controls game states, window loops, and AI execution.
* `Board` - Handles game grid calculations and Raylib rendering.
* `Player` - Simple class tracking player names and board marks ('X'/'O').
