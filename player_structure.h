#ifndef PLAYER_STRUCTURE_H_INCLUDED
#define PLAYER_STRUCTURE_H_INCLUDED

typedef struct
{
	int name_len;
	char name[MAX];
	int score;
	int nmoves;

}player;

player player1 = {0, ' ', 0, 0};
player player2 = {0, ' ', 0, 0};

#endif // PLAYER_STRUCTURE_H_INCLUDED
