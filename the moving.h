#ifndef THE_MOVING_H_INCLUDED
#define THE_MOVING_H_INCLUDED

int move(int x1, int y1, int x2, int y2, int n, char grid[3 *n + 2][5 *n + 3], int complete_array[n][n], int turn, int tc)
{
	int r1, r2, c1, c2;
	r1 = 3 *x1 - 2;
	r2 = 3 *x2 - 2;
	c1 = 5 *y1 - 3;
	c2 = 5 *y2 - 3;

	if (r1 != r2 || c1 != c2)
	{
		if (r1 == r2 && c1 < c2)
		{
			for (int i = 1; i <= 4; i++)
				grid[r1][c1 + i] = 196;
		}

		if (r1 == r2 && c1 > c2)
		{
			for (int i = 1; i <= 4; i++)
				grid[r1][c2 + i] = 196;
		}

		if (c1 == c2 && r1 < r2)
		{
			for (int i = 1; i <= 2; i++)
				grid[r1 + i][c1] = 179;
		}

		if (c1 == c2 && r1 > r2)
		{
			for (int i = 1; i <= 2; i++)
				grid[r2 + i][c1] = 179;
		}
	}

	int ch_complete_box;
	ch_complete_box = check_complete(n, grid, complete_array, turn, tc);
	return ch_complete_box;

}

#endif // THE_MOVING_H_INCLUDED
