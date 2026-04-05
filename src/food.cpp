#include "food.hpp"
#include <random>

Food::Food() : m_x{1200}, m_y{400} {
}

int Food::get_x() const {
    return m_x;
}

int Food::get_y() const {
    return m_y;
}

static int get_random_number() {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(1, 225);
    return distr(eng);
}

void Food::update() {
    const int random_field = get_random_number();
    m_x = (random_field % 15) * 100;
    m_y = (random_field / 15) * 100;
}
