#ifndef PLAYER_LIST_H_INCLUDED
#define PLAYER_LIST_H_INCLUDED

typedef struct
{
    int name_len;
    char name[MAX];
    int score;

} gamer;

gamer winners_list[MAX] = {0};

#endif // PLAYER_LIST_H_INCLUDED
