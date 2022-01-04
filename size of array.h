#ifndef SIZE_OF_ARRAY_H_INCLUDED
#define SIZE_OF_ARRAY_H_INCLUDED

int size_of_array()
{
	printf(YELLOW "\nChoose The Game Level:- \n\n" COLOR_RESET);
	printf(MAGENTA "Easy 2x2 board (Please Enter 1) :\n" COLOR_RESET);
	printf(MAGENTA "Medium 3x3 board (Please Enter 2) :\n" COLOR_RESET);
	printf(MAGENTA "Hard 4x4 board (Please Enter 3) :\n" COLOR_RESET);
	printf(MAGENTA "Extremely Hard 5x5 board (Please Enter 4) :\n" COLOR_RESET);
	char size_choice[MAX];
	gets(size_choice);
	int size_length = strlen(size_choice);

	while (size_length > 1)
	{
		system("cls");
		printf(YELLOW "Choose The Game Level:- \n\n" COLOR_RESET);
		printf(MAGENTA "Easy 2x2 board (Please Enter 1) :\n" COLOR_RESET);
		printf(MAGENTA "Medium 3x3 board (Please Enter 2) :\n" COLOR_RESET);
		printf(MAGENTA "Hard 4x4 board (Please Enter 3) :\n" COLOR_RESET);
		printf(MAGENTA "Extremely Hard 5x5 board (Please Enter 4) :\n" COLOR_RESET);
		printf(RED "please enter a valid number\n" COLOR_RESET);
		gets(size_choice);
		size_length = strlen(size_choice);
	}

	int s;
	if (size_choice[0] > 48 && size_choice[0] < 53)
	{
		s = size_choice[0] - 48;
	}
	else
	{
		while (size_choice[0] <= 48 || size_choice[0] >= 53)
		{
			system("cls");
			printf(YELLOW "Choose The Game Level:- \n\n" COLOR_RESET);
			printf(MAGENTA "Easy 2x2 board (Please Enter 1) :\n" COLOR_RESET);
			printf(MAGENTA "Medium 3x3 board (Please Enter 2) :\n" COLOR_RESET);
			printf(MAGENTA "Hard 4x4 board (Please Enter 3) :\n" COLOR_RESET);
			printf(MAGENTA "Extremely Hard 5x5 board (Please Enter 4) :\n" COLOR_RESET);
			printf(RED "please enter a valid number\n" COLOR_RESET);
			gets(size_choice);
			size_length = strlen(size_choice);
			while (size_length > 1)
			{
				system("cls");
				printf(YELLOW "Choose The Game Level:- \n\n" COLOR_RESET);
				printf(MAGENTA "Easy 2x2 board (Please Enter 1) :\n" COLOR_RESET);
				printf(MAGENTA "Medium 3x3 board (Please Enter 2) :\n" COLOR_RESET);
				printf(MAGENTA "Hard 4x4 board (Please Enter 3) :\n" COLOR_RESET);
				printf(MAGENTA "Extremely Hard 5x5 board (Please Enter 4) :\n" COLOR_RESET);
				printf(RED "please enter a valid number\n" COLOR_RESET);
				gets(size_choice);
				size_length = strlen(size_choice);
			}
		}

		s = size_choice[0] - 48;
	}

	int n;
	switch (s)
	{
		case 1:
			n = 2;
			break;
		case 2:
			n = 3;
			break;
		case 3:
			n = 4;
			break;
		case 4:
			n = 5;
			break;
	}

	return n;
}


#endif // SIZE_OF_ARRAY_H_INCLUDED
