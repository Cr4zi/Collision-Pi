#include "square.h"
#include <raylib.h>

void drawSquare(Vector2 *pos, Color color, int sides)
{
    DrawRectangle(pos->x, pos->y, sides, sides, color);
}

void handleSquareCollision(Square *square1, Square *square2, int *collision)
{
    float m1 = square1->mass, m2 = square2->mass;
    Rectangle rec1 = { square1->pos.x, square1->pos.y, square1->sides, square1->sides };
    Rectangle rec2 = { square2->pos.x, square2->pos.y, square2->sides, square2->sides };
    if(square1->pos.x + square1->sides >= square2->pos.x) {
        int v1 = square1->vel;
        square1->vel = ((m1 - m2) / (m1 + m2)) * square1->vel + ((2 * m2) / (m1 + m2)) * square2->vel;
        square2->vel = ((m2 - m1) / (m1 + m2)) * square2->vel + ((2 * m1) / (m1 + m2)) * v1;
        ++(*collision);
    }
}

void handleWallCollision(Square *square, int posx, int *collision)
{
    if(square->pos.x <= posx) {
        square->vel *= -1;
        ++(*collision);
    }
}
