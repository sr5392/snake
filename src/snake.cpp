#include "snake.hpp"
#include "food.hpp"

Snake::Snake() : m_direction{SnakeDirection::Right} {
    m_snake.reserve(255);
    m_snake.emplace_back(SnakeTile{400, 400});
    m_snake.emplace_back(SnakeTile{300, 400});
    m_snake.emplace_back(SnakeTile{200, 400});
}

void Snake::update(const Food& food) {
    auto new_head = m_snake.front();
    switch (m_direction) {
        case SnakeDirection::Left:
            new_head.x -= 100;
            break;
        case SnakeDirection::Right:
            new_head.x += 100;
            break;
        case SnakeDirection::Up:
            new_head.y -= 100;
            break;
        case SnakeDirection::Down:
            new_head.y += 100;
            break;
    }

    m_snake.insert(m_snake.begin(), new_head);
    if (!check_collision_food(food)) m_snake.pop_back();
}

const std::vector<SnakeTile>& Snake::get_body() const {
    return m_snake;
}

void Snake::set_direction(SnakeDirection direction) {
    if (direction == m_direction) return;

    if (direction == SnakeDirection::Left && m_direction != SnakeDirection::Right
        || direction == SnakeDirection::Right && m_direction != SnakeDirection::Left
        || direction == SnakeDirection::Up && m_direction != SnakeDirection::Down
        || direction == SnakeDirection::Down && m_direction != SnakeDirection::Up)
        m_direction = direction;
}

SnakeDirection Snake::get_direction() const {
    return m_direction;
}

bool Snake::check_collision_self() const {
    const auto& head = m_snake.front();
    const auto& body = m_snake;
    for (auto i = body.begin() + 1; i != body.end(); ++i) {
        const auto& current = *i;
        if (current.x == head.x && current.y == head.y) {
            return true;
        }
    }
    return false;
}

bool Snake::check_collision_food(const Food& food) const {
    const auto& [x, y] = m_snake.front();
    if (food.get_x() == x && food.get_y() == y) return true;
    return false;
}
