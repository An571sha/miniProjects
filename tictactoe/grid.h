#ifndef GRID_H
#define GRID_H

#include <stdlib.h>

typedef struct {
    char *spaces;
    size_t n;
    size_t size;
} grid_t;

void grid_init(grid_t **grid);
void grid_destroy(grid_t *grid);
void grid_set_token(grid_t *grid, size_t i, size_t j, char token);
char grid_get_token(grid_t *grid, size_t i, size_t j);
void grid_print(grid_t *grid);
void grid_print_hint(grid_t *grid);
int grid_check(grid_t *grid, char token);

#endif