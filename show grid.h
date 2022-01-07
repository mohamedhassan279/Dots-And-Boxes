#ifndef SHOW_GRID_H_INCLUDED
#define SHOW_GRID_H_INCLUDED

void show_grid(int n, char arr[3 *n + 2][5 *n + 3], int moves[2 *n *(n + 1)][6], int no_moves, int mode, int n_lines, int t)
{
	time_t currenttime;
	int current = time(&currenttime);
	int seconds = (current - t) % 60;
	int minutes = (current - t) / 60;
	char h_l = 196, v_l = 179;

	printf("\t\t\t\t\t\t");
	int i, j;

	for (i = 0; i < (5 *n + 3); i++)
	{
		printf("%c", arr[0][i]);
	}

	printf("\n");

	for (i = 1; i < (3 *n + 2); i++)
	{
		printf("\t\t\t\t\t\t");

		for (j = 0; j < (5 *n + 3); j++)
		{
			if (arr[i][j] != h_l && arr[i][j] != v_l && arr[i][j] != 'a' && arr[i][j] != 'b')
			{
				printf("%c", arr[i][j]);
			}
			else if (arr[i][j] == 'a')
			{
				printf(RED_SPACE " " COLOR_RESET);
			}
			else if (arr[i][j] == 'b')
			{
				printf(BLUE_SPACE " " COLOR_RESET);
			}
			else
			{
				for (int c = 0; c < no_moves; c++)
				{
					if (moves[c][0] == moves[c][2] && moves[c][1] < moves[c][3])
					{
						if ((3 *moves[c][0] - 2) == i && j > (5 *moves[c][1] - 3) && j < (5 *moves[c][3] - 3))
						{
							if (moves[c][4] == 1)
								printf(RED);
							else
								printf(BLUE);
						}
					}

					if (moves[c][0] == moves[c][2] && moves[c][1] > moves[c][3])
					{
						if ((3 *moves[c][0] - 2) == i && j > (5 *moves[c][3] - 3) && j < (5 *moves[c][1] - 3))
						{
							if (moves[c][4] == 1)
								printf(RED);
							else
								printf(BLUE);
						}
					}

					if (moves[c][1] == moves[c][3] && moves[c][0] < moves[c][2])
					{
						if (i > (3 *moves[c][0] - 2) && i < (3 *moves[c][2] - 2) && j == (5 *moves[c][1] - 3))
						{
							if (moves[c][4] == 1)
								printf(RED);
							else
								printf(BLUE);
						}
					}

					if (moves[c][1] == moves[c][3] && moves[c][0] > moves[c][2])
					{
						if (i > (3 *moves[c][2] - 2) && i < (3 *moves[c][0] - 2) && j == (5 *moves[c][1] - 3))
						{
							if (moves[c][4] == 1)
								printf(RED);
							else
								printf(BLUE);
						}
					}
				}

				printf("%c" COLOR_RESET, arr[i][j]);
			}
		}

		printf("\n");
	}

	printf("\n\n");
	if (mode == 2)
	{
		printf(RED "player1 name: %s " COLOR_RESET, player1.name);
		printf(BLUE " \t\t\t\t\t\t\t player2 name: %s \n" COLOR_RESET, player2.name);
	}
	else if (mode == 1)
	{
		printf(RED "player1 name: %s " COLOR_RESET, player1.name);
		printf(BLUE " \t\t\t\t\t\t\t player2 name: computer \n" COLOR_RESET);
	}

	printf(RED "Number of moves for player1: %d " COLOR_RESET, player1.nmoves);
	printf(BLUE " \t\t\t\t\t Number of moves for player2: %d \n" COLOR_RESET, player2.nmoves);
	printf(RED "player1 score: %d " COLOR_RESET, player1.score);
	printf(BLUE " \t\t\t\t\t\t\t player2 score: %d \n\n" COLOR_RESET, player2.score);
	printf(YELLOW "Number of remaining lines: %d " COLOR_RESET, n_lines);
	printf(GREEN "\t\t\t\t\t\tTime passed:  %.2d:%.2d \n\n" COLOR_RESET, minutes, seconds);
	printf(YELLOW "Enter:    " COLOR_RESET);
	printf(CYAN " (0,0)(0,0) for main menu\t (7,7)(7,7) to save\t (8,8)(8,8) to undo\t (9,9)(9,9) to redo \n\n" COLOR_RESET);

}

#endif // SHOW_GRID_H_INCLUDED
