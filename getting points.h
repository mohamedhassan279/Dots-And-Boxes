#ifndef GETTING_POINTS_H_INCLUDED
#define GETTING_POINTS_H_INCLUDED

int read_point()
{
	char getstr[MAX];

	gets(getstr);
	int length = strlen(getstr);
	int s;
	if (length == 1)
	{
		if (getstr[0] >= 48 && getstr[0] <= 57)
		{
			s = getstr[0] - 48;
			return s;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
}

#endif // GETTING_POINTS_H_INCLUDED
