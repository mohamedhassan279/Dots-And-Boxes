#ifndef UNDO_AND_REDO_H_INCLUDED
#define UNDO_AND_REDO_H_INCLUDED

// undo and redo function
void undo(int counter, int n, char grid[3 *n + 2][5 *n + 3], int moves[2 *n *(n + 1)][6], int complete_array[n][n], int inverse_uarray[n][n])
{
	char h_l = 196, v_l = 179;
	int x1, y1, x2, y2, r1, c1, r2, c2, ch_complete, t;
	x1 = moves[counter - 1][0];
	y1 = moves[counter - 1][1];
	x2 = moves[counter - 1][2];
	y2 = moves[counter - 1][3];
	t = moves[counter - 1][4];
	ch_complete = moves[counter - 1][5];
	r1 = 3 *x1 - 2;
	r2 = 3 *x2 - 2;
	c1 = 5 *y1 - 3;
	c2 = 5 *y2 - 3;

	if (ch_complete == 0)
	{
		if (r1 == r2 && c1 < c2)
		{
			if (grid[r1][c1 + 1] == h_l)
			{
				for (int i = 1; i <= 4; i++)
					grid[r1][c1 + i] = ' ';
			}
		}

		if (r1 == r2 && c1 > c2)
		{
			if (grid[r1][c2 + 1] == h_l)
			{
				for (int i = 1; i <= 4; i++)
					grid[r1][c2 + i] = ' ';
			}
		}

		if (c1 == c2 && r1 < r2)
		{
			if (grid[r1 + 1][c1] == v_l)
			{
				for (int i = 1; i <= 2; i++)
					grid[r1 + i][c1] = ' ';
			}
		}

		if (c1 == c2 && r1 > r2)
		{
			if (grid[r2 + 1][c1] == v_l)
			{
				for (int i = 1; i <= 2; i++)
					grid[r2 + i][c1] = ' ';
			}
		}
	}
	else if (ch_complete == 1)
	{
		if (r1 == r2 && c1 < c2)
		{
			for (int i = 1; i <= 4; i++)
			{
				grid[r1][c1 + i] = ' ';
			}

			if (complete_array[x1 - 2][y1 - 1] == 1)
			{
				for (int i = r1 - 2; i < r1; i++)
				{
					for (int j = c1 + 1; j < c1 + 5; j++)
					{
						grid[i][j] = ' ';
						complete_array[x1 - 2][y1 - 1] = 0;
						inverse_uarray[x1 - 2][y1 - 1] = 1;
					}
				}
			}
			else if (complete_array[x1 - 1][y1 - 1] == 1)
			{
				for (int i = r1 + 1; i < r1 + 3; i++)
				{
					for (int j = c1 + 1; j < c1 + 5; j++)
					{
						grid[i][j] = ' ';
						complete_array[x1 - 1][y1 - 1] = 0;
						inverse_uarray[x1 - 1][y1 - 1] = 1;
					}
				}
			}
		}

		if (r1 == r2 && c1 > c2)
		{
			for (int i = 1; i <= 4; i++)
			{
				grid[r1][c2 + i] = ' ';
			}

			if (complete_array[x1 - 2][y2 - 1] == 1)
			{
				for (int i = r1 - 2; i < r1; i++)
				{
					for (int j = c2 + 1; j < c2 + 5; j++)
					{
						grid[i][j] = ' ';
						complete_array[x1 - 2][y2 - 1] = 0;
						inverse_uarray[x1 - 2][y2 - 1] = 1;
					}
				}
			}
			else if (complete_array[x1 - 1][y2 - 1] == 1)
			{
				for (int i = r1 + 1; i < r1 + 3; i++)
				{
					for (int j = c2 + 1; j < c2 + 5; j++)
					{
						grid[i][j] = ' ';
						complete_array[x1 - 1][y2 - 1] = 0;
						inverse_uarray[x1 - 1][y2 - 1] = 1;
					}
				}
			}
		}

		if (c1 == c2 && r1 < r2)
		{
			for (int i = 1; i <= 2; i++)
			{
				grid[r1 + i][c1] = ' ';
			}

			if (complete_array[x1 - 1][y1 - 2] == 1)
			{
				for (int i = r1 + 1; i < r1 + 3; i++)
				{
					for (int j = c1 - 4; j < c1; j++)
					{
						grid[i][j] = ' ';
						complete_array[x1 - 1][y1 - 2] = 0;
						inverse_uarray[x1 - 1][y1 - 2] = 1;
					}
				}
			}
			else if (complete_array[x1 - 1][y1 - 1] == 1)
			{
				for (int i = r1 + 1; i < r1 + 3; i++)
				{
					for (int j = c1 + 1; j < c1 + 5; j++)
					{
						grid[i][j] = ' ';
						complete_array[x1 - 1][y1 - 1] = 0;
						inverse_uarray[x1 - 1][y1 - 1] = 1;
					}
				}
			}
		}

		if (c1 == c2 && r1 > r2)
		{
			for (int i = 1; i <= 2; i++)
			{
				grid[r2 + i][c1] = ' ';
			}

			if (complete_array[x2 - 1][y1 - 2] == 1)
			{
				for (int i = r2 + 1; i < r2 + 3; i++)
				{
					for (int j = c1 - 4; j < c1; j++)
					{
						grid[i][j] = ' ';
						complete_array[x2 - 1][y1 - 2] = 0;
						inverse_uarray[x2 - 1][y1 - 2] = 1;
					}
				}
			}
			else if (complete_array[x2 - 1][y1 - 1] == 1)
			{
				for (int i = r2 + 1; i < r2 + 3; i++)
				{
					for (int j = c1 + 1; j < c1 + 5; j++)
					{
						grid[i][j] = ' ';
						complete_array[x2 - 1][y1 - 1] = 0;
						inverse_uarray[x2 - 1][y1 - 1] = 1;
					}
				}
			}
		}
	}
	else if (ch_complete == 2)
	{
		if (r1 == r2 && c1 < c2)
		{
			for (int i = 1; i <= 4; i++)
			{
				grid[r1][c1 + i] = ' ';
			}

			for (int i = r1 - 2; i < r1 + 3; i++)
			{
				for (int j = c1 + 1; j < c1 + 5; j++)
				{
					grid[i][j] = ' ';
					complete_array[x1 - 2][y1 - 1] = 0;
					inverse_uarray[x1 - 2][y1 - 1] = 1;
					complete_array[x1 - 1][y1 - 1] = 0;
					inverse_uarray[x1 - 1][y1 - 1] = 1;
				}
			}
		}

		if (r1 == r2 && c1 > c2)
		{
			for (int i = 1; i <= 4; i++)
			{
				grid[r1][c2 + i] = ' ';
			}

			for (int i = r1 - 2; i < r1 + 3; i++)
			{
				for (int j = c2 + 1; j < c2 + 5; j++)
				{
					grid[i][j] = ' ';
					complete_array[x1 - 2][y2 - 1] = 0;
					inverse_uarray[x1 - 2][y2 - 1] = 1;
					complete_array[x1 - 1][y2 - 1] = 0;
					inverse_uarray[x1 - 1][y2 - 1] = 1;
				}
			}
		}
	}
	else if (ch_complete == 3)
	{
		if (c1 == c2 && r1 < r2)
		{
			for (int i = 1; i <= 2; i++)
			{
				grid[r1 + i][c1] = ' ';
			}

			for (int i = r1 + 1; i < r1 + 3; i++)
			{
				for (int j = c1 - 4; j < c1 + 5; j++)
				{
					grid[i][j] = ' ';
					complete_array[x1 - 1][y1 - 2] = 0;
					inverse_uarray[x1 - 1][y1 - 2] = 1;
					complete_array[x1 - 1][y1 - 1] = 0;
					inverse_uarray[x1 - 1][y1 - 1] = 1;
				}
			}
		}

		if (c1 == c2 && r1 > r2)
		{
			for (int i = 1; i <= 2; i++)
			{
				grid[r2 + i][c1] = ' ';
			}

			for (int i = r2 + 1; i < r2 + 3; i++)
			{
				for (int j = c1 - 4; j < c1 + 5; j++)
				{
					grid[i][j] = ' ';
					complete_array[x2 - 1][y1 - 2] = 0;
					inverse_uarray[x2 - 1][y1 - 2] = 1;
					complete_array[x2 - 1][y1 - 1] = 0;
					inverse_uarray[x2 - 1][y1 - 1] = 1;
				}
			}
		}
	}
}

