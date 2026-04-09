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

class Food;

class Snake {
public:
    Snake();

    void update(const Food& food);

    void set_direction(SnakeDirection direction);

    [[nodiscard]] SnakeDirection get_direction() const;

    [[nodiscard]] const std::vector<SnakeTile>& get_body() const;

    [[nodiscard]] bool check_collision_self() const;

    [[nodiscard]] bool check_collision_food(const Food&) const;

private:
    std::vector<SnakeTile> m_snake;
    SnakeDirection m_direction;
};

#endif
