#include <stdlib.h>
#include <stdio.h>

#include "snake.h"

snake_s *create_snake()
{
    snake_s *s = malloc(sizeof(snake_s));
    int x = 0, y = 0;

    if (s == NULL)
        return NULL;
    s->dir = RIGHT;
    s->len = 3;
    s->bits = malloc(sizeof(snakebit_s) * 3);
    if (s->bits == NULL)
        return NULL;
    for (int i = 0; i < s->len; i++, x++) {
        s->bits[i].x = x;
        s->bits[i].y = y;
        s->bits[i].next_x = x + 1;
        s->bits[i].next_y = y;
    }
    return s;
}

void dump_snake(snake_s const * const s)
{
    snakebit_s bit;

    printf("Snakebits:\n");
    for (int i = 0; i < s->len; i++) {
        bit = s->bits[i];
	printf("[%d]: (%d, %d), (%d, %d)\n",
               i, bit.x, bit.y, bit.next_x, bit.next_y);
    }
    printf("Length: %d\n", s->len);
    printf("Direction: %d\n", s->dir);
}

void destroy_snake(snake_s *s)
{
    free(s->bits);
    free(s);
}

void update_snakehead(snake_s * const s)
{
    snakebit_s *bit = &s->bits[s->len - 1];

    switch(s->dir) {
    case UP:
        bit->next_y -= 1;
        break;
    case DOWN:
        bit->next_y += 1;
        break;
    case LEFT:
        bit->next_x -= 1;
        break;
    case RIGHT:
        bit->next_x += 1;
        break;
    }
}

void update_snake(snake_s * const s)
{   
    for (int i = 0; i < s->len; i++) {
        s->bits[i].x = s->bits[i].next_x;
        s->bits[i].y = s->bits[i].next_y;
    }
    for (int i = 0; i < s->len - 1; i++) {
        s->bits[i].next_x = s->bits[i+1].next_x;
        s->bits[i].next_y = s->bits[i+1].next_y;
    }
    update_snakehead(s);
}