//redo function
void redo(int counter, int n, char grid[3 *n + 2][5 *n + 3], int moves[2 *n *(n + 1)][6], int complete_array[n][n], int inverse_uarray[n][n])
{
	char h_l = 196, v_l = 179;
	int x1, y1, x2, y2, r1, c1, r2, c2, ch_complete, t;
	x1 = moves[counter][0];
	y1 = moves[counter][1];
	x2 = moves[counter][2];
	y2 = moves[counter][3];
	t = moves[counter][4];
	ch_complete = moves[counter][5];
	r1 = 3 *x1 - 2;
	r2 = 3 *x2 - 2;
	c1 = 5 *y1 - 3;
	c2 = 5 *y2 - 3;

	if (ch_complete == 0)
	{
		if (r1 == r2 && c1 < c2)
		{
			if (grid[r1][c1 + 1] == ' ')
			{
				for (int i = 1; i <= 4; i++)
				{
					if (t == 1)
					{
						grid[r1][c1 + i] = h_l;
					}
					else if (t == 2)
					{
						grid[r1][c1 + i] = h_l;
					}
				}
			}
		}

		if (r1 == r2 && c1 > c2)
		{
			if (grid[r1][c2 + 1] == ' ')
			{
				for (int i = 1; i <= 4; i++)
				{
					if (t == 1)
					{
						grid[r1][c2 + i] = h_l;
					}
					else if (t == 2)
					{
						grid[r1][c2 + i] = h_l;
					}
				}
			}
		}

		if (c1 == c2 && r1 < r2)
		{
			if (grid[r1 + 1][c1] == ' ')
			{
				for (int i = 1; i <= 2; i++)
				{
					if (t == 1)
					{
						grid[r1 + i][c1] = v_l;
					}
					else if (t == 2)
					{
						grid[r1 + i][c1] = v_l;
					}
				}
			}
		}

		if (c1 == c2 && r1 > r2)
		{
			if (grid[r2 + 1][c1] == ' ')
			{
				for (int i = 1; i <= 2; i++)
				{
					if (t == 1)
					{
						grid[r2 + i][c1] = v_l;
					}
					else if (t == 2)
					{
						grid[r2 + i][c1] = v_l;
					}
				}
			}
		}
	}
	else if (ch_complete == 1)
	{
		if (r1 == r2 && c1 < c2)
		{
			for (int i = 1; i <= 4; i++)
			{
				if (t == 1)
				{
					grid[r1][c1 + i] = h_l;
				}
				else if (t == 2)
				{
					grid[r1][c1 + i] = h_l;
				}
			}

			if (inverse_uarray[x1 - 2][y1 - 1] == 1)
			{
				for (int i = r1 - 2; i < r1; i++)
				{
					for (int j = c1 + 1; j < c1 + 5; j++)
					{
						if (t == 1)
						{
							grid[i][j] = 'a';
						}
						else if (t == 2)
						{
							grid[i][j] = 'b';
						}

						complete_array[x1 - 2][y1 - 1] = 1;
						inverse_uarray[x1 - 2][y1 - 1] = 0;
					}
				}
			}
			else if (inverse_uarray[x1 - 1][y1 - 1] == 1)
			{
				for (int i = r1 + 1; i < r1 + 3; i++)
				{
					for (int j = c1 + 1; j < c1 + 5; j++)
					{
						if (t == 1)
						{
							grid[i][j] = 'a';
						}
						else if (t == 2)
						{
							grid[i][j] = 'b';
						}

						complete_array[x1 - 1][y1 - 1] = 1;
						inverse_uarray[x1 - 1][y1 - 1] = 0;
					}
				}
			}
		}

		if (r1 == r2 && c1 > c2)
		{
			for (int i = 1; i <= 4; i++)
			{
				if (t == 1)
				{
					grid[r1][c2 + i] = h_l;
				}
				else if (t == 2)
				{
					grid[r1][c2 + i] = h_l;
				}
			}

			if (inverse_uarray[x1 - 2][y2 - 1] == 1)
			{
				for (int i = r1 - 2; i < r1; i++)
				{
					for (int j = c2 + 1; j < c2 + 5; j++)
					{
						if (t == 1)
						{
							grid[i][j] = 'a';
						}
						else if (t == 2)
						{
							grid[i][j] = 'b';
						}

						complete_array[x1 - 2][y2 - 1] = 1;
						inverse_uarray[x1 - 2][y2 - 1] = 0;
					}
				}
			}
			else if (inverse_uarray[x1 - 1][y2 - 1] == 1)
			{
				for (int i = r1 + 1; i < r1 + 3; i++)
				{
					for (int j = c2 + 1; j < c2 + 5; j++)
					{
						if (t == 1)
						{
							grid[i][j] = 'a';
						}
						else if (t == 2)
						{
							grid[i][j] = 'b';
						}

						complete_array[x1 - 1][y2 - 1] = 1;
						inverse_uarray[x1 - 1][y2 - 1] = 0;
					}
				}
			}
		}

		if (c1 == c2 && r1 < r2)
		{
			for (int i = 1; i <= 2; i++)

			{
				if (t == 1)
				{
					grid[r1 + i][c1] = v_l;
				}
				else if (t == 2)
				{
					grid[r1 + i][c1] = v_l;
				}
			}

			if (inverse_uarray[x1 - 1][y1 - 2] == 1)
			{
				for (int i = r1 + 1; i < r1 + 3; i++)
				{
					for (int j = c1 - 4; j < c1; j++)
					{
						if (t == 1)
						{
							grid[i][j] = 'a';
						}
						else if (t == 2)
						{
							grid[i][j] = 'b';
						}

						complete_array[x1 - 1][y1 - 2] = 1;
						inverse_uarray[x1 - 1][y1 - 2] = 0;
					}
				}
			}
			else if (inverse_uarray[x1 - 1][y1 - 1] == 1)
			{
				for (int i = r1 + 1; i < r1 + 3; i++)
				{
					for (int j = c1 + 1; j < c1 + 5; j++)
					{
						if (t == 1)
						{
							grid[i][j] = 'a';
						}
						else if (t == 2)
						{
							grid[i][j] = 'b';
						}

						complete_array[x1 - 1][y1 - 1] = 1;
						inverse_uarray[x1 - 1][y1 - 1] = 0;
					}
				}
			}
		}

		if (c1 == c2 && r1 > r2)
		{
			for (int i = 1; i <= 2; i++)
			{
				if (t == 1)
				{
					grid[r2 + i][c1] = v_l;
				}
				else if (t == 2)
				{
					grid[r2 + i][c1] = v_l;
				}
			}

			if (inverse_uarray[x2 - 1][y1 - 2] == 1)
			{
				for (int i = r2 + 1; i < r2 + 3; i++)
				{
					for (int j = c1 - 4; j < c1; j++)
					{
						if (t == 1)
						{
							grid[i][j] = 'a';
						}
						else if (t == 2)
						{
							grid[i][j] = 'b';
						}

						complete_array[x2 - 1][y1 - 2] = 1;
						inverse_uarray = 0;
					}
				}
			}
			else if (inverse_uarray[x2 - 1][y1 - 1] == 1)
			{
				for (int i = r2 + 1; i < r2 + 3; i++)
				{
					for (int j = c1 + 1; j < c1 + 5; j++)
					{
						if (t == 1)
						{
							grid[i][j] = 'a';
						}
						else if (t == 2)
						{
							grid[i][j] = 'b';
						}

						complete_array[x2 - 1][y1 - 1] = 1;
						inverse_uarray[x2 - 1][y1 - 1] = 0;
					}
				}
			}
		}
	}
	else if (ch_complete == 2)
	{
		if (r1 == r2 && c1 < c2)
		{
			for (int i = 1; i <= 4; i++)
			{
				grid[r1][c1 + i] = h_l;
			}

			for (int i = r1 - 2; i < r1 + 3; i++)
			{
				for (int j = c1 + 1; j < c1 + 5; j++)
				{
					if (t == 1)
					{
						grid[i][j] = 'a';
					}
					else if (t == 2)
					{
						grid[i][j] = 'b';
					}

					complete_array[x1 - 2][y1 - 1] = 1;
					inverse_uarray[x1 - 2][y1 - 1] = 0;
					complete_array[x1 - 1][y1 - 1] = 1;
					inverse_uarray[x1 - 1][y1 - 1] = 0;
				}
			}
		}

		if (r1 == r2 && c1 > c2)
		{
			for (int i = 1; i <= 4; i++)
			{
				grid[r1][c2 + i] = h_l;
			}

			for (int i = r1 - 2; i < r1 + 3; i++)
			{
				for (int j = c2 + 1; j < c2 + 5; j++)
				{
					if (t == 1)
					{
						grid[i][j] = 'a';
					}
					else if (t == 2)
					{
						grid[i][j] = 'b';
					}

					complete_array[x1 - 2][y2 - 1] = 1;
					inverse_uarray[x1 - 2][y2 - 1] = 0;
					complete_array[x1 - 1][y2 - 1] = 1;
					inverse_uarray[x1 - 1][y2 - 1] = 0;
				}
			}
		}
	}
	else if (ch_complete == 3)
	{
		if (c1 == c2 && r1 < r2)
		{
			for (int i = 1; i <= 2; i++)
			{
				grid[r1 + i][c1] = v_l;
			}

			for (int i = r1 + 1; i < r1 + 3; i++)
			{
				for (int j = c1 - 4; j < c1 + 5; j++)
				{
					if (t == 1)
					{
						grid[i][j] = 'a';
					}
					else if (t == 2)
					{
						grid[i][j] = 'b';
					}

					complete_array[x1 - 1][y1 - 2] = 1;
					inverse_uarray[x1 - 1][y1 - 2] = 0;
					complete_array[x1 - 1][y1 - 1] = 1;
					inverse_uarray[x1 - 1][y1 - 1] = 0;
				}
			}
		}

		if (c1 == c2 && r1 > r2)
		{
			for (int i = 1; i <= 2; i++)
			{
				grid[r2 + i][c1] = v_l;
			}

			for (int i = r2 + 1; i < r2 + 3; i++)
			{
				for (int j = c1 - 4; j < c1 + 5; j++)
				{
					if (t == 1)
					{
						grid[i][j] = 'a';
					}
					else if (t == 2)
					{
						grid[i][j] = 'b';
					}

					complete_array[x2 - 1][y1 - 2] = 1;
					inverse_uarray[x2 - 1][y1 - 2] = 0;
					complete_array[x2 - 1][y1 - 1] = 1;
					inverse_uarray[x2 - 1][y1 - 1] = 0;
				}
			}
		}
	}
}




#endif // UNDO_AND_REDO_H_INCLUDED
