#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include "food.hpp"
#include "snake.hpp"

class Renderer;

class Game {
public:
    explicit Game(Renderer& renderer);
    void run();
    void update();
    void draw();
    void handle_input();
private:
    Renderer &m_renderer;
    Snake m_snake;
    Food m_food;
};

#endif //SNAKE_GAME_HPP
