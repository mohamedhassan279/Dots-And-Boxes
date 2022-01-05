#ifndef SCORE_SORTING_H_INCLUDED
#define SCORE_SORTING_H_INCLUDED

void sort_gamers(gamer gamer_list[MAX])
{
	gamer temp;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = i + 1; j < MAX; j++)
		{
			if (gamer_list[j].score > gamer_list[i].score)
			{
				temp = gamer_list[i];
				gamer_list[i] = gamer_list[j];
				gamer_list[j] = temp;
			}
		}
	}
}

#endif // SCORE_SORTING_H_INCLUDED
