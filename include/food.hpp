#ifndef SNAKE_FOOD_HPP
#define SNAKE_FOOD_HPP

class Food {
public:
    Food();

    void update();

    [[nodiscard]] int get_x() const;

    [[nodiscard]] int get_y() const;

private:
    int m_x;
    int m_y;
};

#endif //SNAKE_FOOD_HPP
