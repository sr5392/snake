#ifndef SNAKE_FOOD_HPP
#define SNAKE_FOOD_HPP

struct Food {
    int x;
    int y;

    Food();

    void respawn();
};
#endif //SNAKE_FOOD_HPP
