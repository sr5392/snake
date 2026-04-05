#include "snake.hpp"

Snake::Snake() : m_direction{SnakeDirection::Right} {
    m_snake.reserve(255);
    m_snake.emplace_back(SnakeTile{400, 400});
    m_snake.emplace_back(SnakeTile{300, 400});
    m_snake.emplace_back(SnakeTile{200, 400});
}

void Snake::update() {
    SnakeTile new_head = m_snake.front();
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
}

std::vector<SnakeTile>& Snake::get_body() {
    return m_snake;
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
