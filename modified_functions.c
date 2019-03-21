#include "mytoolkit.h"

int mtk_myfgets(char *chain, int ln)
{
    char *pos=NULL;
    int retour;

    fflush(stdin);

    if (fgets(chain,ln,stdin)!=NULL)
    {
        if((pos=strchr(chain,'\n'))!=NULL) *pos='\0';
        retour=1;
    }
    else  retour=0;

    fflush(stdin);

    return(retour);
}

void mtk_empty_ke()
{
    while(kbhit()) getch();
}
