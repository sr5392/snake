#include "food.hpp"

Food::Food() : x{1200}, y{400} {
}

void Food::respawn() {
    x = 200;
    y = 200;
}
