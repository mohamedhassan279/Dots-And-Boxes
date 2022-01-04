#ifndef COMPUTER_FUNCTION_H_INCLUDED
#define COMPUTER_FUNCTION_H_INCLUDED

int computer1(int n, char grid[3 *n + 2][5 *n + 3], int moves[2 *n *(n + 1)][6], int *ind, int *no_moves, int complete_array[n][n], int turn, int tc)
{
	int complete_tc = 0;
	int i = 1, done = 0;
	while (i < (n + 2) && !done)
	{
		for (int j = 1; j < (n + 2); j++)
		{
			if (valid_move(i, j, i, j + 1, n, grid))
			{
				*no_moves = *no_moves + 1;
				complete_tc = move(i, j, i, j + 1, n, grid, complete_array, turn, tc);
				player2.nmoves++;
				moves[*ind][0] = i;
				moves[*ind][1] = j;
				moves[*ind][2] = i;
				moves[*ind][3] = j + 1;
				moves[*ind][4] = 2;
				moves[*ind][5] = complete_tc;
				*ind = *ind + 1;
				return complete_tc;
				done = 1;
				break;
			}
			else if (valid_move(i, j, i + 1, j, n, grid))
			{
			    *no_moves = *no_moves + 1;
				complete_tc = move(i, j, i + 1, j, n, grid, complete_array, turn, tc);
				player2.nmoves++;
				moves[*ind][0] = i;
				moves[*ind][1] = j;
				moves[*ind][2] = i + 1;
				moves[*ind][3] = j;
				moves[*ind][4] = 2;
				moves[*ind][5] = complete_tc;
				*ind = *ind + 1;

				return complete_tc;
				done = 1;
				break;
			}
		}

		i++;
	}
}

#endif // COMPUTER_FUNCTION_H_INCLUDED
