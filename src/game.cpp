#include "game.hpp"
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
        constexpr float interval = 0.5f;
        accumulatedTime += deltaTime;

        if (accumulatedTime >= interval) {
            m_snake.set_direction(direction);
            update();
            accumulatedTime -= interval;
        }

        draw();
    }
}

void Game::update() {
    m_snake.update();
}

void Game::handle_input() {
    return;
}

void Game::draw() {
    BeginDrawing();
    ClearBackground(BLACK);
    m_renderer.draw_snake(m_snake.get_snake_body());
    EndDrawing();
}
