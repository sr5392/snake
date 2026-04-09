#ifndef SNAKE_FOOD_HPP
#define SNAKE_FOOD_HPP

class Snake;

class Food {
public:
    Food();

    void update(const Snake& snake);

    [[nodiscard]] bool check_collision_snake(const Snake&) const;

    [[nodiscard]] int get_x() const;

    [[nodiscard]] int get_y() const;

private:
    int m_x;
    int m_y;
};

#endif //SNAKE_FOOD_HPP
