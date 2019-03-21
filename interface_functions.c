#include "mytoolkit.h"

void mtk_animated_text(char *text, int speed, int x, int y, int limit, int color, int text_color)
{
    /** VARIABLES **/
    int i, newline, lenght;

    lenght = strlen(text);
    if(x>=1 && y>=1 && lenght>=1 && speed>=1 && x<=limit)
    {
        gotoxy(x, y); textattr(color*16+text_color);
        newline=0;
        for(i=0; i<lenght; i++)
        {
            Sleep(300/speed);
            printf("%c", text[i]);
            if((newline+x)==(limit))
            {
                gotoxy(x, ++y);
                newline=-1;
            }
            newline++;
        }
    }
    else if(x<1)
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYTOOLKIT] Error: x<1");
    }
    else if(y<1)
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYTOOLKIT] Error: y<1");
    }
    else if(lenght<1)
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYTOOLKIT] Error: lenght<1");
    }
    else if(speed<1)
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYTOOLKIT] Error: speed<1");
    }
    else if(x>limit)
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYTOOLKIT] Error: x<limit");
    }
    else
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYTOOLKIT] Error");
    }

    gotoxy(1, 1); textattr(BLACK*16+LIGHTGRAY);
}
