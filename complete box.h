#ifndef COMPLETE_BOX_H_INCLUDED
#define COMPLETE_BOX_H_INCLUDED

int check_complete(int n, char grid[3 *n + 2][5 *n + 3], int complete_array[n][n], int turn, int tc)
{
	char h_l = 196, v_l = 179;

	int a, b, c, e, f, h;
	int box = 0;
	int chain_h = 0;
	int chain_v = 0;
	a = 1;
	c = 4;
	e = 2;

	for (int i = 0; i < n; i++)
	{
		b = 3;
		f = 2;
		h = 7;
		for (int j = 0; j < n; j++)
		{
			box = 0;
			if (grid[a][b] == h_l && grid[c][b] == h_l && grid[e][f] == v_l && grid[e][h] == v_l && complete_array[i][j] != 1)
			{
				if (grid[c + 1][f] == v_l && grid[c + 1][h] == v_l && grid[c + 3][f + 1] == h_l && complete_array[i][j] != 1 && complete_array[i + 1][j] != 1)
				{
					complete_array[i][j] = 1;
					complete_array[i + 1][j] = 1;
					chain_v = 2;
					if (turn == 1 || tc == 1)
					{
						for (int i = 0; i < 5; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								grid[a + 1 + i][f + 1 + j] = 'a';
							}
						}
					}
					else
					{
						for (int i = 0; i < 5; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								grid[a + 1 + i][f + 1 + j] = 'b';
							}
						}
					}

					return 2;
					break;
				}
				else if (grid[a][h + 1] == h_l && grid[c][h + 1] == h_l && grid[a + 1][h + 5] == v_l && complete_array[i][j] != 1 && complete_array[i][j + 1] != 1)
				{
					complete_array[i][j] = 1;
					complete_array[i][j + 1] = 1;
					chain_h = 3;
					if (turn == 1 || tc == 1)
					{
						for (int i = 0; i < 2; i++)
						{
							for (int j = 0; j < 9; j++)
							{
								grid[a + 1 + i][f + 1 + j] = 'a';
							}
						}
					}
					else
					{
						for (int i = 0; i < 2; i++)
						{
							for (int j = 0; j < 9; j++)
							{
								grid[a + 1 + i][f + 1 + j] = 'b';
							}
						}
					}

					return 3;
					break;
				}
				else
				{
					complete_array[i][j] = 1;
					box = 1;
					if (turn == 1 || tc == 1)
					{
						for (int i = 0; i < 2; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								grid[a + 1 + i][f + 1 + j] = 'a';
							}
						}
					}
					else
					{
						for (int i = 0; i < 2; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								grid[a + 1 + i][f + 1 + j] = 'b';
							}
						}
					}

					return box;
					break;
				}
			}
			else {}

			b = b + 5;
			f = f + 5;
			h = h + 5;
		}

		if (box == 1 || chain_h == 3 || chain_v == 2)
			break;
		a = a + 3;
		c = c + 3;
		e = e + 3;
	}

	if (!(box == 1 || chain_h == 3 || chain_v == 2))
		return 0;
}

#endif // COMPLETE_BOX_H_INCLUDED
