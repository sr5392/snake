#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP
#include <vector>

class Renderer;
class Game;

struct SnakeTile {
    int x;
    int y;
};

enum class SnakeDirection {
    Up,
    Right,
    Down,
    Left
};

class Snake {
public:
    Snake();
    void update();
    void grow();
    bool check_collision();
    void set_direction(SnakeDirection direction);
    SnakeDirection get_direction() const;
    std::vector<SnakeTile>& get_snake_body();
private:
    std::vector<SnakeTile> m_snake;
    SnakeDirection m_direction;
};

#endif