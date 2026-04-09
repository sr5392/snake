#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include "food.hpp"
#include "snake.hpp"

class Renderer;
class Food;

class Game {
public:
    explicit Game(Renderer& renderer);

    void run();

    void update();

    void draw() const;

    [[nodiscard]] bool check_collision_snake_head_food() const;

    [[nodiscard]] bool check_collision_snake_wall() const;

private:
    Renderer& m_renderer;
    Snake m_snake;
    Food m_food;
};

#endif //SNAKE_GAME_HPP
