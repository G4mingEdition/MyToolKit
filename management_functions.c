#include "mytoolkit.h"

void mtk_sign_up(char pseudo[], int size_pseudo, char password[], int size_password, int isHidden, int check, int x, int y, int color, int text_color)
{
    textattr(color*16+text_color);
    MYclrwin(x, y, x+size_pseudo-2, y);
    MYclrwin(x, y+2, x+size_pseudo-2, y+2);
    if(check == 1) MYclrwin(x, y+4, x+size_pseudo-2, y+4);
    mtk_pseudo_creation(pseudo, size_pseudo, x, y, color, text_color);
    mtk_password_creation(password, size_password, isHidden, check, x, y+2, color, text_color);
}

void mtk_pseudo_creation(char pseudo[], int size_pseudo, int x, int y, int color, int text_color)
{
    /** VARIABLES **/
    int i, size_color;

    size_pseudo--;
    size_color = size_pseudo-1;
    if(size_pseudo>=1 && x>=1 && y>=1)
    {
        textbackground(color); textcolor(text_color);
        MYclrwin(x, y, x+size_color, y);
        gotoxy(x, y);
        for (i=0; pseudo[i-1]!=13; i++) // pseudo entry
        {
            while(kbhit())
                getch();
            if(i<=size_pseudo-1)
            {
                pseudo[i] = getche();
                if(pseudo[i] == 8 && i>1) // deleting a character
                {
                    i-=1;
                    MYclrwin(x+i, y, x+size_color, y);
                    i-=1;
                }
                else if(pseudo[i] == 8 && i == 1) // deleting a character
                {
                    i-=1;
                    MYclrwin(x+i, y, x+size_color, y);
                    i-=1;
                }
                else if(pseudo[i] == 8 && i <= 0) // deleting a character
                {
                    MYclrwin(x+i, y, x+size_color, y);
                    i-=1;
                }
            }
            else
            {
                pseudo[size_pseudo]=getch();
                if(pseudo[size_pseudo] == 8) // deleting a character
                {
                    i-=1;
                    MYclrwin(x+i, y, x+size_color, y);
                    i-=1;
                }
                else if(pseudo[size_pseudo] != 13)
                    i = i-1;
            }

        }
        pseudo[i-1]='\0';
    }
    else if(x<1)
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Error: x<1");
    }
    else if(y<1)
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Error: y<1");
    }
    else if(size_pseudo<1)
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Error: size_pseudo<1");
    }
    else
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Error");
    }

    gotoxy(1, 1); textattr(BLACK*16+LIGHTGRAY);
}

void mtk_password_creation(char password[], int size_password, int isHidden, int check, int x, int y, int color, int text_color)
{
    /** VARIABLES **/
    int i, isValid, size_color;
    char password_confirmation_1[size_password];
    char password_confirmation_2[size_password];

    size_password--;
    size_color = size_password-1;
    if(size_password>=1 && (isHidden==0 || isHidden==1) && (check==0 || check==1) && x>=1 && y>=1)
    {
        do
        {
            textbackground(color); textcolor(text_color);
            MYclrwin(x, y, x+size_color, y);
            if (check == 1) MYclrwin(x, y+2, x+size_color, y+2);
            gotoxy(x, y); while(kbhit()) getch();
            for (i=0; password_confirmation_1[i-1]!=13; i++) // first password entry
            {
                if(i<=size_password-1)
                {
                    if(isHidden == 1)
                    {
                        password_confirmation_1[i] = getch();
                        if(password_confirmation_1[i] != 8 && password_confirmation_1[i] != 13) printf("*");
                    }
                    else password_confirmation_1[i] = getche();
                    if(password_confirmation_1[i] == 8 && i>1) // deleting a character
                    {
                        i-=1;
                        MYclrwin(x+i, y, x+size_color, y);
                        i-=1;
                    }
                    else if(password_confirmation_1[i] == 8 && i == 1) // deleting a character
                    {
                        i-=1;
                        MYclrwin(x+i, y, x+size_color, y);
                        i-=1;
                    }
                    else if(password_confirmation_1[i] == 8 && i <= 0) // deleting a character
                    {
                        MYclrwin(x+i, y, x+size_color, y);
                        i-=1;
                    }
                }
                else
                {
                    password_confirmation_1[size_password]=getch();
                    if(password_confirmation_1[size_password] == 8) // deleting a character
                    {
                        i-=1;
                        MYclrwin(x+i, y, x+size_color, y);
                        i-=1;
                    }
                    else if(password_confirmation_1[size_password] != 13)
                        i = i-1;
                }
            }
            password_confirmation_1[i-1]='\0';

            if(check == 1)
            {
                gotoxy(x, y+2);
                for (i=0; password_confirmation_2[i-1]!=13; i++) // second password entry
                {
                    if(i<=size_password-1)
                    {
                        if(isHidden == 1)
                        {
                            password_confirmation_2[i] = getch();
                            if(password_confirmation_1[i] != 8 && password_confirmation_2[i] != 13) printf("*");
                        }
                        else password_confirmation_2[i] = getche();
                        if(password_confirmation_2[i] == 8 && i>1) // deleting a character
                        {
                            i-=1;
                            MYclrwin(x+i, y+2, x+size_color, y+2);
                            i-=1;
                        }
                        else if(password_confirmation_2[i] == 8 && i == 1) // deleting a character
                        {
                            i-=1;
                            MYclrwin(x+i, y+2, x+size_color, y+2);
                            i-=1;
                        }
                        else if(password_confirmation_2[i] == 8 && i <= 0) // deleting a character
                        {
                            MYclrwin(x+i, y+2, x+size_color, y+2);
                            i-=1;
                        }
                    }
                    else
                    {
                        password_confirmation_2[size_password]=getch();
                        if(password_confirmation_2[size_password] == 8) // deleting a character
                        {
                            i-=1;
                            MYclrwin(x+i, y+2, x+size_color, y);
                            i-=1;
                        }
                        else if(password_confirmation_2[size_password] != 13)
                            i = i-1;
                    }
                }
                password_confirmation_2[i-1]='\0';
                isValid = strcmp(password_confirmation_1, password_confirmation_2);
            }
        }while(isValid != 0 && check == 1);

        strcpy(password,password_confirmation_1); // copying password
    }
    else if(x<1)
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Error: x<1");
    }
    else if(y<1)
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Error: y<1");
    }
    else if(size_password<1)
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Error: size_password<1");
    }
    else if(isHidden==0 || isHidden==1)
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Error: isHidden!=0 or isHidden!=1");
    }
    else if(check==0 || check==1)
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Error: check!=0 or check!=1");
    }
    else
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Error");
    }

    gotoxy(1, 1); textattr(BLACK*16+LIGHTGRAY);
}
