#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include <vector>

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

    [[nodiscard]] bool check_collision() const;

    void set_direction(SnakeDirection direction);

    [[nodiscard]] SnakeDirection get_direction() const;

    std::vector<SnakeTile>& get_body();

    [[nodiscard]] const std::vector<SnakeTile>& get_body() const;

private:
    std::vector<SnakeTile> m_snake;
    SnakeDirection m_direction;
};

#endif
