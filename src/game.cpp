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
    bool grow = check_collision_snake_food();
    m_snake.update(grow);
    if (grow) m_food.respawn();
}

void Game::handle_input() {
    return;
}

void Game::draw() {
    BeginDrawing();
    ClearBackground(BLACK);
    m_renderer.draw_food(m_food);
    m_renderer.draw_snake(m_snake);
    EndDrawing();
}

bool Game::check_collision_snake_food() {
    auto [x, y] = m_snake.get_body().front();
    switch (m_snake.get_direction()) {
        case SnakeDirection::Up: y -= 100;
            break;
        case SnakeDirection::Down: y += 100;
            break;
        case SnakeDirection::Left: x -= 100;
            break;
        case SnakeDirection::Right: x += 100;
            break;
    }
    if (m_food.x == x && m_food.y == y) return true;
    return false;
}
