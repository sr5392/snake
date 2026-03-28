#include "snake.hpp"

Snake::Snake() : m_direction{SnakeDirection::Right} {
    m_snake.reserve(3);
    m_snake.emplace_back(SnakeTile{400, 400});
    m_snake.emplace_back(SnakeTile{300, 400});
    m_snake.emplace_back(SnakeTile{200, 400});
}

void Snake::update() {
    for (auto i = m_snake.size() - 1; i > 0; --i) {
        m_snake[i].x = m_snake[i - 1].x;
        m_snake[i].y = m_snake[i - 1].y;
    }
    switch (m_direction) {
        case SnakeDirection::Left:
            m_snake[0].x -= 100;
            break;
        case SnakeDirection::Right:
            m_snake[0].x += 100;
            break;
        case SnakeDirection::Up:
            m_snake[0].y -= 100;
            break;
        case SnakeDirection::Down:
            m_snake[0].y += 100;
            break;
    }
}

std::vector<SnakeTile>& Snake::get_snake_body() {
    return m_snake;
}

void Snake::set_direction(SnakeDirection direction) {
    if (direction == m_direction) return;

    switch (direction) {
        case SnakeDirection::Left:
            if (m_direction != SnakeDirection::Right) m_direction = direction;
            break;
        case SnakeDirection::Right:
            if (m_direction != SnakeDirection::Left) m_direction = direction;
            break;
        case SnakeDirection::Up:
            if (m_direction != SnakeDirection::Down) m_direction = direction;
            break;
        case SnakeDirection::Down:
            if (m_direction != SnakeDirection::Up) m_direction = direction;
            break;
    }
}

SnakeDirection Snake::get_direction() const {
    return m_direction;
}
