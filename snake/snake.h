#ifndef SNAKE_H_
#define SNAKE_H_

typedef enum direction {
    UP = -1,
    DOWN = 1,
    LEFT = -2,
    RIGHT = 2
} dir_e;

typedef struct snakebit_s {
    int x;//      0-1-2 | 1-2-3 | 2-3-3 | 2-3-3
    int y;//      0-0-0 | 0-0-0 | 0-0-1 | 0-1-2
    
    int next_x;// 1-2-3 | 2-3-3 | 2-3-3 | 3-3-3
    int next_y;// 0-0-0 | 0-0-1 | 0-1-2 | 0-1-2
} snakebit_s;

typedef struct snake_s {
    snakebit_s *bits;
    int len;
    dir_e dir;
} snake_s;

snake_s *create_snake();
void dump_snake(snake_s const * const s);
void destroy_snake(snake_s *s);
void update_snake(snake_s * const s);

#endif
