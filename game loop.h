#ifndef GAME_LOOP_H_INCLUDED
#define GAME_LOOP_H_INCLUDED

// game loop
int game(int n_undo, int counter, int n, int mode, char grid[3 *n + 2][5 *n + 3], int turn, int tc, int n_lines, int moves[2 *n *(n + 1)][6], int ind, int complete_array[n][n], int inverse_uarray, int complete_turn, int complete_tc, int no_moves, int l_t)
{
    time_t savedtime;
    int t = time(&savedtime);
    t -= l_t;
    int ch_error=0;
    int ch_redo = 1;
    int row1, col1, row2, col2, computer;
    char pl;
    FILE *debug = fopen("debug.txt", "a");
    fseek(debug, 0, SEEK_END);
    if (mode == 1)
    {
        computer = 1;
    }
    else if (mode == 2)
    {
        computer = 0;
    }

    show_grid(n, grid, moves, no_moves, mode, n_lines, t);
    fprintf(debug, "\n\n");
    for (int i = 0; i< (3*n+2); i++)
    {
        for (int j =0; j < (5 *n + 3); j++)
            fprintf(debug, "%c", grid[i][j]);
        fprintf(debug, "\n");
    }
    int end_game = 0;

    while (!end_game)
    {
        ch_redo = 1;
        complete_tc = 0;
        if (computer == 1)
        {
            if (tc == 1)
            {
                turn = 0;
                pl = player1.name[0];
            }
            else if (tc == 2)
            {
                turn = 0;
                pl = 'C';
            }
        }
        else if (computer == 0)
        {
            if (turn == 1)
            {
                tc = 0;
                pl = player1.name[0];
            }
            else if (turn == 2)
            {
                tc = 0;
                pl = player2.name[0];
            }
        }

        if (turn == 1 || tc == 1)
        {
            printf(RED "Enter the first point\nRow: ");
            row1 = read_point();
            printf("col: ");
            col1 = read_point();
            printf("Enter the second point\nRow: ");
            row2 = read_point();
            printf("Col: ");
            col2 = read_point();
            printf(COLOR_RESET);
        }
        else if (turn == 2)
        {
            printf(BLUE "\t\t\t\t\t\t\t\t\t Enter the first point\n\t\t\t\t\t\t\t\t\t Row: ");
            row1 = read_point();
            printf("\t\t\t\t\t\t\t\t\t Col: ");
            col1 = read_point();
            printf("\t\t\t\t\t\t\t\t\t Enter the second point\n\t\t\t\t\t\t\t\t\t Row: ");
            row2 = read_point();
            printf("\t\t\t\t\t\t\t\t\t Col: ");
            col2 = read_point();
            printf(COLOR_RESET);
        }
        else if (turn == 1 && tc == 2)
        {
            printf(BLUE "player %c \n" COLOR_RESET, pl);
        }

        // if the player enter invalid move
        if (computer == 0)
        {
            while (!valid_move(row1, col1, row2, col2, n, grid))
            {
                if (turn == 1)
                {
                    system("cls");
                    show_grid(n, grid, moves, no_moves, mode, n_lines, t);
                    printf(RED "Not allowed\n" COLOR_RESET);
                    fprintf(debug, "\nplayer1 entered invalid move");
                    printf(RED "Enter the first point\nRow: ");
                    row1 = read_point();
                    printf("col: ");
                    col1 = read_point();
                    printf("Enter the second point\nRow: ");
                    row2 = read_point();
                    printf("Col: ");
                    col2 = read_point();
                    printf(COLOR_RESET);
                }
                else if (turn == 2)
                {
                    system("cls");
                    show_grid(n, grid, moves, no_moves, mode, n_lines, t);
                    printf(BLUE "\t\t\t\t\t\t\t\t\t Not allowed\n" COLOR_RESET);
                    fprintf(debug, "\nplayer2 entered invalid move");
                    printf(BLUE "\t\t\t\t\t\t\t\t\t Enter the first point\n\t\t\t\t\t\t\t\t\t Row: ");
                    row1 = read_point();
                    printf("\t\t\t\t\t\t\t\t\t Col: ");
                    col1 = read_point();
                    printf("\t\t\t\t\t\t\t\t\t Enter the second point\n\t\t\t\t\t\t\t\t\t Row: ");
                    row2 = read_point();
                    printf("\t\t\t\t\t\t\t\t\t Col: ");
                    col2 = read_point();
                    printf(COLOR_RESET);
                }
            }

            if (row1 == 3 && col1 == 3 && row2 == 3 && col2 == 3)	//save
            {
                int no_save;
                if (turn == 1)
                    printf(RED);
                else if (turn == 2)
                    printf(BLUE);
                printf("Save game to file number 1 or 2 or 3\n");
                while (1)
                {
                    no_save = read_point();
                    if (no_save == 1 || no_save == 2 || no_save == 3)
                    {
                        time_t currenttime;
                        int current = time(&currenttime);
                        l_t = current - t;

                        char save_name[9];
                        sprintf(save_name, "%dsave.txt", no_save);

                        FILE *save = fopen(save_name, "w");
                        fwrite(&l_t, sizeof(int), 1, save);
                        fwrite(&counter, sizeof(int), 1, save);
                        fwrite(&n_undo, sizeof(int), 1, save);
                        fwrite(&n, sizeof(int), 1, save);
                        fwrite(&mode, sizeof(int), 1, save);
                        fwrite(&no_moves, sizeof(int), 1, save);
                        fwrite(&player1.nmoves, sizeof(int), 1, save);
                        fwrite(&player2.nmoves, sizeof(int), 1, save);
                        fwrite(&player1.score, sizeof(int), 1, save);
                        fwrite(&player2.score, sizeof(int), 1, save);
                        fwrite(&turn, sizeof(int), 1, save);
                        fwrite(&tc, sizeof(int), 1, save);
                        fwrite(moves, sizeof(int), (2 *n *(n + 1)) *6, save);
                        fwrite(&ind, sizeof(int), 1, save);
                        fwrite(complete_array, sizeof(int), n *n, save);
                        fwrite(inverse_uarray, sizeof(int), n *n, save);
                        fwrite(&complete_turn, sizeof(int), 1, save);
                        fwrite(&complete_tc, sizeof(int), 1, save);
                        fwrite(grid, sizeof(char), (3 *n + 2) *(5 *n + 3), save);
                        fwrite(&player1.name_len, sizeof(int), 1, save);
                        fwrite(&player1.name, sizeof(char), player1.name_len, save);
                        fwrite(&player2.name_len, sizeof(int), 1, save);
                        fwrite(&player2.name, sizeof(char), player2.name_len, save);
                        fclose(save);
                        system("cls");
                        printf("saved to %dsave.txt\n" COLOR_RESET, no_save);
                        fprintf(debug, "\nsaved to %dsave.txt", no_save);
                        show_grid(n, grid, moves, no_moves, mode, n_lines, t);
                        break;
                    }
                    else
                    {
                        printf("Not existing file\n");
                    }
                }

                continue;
            }

            if (row1 == 0 && col1 == 0 && row2 == 0 && col2 == 0)	// to go back to main menu
            {
                fprintf(debug, "\nback to main menu");
                fclose(debug);
                return 0;
            }

            // to undo
            if (row1 == 1 && row2 == 1 && col1 == 1 && col2 == 1)
            {
                if (counter != 0)
                {
                    ch_error=0;
                    int t = moves[counter - 1][4];
                    int ch_comp = moves[counter - 1][5];
                    undo(counter, n, grid, moves, complete_array, inverse_uarray);
                    n_undo++;
                    fprintf(debug, "\nundo");

                    if (ch_comp == 1 && t == 1)
                    {
                        turn = turn + pow(-1, turn + 1);
                        player1.score--;
                        player1.nmoves--;
                        fprintf(debug, "\npalyer1 score: %d\nplayer1 no. of moves: %d", player1.score, player1.nmoves);
                        complete_turn = 0;
                    }
                    else if (ch_comp == 1 && t == 2)
                    {
                        turn = turn + pow(-1, turn + 1);
                        player2.score--;
                        player2.nmoves--;
                        fprintf(debug, "\npalyer2 score: %d\nplayer2 no. of moves: %d", player2.score, player2.nmoves);
                        complete_turn = 0;
                    }

                    if ((ch_comp == 2 || ch_comp == 3) && t == 1)
                    {
                        turn = turn + pow(-1, turn + 1);
                        player1.score = player1.score - 2;
                        player1.nmoves--;
                        fprintf(debug, "\npalyer1 score: %d\nplayer1 no. of moves: %d", player1.score, player1.nmoves);
                        complete_turn = 0;
                    }
                    else if ((ch_comp == 2 || ch_comp == 3)&& t == 2)
                    {
                        turn = turn + pow(-1, turn + 1);
                        player2.score = player2.score - 2;
                        player2.nmoves--;
                        fprintf(debug, "\npalyer2 score: %d\nplayer2 no. of moves: %d", player2.score, player2.nmoves);
                        complete_turn = 0;
                    }

                    if (ch_comp == 0 && t == 1)
                    {
                        player1.nmoves--;
                        fprintf(debug, "\npalyer1 score: %d\nplayer1 no. of moves: %d", player1.score, player1.nmoves);
                    }
                    else if (ch_comp == 0 && t == 2)
                    {
                        player2.nmoves--;
                        fprintf(debug, "\npalyer2 score: %d\nplayer2 no. of moves: %d", player2.score, player2.nmoves);
                    }

                    ind--;
                    n_lines++;
                    fprintf(debug, "\nremaining lines: %d", n_lines);
                    counter--;

                }
                else
                {
                    turn = turn + pow(-1, turn + 1);
                    ch_error = 1;
                }
            }

            //to redo
            else if (row1 == 2 && row2 == 2 && col1 == 2 && col2 == 2)
            {
                if (n_undo > 0)
                {
                    ch_error = 0;
                    int t = moves[counter][4];
                    int ch_comp = moves[counter][5];

                    redo(counter, n, grid, moves, complete_array, inverse_uarray);
                    n_undo--;
                    fprintf(debug, "\nredo");

                    if (ch_comp == 0 && t == 1)
                    {
                        player1.nmoves++;
                        fprintf(debug, "\npalyer1 score: %d\nplayer1 no. of moves: %d", player1.score, player1.nmoves);

                    }
                    else if (ch_comp == 0 && t == 2)
                    {
                        player2.nmoves++;
                        fprintf(debug, "\npalyer2 score: %d\nplayer2 no. of moves: %d", player2.score, player2.nmoves);

                    }

                    if (ch_comp == 1 && t == 1)
                    {
                        player1.score++;
                        player1.nmoves++;
                        fprintf(debug, "\npalyer1 score: %d\nplayer1 no. of moves: %d", player1.score, player1.nmoves);
                        complete_turn = 1;
                    }
                    else if (ch_comp == 1 && t == 2)
                    {
                        player2.score++;
                        player2.nmoves++;
                        fprintf(debug, "\npalyer2 score: %d\nplayer2 no. of moves: %d", player2.score, player2.nmoves);
                        complete_turn = 1;
                    }

                    if ((ch_comp == 2 || ch_comp == 3) && t == 1)
                    {
                        player1.score = player1.score + 2;
                        player1.nmoves++;
                        fprintf(debug, "\npalyer1 score: %d\nplayer1 no. of moves: %d", player1.score, player1.nmoves);
                        complete_turn = 2;
                    }
                    else if ((ch_comp == 2 || ch_comp == 3) && t == 2)
                    {
                        player2.score = player2.score + 2;
                        player2.nmoves++;
                        fprintf(debug, "\npalyer2 score: %d\nplayer2 no. of moves: %d", player2.score, player2.nmoves);
                        complete_turn = 2;
                    }

                    ind++;
                    n_lines--;
                    fprintf(debug, "\nremaining lines: %d", n_lines);
                    counter++;
                    ch_redo = 1;

                }
                else
                {
                    ch_redo = 0;
                    ch_error=2;
                }
            }
            else
            {
                complete_turn = move(row1, col1, row2, col2, n, grid, complete_array, turn, tc);
                n_undo = 0;
                if (turn == 1)
                {
                    player1.nmoves++;
                    fprintf(debug, "\nplayer1 move: (%d,%d) to (%d,%d)", row1, col1, row2, col2);
                    fprintf(debug, "\nplayer1 no. of moves: %d", player1.nmoves);
                    no_moves++;
                    moves[ind][0] = row1;
                    moves[ind][1] = col1;
                    moves[ind][2] = row2;
                    moves[ind][3] = col2;
                    moves[ind][4] = 1;
                    moves[ind++][5] = complete_turn;
                }

                if (turn == 2)
                {
                    player2.nmoves++;
                    fprintf(debug, "\nplayer2 move: (%d,%d) to (%d,%d)", row1, col1, row2, col2);
                    fprintf(debug, "\nplayer2 no. of moves: %d", player2.nmoves);
                    no_moves++;
                    moves[ind][0] = row1;
                    moves[ind][1] = col1;
                    moves[ind][2] = row2;
                    moves[ind][3] = col2;
                    moves[ind][4] = 2;
                    moves[ind++][5] = complete_turn;
                }

                if (turn == 1)
                {
                    if (complete_turn == 1)
                    {
                        player1.score++;
                        fprintf(debug, "\npalyer1 score: %d", player1.score);
                    }
                    else if (complete_turn == 2 || complete_turn == 3)
                    {
                        player1.score = player1.score + 2;
                        fprintf(debug, "\npalyer1 score: %d", player1.score);
                    }
                }
                else if (turn == 2)
                {
                    if (complete_turn == 1)
                    {
                        player2.score++;
                        fprintf(debug, "\npalyer2 score: %d", player2.score);
                    }
                    else if (complete_turn == 2 || complete_turn == 3)
                    {
                        player2.score = player2.score + 2;
                        fprintf(debug, "\npalyer2 score: %d", player2.score);
                    }
                }

                n_lines--;
                fprintf(debug, "\nremaining lines: %d", n_lines);
                counter++;
            }
        }
        else if (computer == 1)
        {
            if (tc == 1)
            {
                while (!valid_move(row1, col1, row2, col2, n, grid))
                {
                    system("cls");
                    show_grid(n, grid, moves, no_moves, mode, n_lines, t);
                    printf(RED "Not allowed\n" COLOR_RESET);
                    fprintf(debug, "\nplayer1 entered invalid move");
                    printf(RED "Enter the first point\nRow: ");
                    row1 = read_point();
                    printf("col: ");
                    col1 = read_point();
                    printf("Enter the second point\nRow: ");
                    row2 = read_point();
                    printf("Col: ");
                    col2 = read_point();
                    printf(COLOR_RESET);
                }

                if (row1 == 3 && col1 == 3 && row2 == 3 && col2 == 3)	//save
                {
                    int no_save;
                    printf(RED "Save game to file number 1 or 2 or 3\n");
                    while (1)
                    {
                        no_save = read_point();
                        if (no_save == 1 || no_save == 2 || no_save == 3)
                        {
                            time_t currenttime;
                            int current = time(&currenttime);
                            l_t = current - t;

                            char save_name[9];
                            sprintf(save_name, "%dsave.txt", no_save);

                            FILE *save = fopen(save_name, "w");
                            fwrite(&l_t, sizeof(int), 1, save);
                            fwrite(&counter, sizeof(int), 1, save);
                            fwrite(&n_undo, sizeof(int), 1, save);
                            fwrite(&n, sizeof(int), 1, save);
                            fwrite(&mode, sizeof(int), 1, save);
                            fwrite(&no_moves, sizeof(int), 1, save);
                            fwrite(&player1.nmoves, sizeof(int), 1, save);
                            fwrite(&player2.nmoves, sizeof(int), 1, save);
                            fwrite(&player1.score, sizeof(int), 1, save);
                            fwrite(&player2.score, sizeof(int), 1, save);
                            fwrite(&turn, sizeof(int), 1, save);
                            fwrite(&tc, sizeof(int), 1, save);
                            fwrite(moves, sizeof(int), (2 *n *(n + 1)) *6, save);
                            fwrite(&ind, sizeof(int), 1, save);
                            fwrite(complete_array, sizeof(int), n *n, save);
                            fwrite(inverse_uarray, sizeof(int), n *n, save);
                            fwrite(&complete_turn, sizeof(int), 1, save);
                            fwrite(&complete_tc, sizeof(int), 1, save);
                            fwrite(grid, sizeof(char), (3 *n + 2) *(5 *n + 3), save);
                            fwrite(&player1.name_len, sizeof(int), 1, save);
                            fwrite(&player1.name, sizeof(char), player1.name_len, save);
                            fclose(save);
                            system("cls");
                            printf(CYAN "saved to %dsave.txt\n" COLOR_RESET, no_save);
                            fprintf(debug, "\nsaved to %dsave.txt", no_save);
                            show_grid(n, grid, moves, no_moves, mode, n_lines, t);
                            break;
                        }
                        else
                        {
                            printf(RED "Not existing file\n");
                        }
                    }

                    continue;
                }

                if (row1 == 0 && col1 == 0 && row2 == 0 && col2 == 0)	// to go back to main menu
                {
                    fprintf(debug, "\nback to main menu");
                    fclose(debug);
                    return 0;
                }

                // to undo
                if (row1 == 1 && row2 == 1 && col1 == 1 && col2 == 1)
                {
                    if (counter != 0)
                    {
                        ch_error = 0;
                        int t = moves[counter - 1][4];
                        int ch_comp = moves[counter - 1][5];

                        if (t == 2)
                        {
                            while (t == 2)
                            {
                                if (t == 2 && ch_comp == 0)
                                {
                                    undo(counter, n, grid, moves, complete_array, inverse_uarray);
                                    fprintf(debug, "\nundo move");
                                    counter--;
                                    n_lines++;
                                    ind--;
                                    player2.nmoves--;
                                    fprintf(debug, "\ncomputer no. of moves: %d\nremaining lines: %d", player2.nmoves, n_lines);
                                    ch_comp = moves[counter - 1][5];
                                    t = moves[counter - 1][4];

                                    while (t == 2)
                                    {
                                        if (ch_comp == 1)
                                        {
                                            undo(counter, n, grid, moves, complete_array, inverse_uarray);
                                            fprintf(debug, "\nundo move");
                                            counter--;
                                            n_lines++;
                                            ind--;
                                            player2.nmoves--;
                                            player2.score--;
                                            fprintf(debug, "\ncomputer no. of moves: %d\ncomputer score: %d\nremaining lines: %d", player2.nmoves, player2.score, n_lines);
                                            ch_comp = moves[counter - 1][5];
                                            t = moves[counter - 1][4];
                                        }
                                        else if (ch_comp == 2 || ch_comp == 3)
                                        {
                                            undo(counter, n, grid, moves, complete_array, inverse_uarray);
                                            fprintf(debug, "\nundo move");
                                            counter--;
                                            n_lines++;
                                            ind--;
                                            player2.nmoves--;
                                            player2.score -= 2;
                                            fprintf(debug, "\ncomputer no. of moves: %d\ncomputer score: %d\nremaining lines: %d", player2.nmoves, player2.score, n_lines);
                                            ch_comp = moves[counter - 1][5];
                                            t = moves[counter - 1][4];
                                        }
                                    }

                                    if (t == 1 && ch_comp == 0)
                                    {
                                        undo(counter, n, grid, moves, complete_array, inverse_uarray);
                                        fprintf(debug, "\nundo move");
                                        n_undo++;;
                                        counter--;
                                        n_lines++;
                                        ind--;
                                        player1.nmoves--;
                                        fprintf(debug, "\nplayer1 no. of moves: %d\nremaining lines: %d", player1.nmoves, n_lines);
                                        tc = tc + pow(-1, tc + 1);
                                        break;
                                    }
                                    else if (t == 1 && ch_comp == 1)
                                    {
                                        undo(counter, n, grid, moves, complete_array, inverse_uarray);
                                        fprintf(debug, "\nundo move");
                                        n_undo++;;
                                        counter--;
                                        n_lines++;
                                        ind--;
                                        player1.nmoves--;
                                        player1.score--;
                                        fprintf(debug, "\nplayer1 no. of moves: %d\nplayer1 score: %d\nremaining lines: %d", player1.nmoves, player1.score, n_lines);
                                        tc = tc + pow(-1, tc + 1);
                                        break;
                                    }
                                    else if (t == 1 && ((ch_comp == 2) || (ch_comp == 3)))
                                    {
                                        undo(counter, n, grid, moves, complete_array, inverse_uarray);
                                        fprintf(debug, "\nundo move");
                                        n_undo++;
                                        counter--;
                                        n_lines++;
                                        ind--;
                                        player1.nmoves--;
                                        player1.score = player1.score - 2;
                                        fprintf(debug, "\nplayer1 no. of moves: %d\nplayer1 score: %d\nremaining lines: %d", player1.nmoves, player1.score, n_lines);
                                        tc = tc + pow(-1, tc + 1);
                                        break;
                                    }
                                }
                            }
                        }
                        else if (t == 1)
                        {
                            if (ch_comp == 1)
                            {
                                undo(counter, n, grid, moves, complete_array, inverse_uarray);
                                fprintf(debug, "\nundo move");
                                n_undo++;
                                counter--;
                                n_lines++;
                                ind--;
                                player1.nmoves--;
                                player1.score--;
                                fprintf(debug, "\nplayer1 no. of moves: %d\nplayer1 score: %d\nremaining lines: %d", player1.nmoves, player1.score, n_lines);
                                tc = tc + pow(-1, tc + 1);
                            }
                            else if (ch_comp == 2 || ch_comp == 3)
                            {
                                undo(counter, n, grid, moves, complete_array, inverse_uarray);
                                fprintf(debug, "\nundo move");
                                n_undo++;
                                counter--;
                                n_lines++;
                                ind--;
                                player1.nmoves--;
                                player1.score = player1.score - 2;
                                fprintf(debug, "\nplayer1 no. of moves: %d\nplayer1 score: %d\nremaining lines: %d", player1.nmoves, player1.score, n_lines);
                                tc = tc + pow(-1, tc + 1);
                            }
                        }
                    }
                    else
                    {
                        tc = tc + pow(-1, tc + 1);
                        ch_error=1;
                    }
                }

                // to redo
                else if (row1 == 2 && row2 == 2 && col1 == 2 && col2 == 2)
                {
                    if (n_undo > 0)
                    {
                        ch_error=0;
                        int t = moves[counter][4];
                        int ch_comp = moves[counter][5];

                        redo(counter, n, grid, moves, complete_array, inverse_uarray);
                        fprintf(debug, "\nredo");
                        n_undo--;

                        if (ch_comp == 0 && t == 1)
                        {
                            player1.nmoves++;
                            fprintf(debug, "\nplayer1 no. of moves: %d", player1.nmoves);
                        }

                        if (ch_comp == 1 && t == 1)
                        {
                            player1.score++;
                            player1.nmoves++;
                            fprintf(debug, "\nplayer1 no. of moves: %d\nplayer1 score: %d", player1.nmoves, player1.score);
                            tc = tc + pow(-1, tc + 1);
                        }

                        if ((ch_comp == 2 || ch_comp == 2) && t == 1)
                        {
                            player1.score = player1.score + 2;
                            player1.nmoves++;
                            fprintf(debug, "\nplayer1 no. of moves: %d\nplayer1 score: %d", player1.nmoves, player1.score);
                            tc = tc + pow(-1, tc + 1);
                        }

                        ind++;
                        n_lines--;
                        fprintf(debug, "\nremaining lines: %d", n_lines);
                        counter++;
                        ch_redo = 1;

                        while (t == 2)
                        {
                            complete_tc = computer1(n, grid, moves, &ind, &no_moves, complete_array, turn, tc);
                            if (complete_tc == 1)
                            {
                                player2.score++;
                                fprintf(debug, "\ncomputer score: %d", player2.score);
                                t = 2;
                            }
                            else if (complete_tc == 2 || complete_tc == 3)
                            {
                                player2.score = player2.score + 2;
                                fprintf(debug, "\ncomputer score: %d", player2.score);
                                t = 2;
                            }
                            else
                            {
                                complete_tc = 0;
                                t = 1;
                            }

                            complete_tc = 0;
                            n_lines--;
                            fprintf(debug, "\nremaining lines: %d", n_lines);
                            counter++;
                        }
                    }
                    else
                    {
                        ch_redo = 0;
                        ch_error=2;
                    }
                }
                else
                {
                    complete_tc = move(row1, col1, row2, col2, n, grid, complete_array, turn, tc);
                    n_undo=0;
                    if (tc == 1)
                    {
                        player1.nmoves++;
                        fprintf(debug, "\nplayer1 move: (%d,%d) to (%d,%d)", row1, col1, row2, col2);
                        fprintf(debug, "\nplayer1 no. of moves: %d", player1.nmoves);
                        no_moves++;
                        moves[ind][0] = row1;
                        moves[ind][1] = col1;
                        moves[ind][2] = row2;
                        moves[ind][3] = col2;
                        moves[ind][4] = 1;
                        moves[ind++][5] = complete_tc;
                    }

                    if (tc == 1)
                    {
                        if (complete_tc == 1)
                        {
                            player1.score++;
                            fprintf(debug, "\nplayer1 score: %d", player1.score);
                        }
                        else if (complete_tc == 2 || complete_tc == 3)
                        {
                            player1.score = player1.score + 2;
                            fprintf(debug, "\nplayer1 score: %d", player1.score);
                        }
                    }

                    n_lines--;
                    fprintf(debug, "\nremaining lines: %d", n_lines);
                    counter++;
                }
            }
            else if (tc == 2)
            {
                printf(BLUE "computer %c \n" COLOR_RESET);
                complete_tc = 0;
                complete_tc = computer1(n, grid, moves, &ind, &no_moves, complete_array, turn, tc);

                if (tc == 2)
                {
                    if (complete_tc == 1)
                    {
                        player2.score++;
                        fprintf(debug, "\ncomputer score: %d", player2.score);
                    }
                    else if (complete_tc == 2 || complete_tc == 3)
                    {
                        player2.score = player2.score + 2;
                        fprintf(debug, "\ncomputer score: %d", player2.score);
                    }
                    else
                    {
                        complete_tc = 0;
                    }
                }

                n_lines--;
                fprintf(debug, "\nremaining lines: %d", n_lines);
                counter++;
            }
        }

        system("cls");
        show_grid(n, grid, moves, no_moves, mode, n_lines, t);
        fprintf(debug, "\n\n");
        for (int i = 0; i< (3*n+2); i++)
        {
            for (int j =0; j < (5 *n + 3); j++)
                fprintf(debug, "%c", grid[i][j]);
            fprintf(debug, "\n");
        }
        if (ch_error == 1 && (turn == 2 || tc == 2))
        {
            printf (RED "there are no moves to undo\n" COLOR_RESET);
            fprintf(debug, "\nthere are no moves to undo");
        }
        else if (ch_error == 1 && (turn == 1 || tc == 1))
        {
            printf (BLUE "\t\t\t\t\t\t\t\t\t there are no moves to undo\n" COLOR_RESET);
            fprintf(debug, "\nthere are no moves to undo");
        }
        else if (ch_error == 2 && (turn == 1 ||tc == 1))
        {
            printf(RED "there are no moves to redo\n" COLOR_RESET);
            fprintf(debug, "\nthere are no moves to redo");
        }
        else if (ch_error == 2 && (turn == 2 ||tc == 2))
        {
            printf(BLUE "\t\t\t\t\t\t\t\t\t there are no moves to redo\n" COLOR_RESET);
            fprintf(debug, "\nthere are no moves to redo");
        }
        ch_error=0;

        if (computer == 0)
        {
            if (complete_turn == 0 && ch_redo != 0)
            {
                turn = turn + pow(-1, turn + 1);
            }
            else {}
        }
        else if (computer == 1)
        {
            if (complete_tc == 0 && ch_redo != 0)
            {
                tc = tc + pow(-1, tc + 1);
            }
            else {}
        }

        if (n_lines == 0)
        {
            fprintf(debug, "\nEnd Game");
            end_game = 1;
            printf("\t\t\t\t\t\tEND GAME\n");
            if (player1.score > player2.score)
            {
                printf(RED "\t\t\t\t\t\tWinner is: %s\n\t\t\t\t\t\tscore: %d\n" COLOR_RESET, player1.name, player1.score);
                fprintf(debug, "\nWinner is player1  score: %d", player1.score);
                fclose(debug);
                return 1;
            }
            else if (player2.score > player1.score)
            {
                if (mode == 1)
                {
                    printf(BLUE "\t\t\t\t\t\tWinner is: Computer\n\t\t\t\t\t\tscore: %d\n" COLOR_RESET, player2.score);
                    fprintf(debug, "\nWinner is computer  score: %d", player1.score);
                    fclose(debug);
                    return 3;
                }
                else
                {
                    printf(BLUE "\t\t\t\t\t\tWinner is: %s\n\t\t\t\t\t\tscore: %d\n" COLOR_RESET, player2.name, player2.score);
                    fprintf(debug, "\nWinner is player2  score: %d", player2.score);
                    fclose(debug);
                    return 2;
                }
            }
            else
            {
                printf("\t\t\t\t\t\tTIE");
                fprintf(debug, "\nTie");
                fclose(debug);
                return 0;
            }
        }
    }
}

#endif // GAME_LOOP_H_INCLUDED
