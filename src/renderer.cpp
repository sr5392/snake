#include "snake.hpp"
#include "renderer.hpp"
#include "raylib.h"

void Renderer::draw_snake(const Snake& snake) {
    for (const SnakeTile& t: snake.get_body()) {
        DrawRectangle(t.x, t.y, 90, 90, WHITE);
    }
}

void Renderer::draw_food(const Food& food) {
    DrawRectangle(food.x, food.y, 90, 90, RED);
}
