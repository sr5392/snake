#include "game.hpp"
#include "snake.hpp"
#include "renderer.hpp"
#include "raylib.h"

Game::Game(Renderer& renderer) : m_renderer(renderer) {
};

void Game::run() {
    SnakeDirection direction = m_snake.get_direction();

    float accumulatedTime = 0;
    while (!WindowShouldClose()) {
        if (IsKeyDown('W')) direction = SnakeDirection::Up;
        if (IsKeyDown('A')) direction = SnakeDirection::Left;
        if (IsKeyDown('S')) direction = SnakeDirection::Down;
        if (IsKeyDown('D')) direction = SnakeDirection::Right;

        const float deltaTime = GetFrameTime();
        constexpr float interval = 0.25f;
        accumulatedTime += deltaTime;

        if (accumulatedTime >= interval) {
            m_snake.set_direction(direction);
            update();
            accumulatedTime -= interval;
        }

        if (check_collision_snake_wall() || m_snake.check_collision_self()) break;

        draw();
    }
}

void Game::update() {
    m_snake.update(m_food);
    m_food.update(m_snake);
}

void Game::draw() const {
    BeginDrawing();
    ClearBackground(BLACK);
    m_renderer.draw_food(m_food);
    m_renderer.draw_snake(m_snake);
    EndDrawing();
}

bool Game::check_collision_snake_head_food() const {
    const auto& [x, y] = m_snake.get_body().front();
    if (m_food.get_x() == x && m_food.get_y() == y) return true;
    return false;
}

bool Game::check_collision_snake_wall() const {
    const auto& [head_x, head_y] = m_snake.get_body().front();
    if (head_x >= 1500 || head_x < 0) return true;
    if (head_y >= 1500 || head_y < 0) return true;
    return false;
}
