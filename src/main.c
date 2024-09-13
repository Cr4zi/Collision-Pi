#include "raylib.h"
#include "config.h"
#include "square.h"
#include <stdlib.h>

#define WALL_X 100
#define WALL_WIDTH 10

void draw(Square *square1, Square *square2, int *collision);

int main()
{
    Vector2 v1 = {400, 500};
    Vector2 v2 = {1100, 500};
    Square sq1 = { 1, 100, v1, 0};
    Square sq2 = { 10000, 100, v2, -5};
    int collision = 0;

    InitWindow(WIDTH, HEIGHT, "Collision Pi");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        draw(&sq1, &sq2, &collision);
    }
    CloseWindow();

    return 0;
}

int num_length(int num)
{
    if(num == 0) return 1;

    int len = 0;
    while(num != 0) {
        len++;
        num /= 10;
    }
    return len;
}

void draw(Square *square1, Square *square2, int *collision)
{
    BeginDrawing();
    ClearBackground(BLACK);

    drawSquare(&square1->pos, RAYWHITE, square1->sides);
    drawSquare(&square2->pos, RAYWHITE, square2->sides);

    /* Drawing wall */
    DrawRectangle(WALL_X, 0, WALL_WIDTH, HEIGHT-120, RAYWHITE);

    handleSquareCollision(square1, square2, collision);
    handleWallCollision(square1, WALL_X+WALL_WIDTH, collision);

    square1->pos.x += square1->vel;
    square2->pos.x += square2->vel;

    char *str = (char *)malloc(1000);
    char collision_str[] = "Collision: ";
    int i;
    for(i = 0; collision_str[i] != '\0'; i++)
        str[i] = collision_str[i];

    int nDigits = num_length(*collision);
    int coll_copy = *collision;
    int *arr = (int *)malloc(nDigits * sizeof(int));
    for(int j = nDigits-1; j >=0; j--) {
        arr[j] = coll_copy % 10;
        coll_copy /= 10;
    }

    for(int j = 0; j < nDigits; j++) {
        str[i++] = arr[j] + '0';
    }

    str[i] = '\0';

    // printf("%s\n", str);
    DrawText(str, 1000, 100, 20, PINK);
    EndDrawing();
    free(str);
}
