#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RED_SPACE "\033[;41m"
#define BLUE_SPACE "\033[0;44m"
#define COLOR_RESET "\x1b[0m"
#define MAX 256
#include "player_structure.h"
#include "player_list.h"
#include "score sorting.h"
#include "main_menu.h"
#include "show grid.h"
#include "getting points.h"
#include "valid.h"
#include "complete box.h"
#include "the moving.h"
#include "current mode.h"
#include "computer function.h"
#include "size of array.h"
#include "undo and redo.h"
#include "game loop.h"

int main(void)
{
    while (1)
    {
        FILE *debug = fopen("debug.txt", "a");
        fseek(debug, 0, SEEK_END);
        player1.score = 0;
        player1.nmoves = 0;
        player1.name_len = 0;
        player2.name_len = 0;
        player2.nmoves = 0;
        player2.score = 0;
        system("cls");
        int n, mode;
        int ind = 0, complete_turn = 0, complete_tc = 0, winner ;
        int n_undo = 0;

        int game_choice = main_menu();
        switch(game_choice)
        {
        case 1:
            fprintf(debug, "\nselect new game");
            break;
        case 2:
            fprintf(debug, "\nselect load game");
            break;
        case 3:
            fprintf(debug, "\nselect top 10 players");
            break;
        case 4:
            fprintf(debug, "\nselect exit game");
            break;
        }
        system("cls");

        //open the file of winners
        FILE *rwin = fopen("players.txt", "r");
        if (rwin == NULL)	// if the file was deleted
        {
            printf(RED "Players file was deleted" COLOR_RESET);
            rwin = fopen("players.txt", "w");
            fclose(rwin);
            rwin = fopen("players.txt", "r");
        }

        //read the file
        int counter = 0;
        while (!feof(rwin))	//determine the end of the file was reached or not
        {
            fread(&winners_list[counter].name_len, sizeof(int), 1, rwin);
            fread(&winners_list[counter].name, sizeof(char), winners_list[counter].name_len, rwin);
            winners_list[counter].name[winners_list[counter].name_len] = '\0';
            fread(&winners_list[counter].score, sizeof(int), 1, rwin);
            counter++;
        }

        fclose(rwin);

        int turn, tc, computer = 0, l_t = 0;

        if (game_choice == 1)
        {
            n = size_of_array();
            switch(n)
            {
            case 2:
                fprintf(debug, "\nselect 2x2 grid");
                break;
            case 3:
                fprintf(debug, "\nselect 3x3 grid");
                break;
            case 4:
                fprintf(debug, "\nselect 4x4 grid");
                break;
            case 5:
                fprintf(debug, "\nselect 5x5 grid");
                break;
            }
            system("cls");
            mode = 0;
            mode = single_or_double_mode();
            switch(mode)
            {
            case 1:
                fprintf(debug, "\nselect single mode");
                break;
            case 2:
                fprintf(debug, "\nselect double mode");
                break;
            }

            system("cls");
            if (mode == 2)
            {
                printf(RED "please enter player1's name:  ");
                gets(player1.name);
                fprintf(debug, "\nplayer1 name: %s", player1.name);
                player1.name_len = strlen(player1.name);
                printf("\n");
                printf(BLUE "please enter player2's name:  ");
                gets(player2.name);
                fprintf(debug, "\t\t\t\tplayer2 name: %s", player2.name);
                player2.name_len = strlen(player2.name);
                printf(COLOR_RESET "\n");
            }

            if (mode == 1)
            {
                printf(RED "please enter player1's name:  ");
                gets(player1.name);
                fprintf(debug, "\nplayer1 name: %s\t\t\t\tplayer2 name: Computer", player1.name);
                player1.name_len = strlen(player1.name);
                printf(COLOR_RESET "\n");
            }

            system("cls");

            char grid[3 *n + 2][5 *n + 3];
            // create th grid
            grid[0][0] = ' ';
            for (int i = 0; i < (3 *n + 2); i++)
                grid[i][1] = ' ';

            for (int j = 2; j < (5 *n + 3); j++)
            {
                if ((j - 2) % 5 != 0)
                    grid[0][j] = ' ';
                else
                    grid[0][j] = (j + 3) / 5 + 48;
            }

            for (int i = 1; i < (3 *n + 2); i++)
            {
                if ((i - 1) % 3 != 0)
                    grid[i][0] = ' ';
                else
                    grid[i][0] = ((i + 2) / 3 + 48);
            }

            for (int i = 1; i < (3 *n + 2); i++)
            {
                for (int j = 2; j < (5 *n + 3); j++)
                {
                    if ((i - 1) % 3 != 0)
                        grid[i][j] = ' ';
                    else if ((j - 2) % 5 != 0)
                        grid[i][j] = ' ';
                    else
                        grid[i][j] = 254;
                }
            }

            int no_moves = 0, n_lines = 2 *n *(n + 1);

            int complete_array[n][n];
            int inverse_uarray[n][n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    complete_array[i][j] = 0;
                    inverse_uarray[i][j] = 0;
                }
            }

            int moves[2 *n *(n + 1)][6];
            for (int i = 0; i < (2 *n *(n + 1)); i++)
            {
                for (int j = 0; j < 6; j++)
                    moves[i][j] = 0;
            }

            turn = 1;
            tc = 1;
            computer = 0;
            counter = 0;
            n_undo = 0;
            fclose(debug);
            winner = game(n_undo, counter, n, mode, grid, turn, tc, n_lines, moves, ind, complete_array, inverse_uarray, complete_turn, complete_tc, no_moves, l_t);
        }

        //load
        if (game_choice == 2)
        {
            int load_no;
            printf(CYAN "\nLoad (1 or 2 or 3)\n");
            load_no = read_point();
            printf(COLOR_RESET);
            if (load_no == 1 || load_no == 2 || load_no == 3)
            {
                system("cls");
                char load_name[9];
                sprintf(load_name, "%dsave.txt", load_no);
                FILE *load = fopen(load_name, "r");
                if (load == NULL)	// if the file does not exist
                {
                    printf(RED "Not Existing File\n" COLOR_RESET);
                }
                else
                {
                    fseek(load, 0, SEEK_END);	//get the size of the file
                    int sz = ftell(load);
                    if (sz == 0)	//if the file is empty
                    {
                        system("cls");
                        printf(RED "This File is Empty\n" COLOR_RESET);
                        continue;
                    }
                    else
                    {
                        fseek(load, 0, SEEK_SET);
                    }

                    fread(&l_t, sizeof(int), 1, load);
                    fread(&counter, sizeof(int), 1, load);
                    fread(&n_undo, sizeof(int), 1, load);
                    fread(&n, sizeof(int), 1, load);
                    fread(&mode, sizeof(int), 1, load);
                    int no_moves, n_lines;
                    fread(&no_moves, sizeof(int), 1, load);
                    fread(&player1.nmoves, sizeof(int), 1, load);
                    fread(&player2.nmoves, sizeof(int), 1, load);
                    fread(&player1.score, sizeof(int), 1, load);
                    fread(&player2.score, sizeof(int), 1, load);
                    fread(&turn, sizeof(int), 1, load);
                    fread(&tc, sizeof(int), 1, load);
                    int moves[2 *n *(n + 1)][6];
                    n_lines = (2 *n *(n + 1)) - player1.nmoves - player2.nmoves;
                    fread(moves, sizeof(int), (2 *n *(n + 1)) *6, load);
                    fread(&ind, sizeof(int), 1, load);
                    int complete_array[n][n];
                    int inverse_uarray[n][n];
                    fread(complete_array, sizeof(int), n *n, load);
                    fread(inverse_uarray, sizeof(int), n *n, load);
                    fread(&complete_turn, sizeof(int), 1, load);
                    fread(&complete_tc, sizeof(int), 1, load);
                    char grid[3 *n + 2][5 *n + 3];
                    fread(grid, sizeof(char), (3 *n + 2) *(5 *n + 3), load);
                    fread(&player1.name_len, sizeof(int), 1, load);
                    fread(&player1.name, sizeof(char), player1.name_len, load);
                    if (mode == 1)
                    {
                        fclose(load);
                        fclose(debug);
                        winner = game(n_undo, counter, n, mode, grid, turn, tc, n_lines, moves, ind, complete_array, inverse_uarray, complete_turn, complete_tc, no_moves, l_t);
                    }
                    else
                    {
                        fread(&player2.name_len, sizeof(int), 1, load);
                        fread(&player2.name, sizeof(char), player2.name_len, load);
                        fclose(load);
                        fclose(debug);
                        winner = game(n_undo, counter, n, mode, grid, turn, tc, n_lines, moves, ind, complete_array, inverse_uarray, complete_turn, complete_tc, no_moves, l_t);
                    }
                }
            }
            else	// if the user enter wrong number of file
            {
                printf(RED "Not Existing File\n" COLOR_RESET);
            }
        }

        int i = 0, found = 0;
        if (game_choice == 1 || game_choice == 2)
        {
            debug = fopen("debug.txt", "a");
            fseek(debug, 0, SEEK_END);
            if (winner == 1)	//player1 is the winner
            {
                while (winners_list[i].name_len != 0 && !found)
                {
                    if (strcmp(player1.name, winners_list[i].name) == 0)	//check if this player have played before
                    {
                        found = 1;
                        if (player1.score > winners_list[i].score)	//update the score to the greater 1
                        {
                            winners_list[i].score = player1.score;
                            fprintf(debug, "\nupdate player1 score");
                        }
                        else {};
                        break;
                    }
                    else
                    {
                        i++;
                        if (i == MAX)	//in case the file is full delete its data
                        {
                            for (int j = 0; j < MAX; j++)
                            {
                                winners_list[i].name_len = 0;
                            }

                            i = 0;
                        }
                    }
                }

                if (!found)	//add the player if it is his first game
                {
                    winners_list[i].name_len = player1.name_len;
                    strcpy(winners_list[i].name, player1.name);
                    winners_list[i].score = player1.score;
                }
            }

            if (winner == 2)	// player2 is the winner
            {
                while (winners_list[i].name_len != 0 && !found)
                {
                    if (strcmp(player2.name, winners_list[i].name) == 0)	//check if this player have played before
                    {
                        found = 1;
                        if (player2.score > winners_list[i].score)	//update the score to the greater 1
                        {
                            winners_list[i].score = player2.score;
                            fprintf(debug, "\nupdate player2 score");
                        }
                        else {};
                        break;
                    }
                    else
                    {
                        i++;
                        if (i == MAX)	//in case the file is full delete its data
                        {
                            for (int j = 0; j < MAX; j++)
                            {
                                winners_list[i].name_len = 0;
                            }

                            i = 0;
                        }
                    }
                }

                if (!found)	//add the player if it is his first game
                {
                    winners_list[i].name_len = player2.name_len;
                    strcpy(winners_list[i].name, player2.name);
                    winners_list[i].score = player2.score;
                }
            }

            FILE *save_win = fopen("players.txt", "w");	//save the information of the player
            int c = 0;
            while (winners_list[c].name_len != 0 && c < MAX)
            {
                fwrite(&winners_list[c].name_len, sizeof(int), 1, save_win);
                fwrite(&winners_list[c].name, sizeof(char), winners_list[c].name_len, save_win);
                fwrite(&winners_list[c].score, sizeof(int), 1, save_win);
                c++;
            }

            fclose(save_win);
            printf(CYAN "\nEnter 1 to go to main menu or 0 to exit game\n");

            while (1)
            {
                int enter = read_point();
                printf(COLOR_RESET);
                if (enter == 0)
                {
                    fprintf(debug, "\nExit Game");
                    fclose(debug);
                    return 0;
                }
                else if (enter == 1)
                {
                    fprintf(debug, "\nback to main menu");
                    fclose(debug);
                    break;
                }
                else
                    printf(RED "Enter a valid number\n" COLOR_RESET);
            }
        }

        if (game_choice == 3)	//top 10 players
        {
            sort_gamers(winners_list);
            int a;
            for (a = 0; a < 10; a++)
            {
                printf(YELLOW "\n%d-  %s\t%d\n" COLOR_RESET, a + 1, winners_list[a].name, winners_list[a].score);
            }

            printf(CYAN "Enter 1 to go to main menu or 0 to exit game\n" COLOR_RESET);
            while (1)
            {
                int enter;
                enter = read_point();
                if (enter == 1)
                {
                    fprintf(debug, "\nback to main menu");
                    fclose(debug);
                    break;
                }
                else if (enter == 0)
                {
                    fprintf(debug, "\nExit Game");
                    fclose(debug);
                    return 0;
                }
                else
                    printf(RED "Enter a valid number\n" COLOR_RESET);
            }
        }

        if (game_choice == 4)	//exit game
        {
            fprintf(debug, "\nExit Game");
            fclose(debug);
            return 0;
        }
    }

    return 0;
}
