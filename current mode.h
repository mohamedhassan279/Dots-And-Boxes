#ifndef CURRENT_MODE_H_INCLUDED
#define CURRENT_MODE_H_INCLUDED

int single_or_double_mode()
{
    int mode;

    printf(YELLOW "please enter single or double mode\nfor single mode enter 1\nfor double mode enter 2\n" COLOR_RESET);

    char check[MAX];
    gets(check);
    int check_length = strlen(check);

    while (check_length > 1)
    {
        system("cls");
        printf(YELLOW "please enter single or double mode\nfor single mode enter 1\nfor double mode enter 2\n" COLOR_RESET);
        printf(RED "please enter a valid number\n" COLOR_RESET);
        gets(check);
        check_length = strlen(check);
    }

    if (check[0] == 49 || check[0] == 50)
    {
        mode = check[0] - 48;
    }
    else
    {
        while (check[0] != 49 && check[0] != 50)
        {
            system("cls");
            printf(YELLOW "please enter single or double mode\nfor single mode enter 1\nfor double mode enter 2\n" COLOR_RESET);
            printf(RED "please enter a valid number\n" COLOR_RESET);
            gets(check);
            check_length = strlen(check);

            while (check_length > 1)
            {
                system("cls");
                printf(YELLOW "please enter single or double mode\nfor single mode enter 1\nfor double mode enter 2\n" COLOR_RESET);
                printf(RED "please enter a valid number\n" COLOR_RESET);
                gets(check);
                check_length = strlen(check);
            }
        }

        mode = check[0] - 48;
    }

    return mode;

}

#endif // CURRENT_MODE_H_INCLUDED
