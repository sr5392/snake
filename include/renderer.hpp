#ifndef SNAKE_RENDERER_HPP
#define SNAKE_RENDERER_HPP

class Snake;
class Food;

class Renderer {
public:
    void draw_snake(const Snake&);

    void draw_food(const Food&);
};

#endif //SNAKE_RENDERER_HPP
