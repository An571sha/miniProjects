#include "grid.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

static void play_game_for_each_(grid_t *grid, int position,char token)
{

    switch(position) {

    case 0:
        grid_set_token(grid,0,0,token);
        break;
    case 1:
        grid_set_token(grid,0,1,token);
        break;
    case 2:
        grid_set_token(grid,0,2,token);
        break;
    case 3:
        grid_set_token(grid,1,0,token);
        break;
    case 4:
        grid_set_token(grid,1,1,token);
        break;
    case 5:
        grid_set_token(grid,1,2,token);
        break;
    case 6:
        grid_set_token(grid,2,0,token);
        break;
    case 7:
        grid_set_token(grid,2,1,token);
        break;
    case 8:
        grid_set_token(grid,2,2,token);
        break;

    }

}

/**
   static void is_not_already_played(int alreadyplayed[],int position){
    for(int i=0; i < 10; i++){
         if(position ==  alreadyplayed[i]){
             printf("%s", "offfffffffff \n");
        }
    }
}
**/
/* TODO : 1.add game over 2. prevent replaying on the same grid position 3.add Minimax algorithm*/
int main()
{
    int position = 0;
    int turn = 1;
    // int alreadyPlayed[10];
    grid_t *grid = NULL;
    grid_init(&grid);
    grid_print_hint(grid);
    turn = 1;
    printf("%s", "please enter a position for your marker \n");

    while(1) {

        scanf("%d", &position);

        if (turn == 1) {

            play_game_for_each_(grid,position,'O');
            printf("status - %d\n", grid_check(grid, 'O'));
            grid_print(grid);
            turn = 0;

        }
        else {

            play_game_for_each_(grid,position,'X');
            printf("status - %d\n", grid_check(grid, 'X'));
            grid_print(grid);
            turn = 1;
        }

        if(grid_check(grid, 'X') == 1) {
            printf("%s", "player 2 has won\n");
            return 0;
        }

        else if (grid_check(grid, 'O') == 1 ) {
            printf("%s", "player 1 has won\n");
            return 0;
        }

    }

    grid_destroy(grid);
    return 0;
}