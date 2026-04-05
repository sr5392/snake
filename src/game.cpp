#include "game.hpp"
#include "renderer.hpp"
#include "raylib.h"
#include <iostream>

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

        if (check_collision_snake_wall() || check_collision_snake_self()) break;

        draw();
    }
}

void Game::update() {
    m_snake.update();
    if (check_collision_snake_head_food()) {
        while (check_collision_snake_body_food()) m_food.update();
    } else {
        m_snake.get_body().pop_back();
    }
}

void Game::draw() {
    BeginDrawing();
    ClearBackground(BLACK);
    m_renderer.draw_food(m_food);
    m_renderer.draw_snake(m_snake);
    EndDrawing();
}

bool Game::check_collision_snake_head_food() const {
    auto [head_x, head_y] = m_snake.get_body().front();
    if (m_food.get_x() == head_x && m_food.get_y() == head_y) return true;
    return false;
}

bool Game::check_collision_snake_body_food() const {
    for (const auto& tile: m_snake.get_body()) {
        if (m_food.get_x() == tile.x && m_food.get_y() == tile.y) return true;
    }
    return false;
}

bool Game::check_collision_snake_wall() const {
    const auto& [head_x, head_y] = m_snake.get_body().front();
    if (head_x >= 1500 || head_x < 0) return true;
    if (head_y >= 1500 || head_y < 0) return true;
    return false;
}

bool Game::check_collision_snake_self() const {
    const auto& head = m_snake.get_body().front();
    const auto& body = m_snake.get_body();
    for (auto i = body.begin() + 1; i != body.end(); ++i) {
        const SnakeTile& current = *i;
        if (current.x == head.x && current.y == head.y) return true;
    }
    return false;
}
