#include "food.hpp"
#include "snake.hpp"
#include <random>

class Snake;

Food::Food() : m_x{1200}, m_y{400} {
}

int Food::get_x() const {
    return m_x;
}

int Food::get_y() const {
    return m_y;
}

static int get_random_number() {
    static std::default_random_engine eng(std::random_device{}());
    static std::uniform_int_distribution<int> dist(1, 225);
    return dist(eng);
}

void Food::update(const Snake& snake) {
    while (check_collision_snake(snake)) {
        const int random_field = get_random_number();
        m_x = (random_field % 15) * 100;
        m_y = (random_field / 15) * 100;
    }
}

bool Food::check_collision_snake(const Snake& snake) const {
    for (const auto& [x, y]: snake.get_body()) {
        if (m_x == x && m_y == y) return true;
    }
    return false;
}
