#include "renderer.hpp"
#include "snake.hpp"
#include "food.hpp"
#include "raylib.h"

void Renderer::draw_snake(const Snake& snake) {
    for (const auto& [x, y] : snake.get_body()) {
        DrawRectangle(x, y, 90, 90, WHITE);
    }
}

void Renderer::draw_food(const Food& food) {
    DrawRectangle(food.get_x(), food.get_y(), 90, 90, RED);
}
