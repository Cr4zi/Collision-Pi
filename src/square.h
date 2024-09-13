#ifndef SQUARE_H_
#define SQUARE_H_

#include "raylib.h"

typedef struct square {
    float mass;
    int sides;
    Vector2 pos;
    float vel;
} Square;

void drawSquare(Vector2 *pos, Color color, int sides);

/* Handling square and square collision */
void handleSquareCollision(Square *square1, Square *square2, int *collison);

/* Handling square and wall collision */
void handleWallCollision(Square *square, int posx, int *collision);

#endif // SQUARE_H_
