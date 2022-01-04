#ifndef MAIN_MENU_H_INCLUDED
#define MAIN_MENU_H_INCLUDED

int main_menu()
{
	char choice[MAX];

	printf(CYAN "\t\t\t\t\t\t Welcome To Our Game \n" COLOR_RESET);
	printf(YELLOW "\t\t\t\t\t\t   Dots And Boxes\n\n\n" COLOR_RESET);
	printf(CYAN "\t\t\t\t\t\t     Main Menu \n\n" COLOR_RESET);
	printf(MAGENTA " New Game  (Please Enter 1) :  \n\n" COLOR_RESET);
	printf(MAGENTA " Load Game  (Please Enter 2) :  \n\n" COLOR_RESET);
	printf(MAGENTA " Top Ten Players  (Please Enter 3) :  \n\n" COLOR_RESET);
	printf(MAGENTA " Exit The Game  (Please Enter 4) : \n\n\n\n" COLOR_RESET);
	printf(MAGENTA "Please Enter Your Choice :" COLOR_RESET);

	gets(choice);
	int choice_length = strlen(choice);

	while (choice_length > 1)
	{
		system("cls");
		printf(CYAN "\t\t\t\t\t\t Welcome To Our Game \n" COLOR_RESET);
		printf(YELLOW "\t\t\t\t\t\t   Dots And Boxes\n\n\n" COLOR_RESET);
		printf(CYAN "\t\t\t\t\t\t     Main Menu \n\n" COLOR_RESET);
		printf(MAGENTA " New Game  (Please Enter 1) :  \n\n" COLOR_RESET);
		printf(MAGENTA " Load Game  (Please Enter 2) :  \n\n" COLOR_RESET);
		printf(MAGENTA " Top Ten Players  (Please Enter 3) :  \n\n" COLOR_RESET);
		printf(MAGENTA " Exit The Game  (Please Enter 4) : \n\n\n\n" COLOR_RESET);
		printf(RED "please enter a valid number\n" COLOR_RESET);
		gets(choice);
		choice_length = strlen(choice);
	}

	int s;
	if (choice[0] > 48 && choice[0] < 53)
	{
		s = choice[0] - 48;
	}
	else
	{
		while (choice[0] <= 48 || choice[0] >= 53)
		{
			system("cls");
			printf(CYAN "\t\t\t\t\t\t Welcome To Our Game \n" COLOR_RESET);
			printf(YELLOW "\t\t\t\t\t\t   Dots And Boxes\n\n\n" COLOR_RESET);
			printf(CYAN "\t\t\t\t\t\t     Main Menu \n\n" COLOR_RESET);
			printf(MAGENTA " New Game  (Please Enter 1) :  \n\n" COLOR_RESET);
			printf(MAGENTA " Load Game  (Please Enter 2) :  \n\n" COLOR_RESET);
			printf(MAGENTA " Top Ten Players  (Please Enter 3) :  \n\n" COLOR_RESET);
			printf(MAGENTA " Exit The Game  (Please Enter 4) : \n\n\n\n" COLOR_RESET);
			printf(RED "please enter a valid number\n" COLOR_RESET);
			gets(choice);
			choice_length = strlen(choice);
			while (choice_length > 1)
			{
				system("cls");
				printf(CYAN "\t\t\t\t\t\t Welcome To Our Game \n" COLOR_RESET);
				printf(YELLOW "\t\t\t\t\t\t   Dots And Boxes\n\n\n" COLOR_RESET);
				printf(CYAN "\t\t\t\t\t\t     Main Menu \n\n" COLOR_RESET);
				printf(MAGENTA " New Game  (Please Enter 1) :  \n\n" COLOR_RESET);
				printf(MAGENTA " Load Game  (Please Enter 2) :  \n\n" COLOR_RESET);
				printf(MAGENTA " Top Ten Players  (Please Enter 3) :  \n\n" COLOR_RESET);
				printf(MAGENTA " Exit The Game  (Please Enter 4) : \n\n\n\n" COLOR_RESET);
				printf(RED "please enter a valid number\n" COLOR_RESET);
				gets(choice);
				choice_length = strlen(choice);
			}
		}

		s = choice[0] - 48;
	}

	return s;
}



#endif // MAIN_MENU_H_INCLUDED
