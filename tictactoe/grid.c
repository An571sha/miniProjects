#include "grid.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

void grid_init(grid_t **grid)
{
    assert(grid);
    *grid = malloc(sizeof(grid_t));
    assert(*grid);
    (*grid)->n = 3;
    (*grid)->size = (*grid)->n * (*grid)->n;
    (*grid)->spaces = malloc((*grid)->size);
    assert((*grid)->spaces);
    memset((*grid)->spaces, '_', (*grid)->size);
}

void grid_destroy(grid_t *grid)
{
    assert(grid);
    if (!grid->spaces)
        free(grid->spaces);
    free(grid);
}

void grid_set_token(grid_t *grid, size_t i, size_t j, char token)
{
    assert(grid->spaces);
    assert(i < grid->n && j < grid->n);
    grid->spaces[grid->n * i + j] = token;
}

char grid_get_token(grid_t *grid, size_t i, size_t j)
{
    assert(grid->spaces);
    assert(i < grid->n && j < grid->n);
    return grid->spaces[grid->n * i + j];
}

void grid_print(grid_t *grid)
{
    size_t i = 0;
    size_t j = 0;
    assert(grid);
    for (i = 0; i < grid->n; ++i) {
        for (j = 0; j < grid->n; ++j) {
            printf("|%c|", grid->spaces[grid->n * i + j]);
        }
        printf("\n");
    }
}

void grid_print_hint(grid_t *grid)
{
    size_t i = 0;
    size_t j = 0;
    assert(grid);
    for (i = 0; i < grid->n; ++i) {
        for (j = 0; j < grid->n; ++j) {
            printf("|%u|", 3 * i + j);
        }
        printf("\n");
    }
}

int grid_check(grid_t *grid, char token)
{
    assert(grid);

    if (token == grid_get_token(grid, 0, 0) && token == grid_get_token(grid, 1, 0) && token == grid_get_token(grid, 2, 0))
        return 1;
    if (token == grid_get_token(grid, 0, 1) && token == grid_get_token(grid, 1, 1) && token == grid_get_token(grid, 2, 1))
        return 1;
    if (token == grid_get_token(grid, 0, 2) && token == grid_get_token(grid, 1, 2) && token == grid_get_token(grid, 2, 2))
        return 1;

    if (token == grid_get_token(grid, 0, 0) && token == grid_get_token(grid, 0, 1) && token == grid_get_token(grid, 0, 2))
        return 1;
    if (token == grid_get_token(grid, 1, 0) && token == grid_get_token(grid, 1, 1) && token == grid_get_token(grid, 1, 2))
        return 1;
    if (token == grid_get_token(grid, 2, 0) && token == grid_get_token(grid, 2, 1) && token == grid_get_token(grid, 2, 2))
        return 1;

    if (token == grid_get_token(grid, 0, 0) && token == grid_get_token(grid, 1, 1) && token == grid_get_token(grid, 2, 2))
        return 1;
    if (token == grid_get_token(grid, 0, 2) && token == grid_get_token(grid, 1, 1) && token == grid_get_token(grid, 2, 0))
        return 1;

    return 0;
}
