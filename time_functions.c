#include "mytoolkit.h"

unsigned int mtk_check_date(int jj, int mm, int aa)
{
    /** VARIABLES **/
    unsigned int check;

    check=0;
    if(mm==2)
    {
        if(aa%4==0 && aa%100!=0)
        {
            if(jj<1 || jj>29)
            {
                gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Error: jj<1 or jj>29");
                check=1;
            }
        }
        else if(aa%400==0)
        {
            if(jj<1 || jj>29)
            {
                gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Error: jj<1 or jj>29");
                check=1;
            }
        }
        else if(jj<1 || jj>28)
        {
            gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Error: jj<1 or jj>28");
            check=1;
        }
    }
    else if(mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)
    {
        if(jj<1 || jj>31)
        {
            gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Error: jj<1 or jj>31");
            check=1;
        }
    }
    else if(mm==4 || mm==6 || mm==9 || mm==11)
    {
        if(jj<1 || jj>30)
        {
            gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Error: jj<1 or jj>30");
            check=1;
        }
    }
    else
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Error: mm<1 or mm>12");
        check=1;
    }

    gotoxy(1, 1); textattr(BLACK*16+LIGHTGRAY);
    return(check);
}
