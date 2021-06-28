#include "Calculations.hpp"

int Calculations::XI(int x, int y)
{
    int num = y * WIN_WIDTH + x;
    return num;
}

//sf::Vector2i Calculations::IX(int num)
//{
//    return sf::Vector2i((num-1)%WIN_WIDTH, (num-1)/WIN_WIDTH);
//}


