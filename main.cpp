#include "raylib.h"
#include "renderer.hpp"
#include "game.hpp"


int main() {
    InitWindow(1500, 1500, "Snake");
    SetTargetFPS(60);

    Renderer renderer;
    Game game{renderer};
    game.run();

    CloseWindow();
    return 0;
}
