#ifndef GAME_LOOP_H_INCLUDED
#define GAME_LOOP_H_INCLUDED

// game loop
int game(int n, int mode, char grid[3 * n + 2][5 * n + 3], int turn, int tc, int n_lines, int moves[n_lines][5], int complete_array[n][n], int no_moves, int name1_length, int name2_length, int loaded)
{
    time_t savedtime;
    int t0 = time(&savedtime);
    t0 -= loaded;
                           int x = (3 * n + 2) * (5 * n + 3);


    int row1, col1, row2, col2, computer, complete_turn = 0, complete_tc = 0, ind = 0;
	char pl;

	if (mode == 1)
	{
		computer = 1;
	}

    show_grid(n, grid, moves, no_moves, mode, n_lines, t0);

    while(1)
    {
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
			printf(RED "Enter the first point\nRow: " COLOR_RESET);
			row1 = read_point();
			printf(RED "col: " COLOR_RESET);
			col1 = read_point();
			printf(RED "Enter the second point\nRow: " COLOR_RESET);
			row2 = read_point();
			printf(RED "Col: " COLOR_RESET);
			col2 = read_point();
		}
		else if (turn == 2)
		{
			printf(BLUE "\t\t\t\t\t\t\t\t\t Enter the first point\n\t\t\t\t\t\t\t\t\t Row: " COLOR_RESET);
			row1 = read_point();
			printf(BLUE "\t\t\t\t\t\t\t\t\t Col: " COLOR_RESET);
			col1 = read_point();
			printf(BLUE "\t\t\t\t\t\t\t\t\t Enter the second point\n\t\t\t\t\t\t\t\t\t Row: "COLOR_RESET);
			row2 = read_point();
			printf(BLUE "\t\t\t\t\t\t\t\t\t Col: " COLOR_RESET);
			col2 = read_point();
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
					printf(MAGENTA "\t\t\t\t\t\t Dots And Boxes\n" COLOR_RESET);
					show_grid(n, grid, moves, no_moves, mode, n_lines, t0);

					printf("Not allowed\n");
					printf(RED "Enter the first point\nRow: " COLOR_RESET);
					row1 = read_point();
					printf(RED "col: " COLOR_RESET);
					col1 = read_point();
					printf(RED "Enter the second point\nRow: " COLOR_RESET);
					row2 = read_point();
					printf(RED "Col: " COLOR_RESET);
					col2 = read_point();
				}
				else if (turn == 2)
				{
					system("cls");
					printf(MAGENTA "\t\t\t\t\t\t Dots And Boxes\n" COLOR_RESET);
					show_grid(n, grid, moves, no_moves, mode, n_lines, t0);
					printf("\t\t\t\t\t\t\t\t\t Not allowed\n");
					printf(BLUE "\t\t\t\t\t\t\t\t\t Enter the first point\n\t\t\t\t\t\t\t\t\t Row: " COLOR_RESET);
					row1 = read_point();
					printf(BLUE "\t\t\t\t\t\t\t\t\t Col: " COLOR_RESET);
					col1 = read_point();
					printf(BLUE "\t\t\t\t\t\t\t\t\t Enter the second point\n\t\t\t\t\t\t\t\t\t Row: " COLOR_RESET);
					row2 = read_point();
					printf(BLUE "\t\t\t\t\t\t\t\t\t Col: " COLOR_RESET);
					col2 = read_point();
				}
			}

			
			if (turn == 1)
			{
				player1.nmoves++;
				no_moves++;
				moves[ind][0] = row1;
				moves[ind][1] = col1;
				moves[ind][2] = row2;
				moves[ind][3] = col2;
				moves[ind++][4] = 1;
			}

			if (turn == 2)
			{
				player2.nmoves++;
				no_moves++;
				moves[ind][0] = row1;
				moves[ind][1] = col1;
				moves[ind][2] = row2;
				moves[ind][3] = col2;
				moves[ind++][4] = 2;
			}

			complete_turn = move(row1, col1, row2, col2, n, grid, complete_array, turn, tc);
			if (turn == 1)
			{
				if (complete_turn == 1)
				{
					player1.score++;
				}
				else if (complete_turn == 2)
				{
					player1.score = player1.score + 2;
				}
				else if (complete_turn == 3)
				{
					player1.score = player1.score + 2;
				}
				else {}
			}
			else if (turn == 2)
			{
				if (complete_turn == 1)
				{
					player2.score++;
				}
				else if (complete_turn == 2)
				{
					player2.score = player2.score + 2;
				}
				else if (complete_turn == 3)
				{
					player2.score = player2.score + 2;
				}
				else {}
			}

			n_lines--;
		}
		else if (computer == 1)
		{
			if (tc == 1)
			{
				while (!valid_move(row1, col1, row2, col2, n, grid))
				{
					system("cls");
					printf(MAGENTA "\t\t\t\t\t\t Dots And Boxes\n"
						COLOR_RESET);
					show_grid(n, grid, moves, no_moves, mode, n_lines, t0);
					printf("Not allowed\n");
					printf(RED "Enter the first point\nRow: " COLOR_RESET);
					row1 = read_point();
					printf(RED "col: " COLOR_RESET);
					col1 = read_point();
					printf(RED "Enter the second point\nRow: "
						COLOR_RESET);
					row2 = read_point();
					printf(RED "Col: "
						COLOR_RESET);
					col2 = read_point();
				}

				if (tc == 1)
				{
					player1.nmoves++;
					no_moves++;
					moves[ind][0] = row1;
					moves[ind][1] = col1;
					moves[ind][2] = row2;
					moves[ind][3] = col2;
					moves[ind++][4] = 1;
				}

				complete_tc = move(row1, col1, row2, col2, n, grid, complete_array, turn, tc);
				if (tc == 1)
				{
					if (complete_tc == 1)
					{
						player1.score++;
					}
					else if (complete_tc == 2)
					{
						player1.score = player1.score + 2;
					}
					else if (complete_tc == 3)
					{
						player1.score = player1.score + 2;
					}
					else {}
				}
				else if (tc == 2)
				{
					if (complete_tc == 1)
					{
						player2.score++;
					}
					else if (complete_tc == 2)
					{
						player2.score = player2.score + 2;
					}
					else if (complete_tc == 3)
					{
						player2.score = player2.score + 2;
					}
					else {}
				}

				n_lines--;
			}
			else if (tc == 2)
			{
				printf(BLUE "computer %c \n"
					COLOR_RESET);
				complete_tc = 0;
				complete_tc = computer1(n, grid, moves, &ind, &no_moves, complete_array, turn, tc);
				if (tc == 1)
				{
					if (complete_tc == 1)
					{
						player1.score++;
					}
					else if (complete_tc == 2)
					{
						player1.score = player1.score + 2;
					}
					else if (complete_tc == 3)
					{
						player1.score = player1.score + 2;
					}
					else
					{
						complete_tc = 0;
					}
				}
				else if (tc == 2)
				{
					if (complete_tc == 1)
					{
						player2.score++;
					}
					else if (complete_tc == 2)
					{
						player2.score = player2.score + 2;
					}
					else if (complete_tc == 3)
					{
						player2.score = player2.score + 2;
					}
					else
					{
						complete_tc = 0;
					}
				}

				n_lines--;
			}
		}

		system("cls");
		printf(MAGENTA "\t\t\t\t\t\t Dots And Boxes\n"
			COLOR_RESET);
		show_grid(n, grid, moves, no_moves, mode, n_lines, t0);

		if (computer == 0)
		{
			if (complete_turn == 0)
			{
				turn = turn + pow(-1, turn + 1);
			}
			else {}
		}
		else if (computer == 1)
		{
			if (complete_tc == 0)
			{
				tc = tc + pow(-1, tc + 1);
			}
			else {}
		}

		if (n_lines == 0)
		{
			break;
		}
	}
	if(no_moves == n_lines){
	printf("\t\t\t\t\t\tEND GAME\n");
	if(player1.score > player2.score)
    {
        printf(RED "\t\t\t\t\t\t%s WIN" COLOR_RESET, player1.name);
        turn = 1;
    }
    else if(player2.score > player1.score)
    {
        printf(BLUE "\t\t\t\t\t\t%s WIN" COLOR_RESET, player2.name);
        turn = 2;
    }
    else
    {
        printf("TIE");
        turn = 0;
    }
    return turn;
	}
}

#endif // GAME_LOOP_H_INCLUDED
