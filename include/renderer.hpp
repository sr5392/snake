#ifndef SNAKE_RENDERER_HPP
#define SNAKE_RENDERER_HPP
#include <vector>

#include "food.hpp"

class Snake;
struct SnakeTile;

class Renderer {
public:
    void draw_snake(const Snake&);

    void draw_food(const Food&);
};

#endif //SNAKE_RENDERER_HPP
