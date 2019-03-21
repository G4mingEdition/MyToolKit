#include "mytoolkit.h"

unsigned int mtk_get_file_size(const char *const file_name) // constant content & constant pointer
{
    /** VARIABLES **/
    unsigned int file_size;
    FILE *ffile=NULL;

    ffile = fopen(file_name,"rb");
        if(ffile != NULL)
        {
            fseek(ffile, 0, SEEK_END);
            file_size = ftell(ffile);
        }
        else if(ffile != NULL)
        {
            gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYTOOLKIT] Error: %s doesn't exist", file_name);
        }
        else
        {
            gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYTOOLKIT] Error");
        }
    fclose(ffile);

    return (file_size);
}

unsigned int mtk_get_records_amout(const char *const file_name, int record_lenght)
{
    /** VARIABLES **/
    unsigned int records_amout;
    FILE *ffile=NULL;

    ffile = fopen(file_name,"rb");
        if(ffile != NULL && record_lenght>=1)
        {
            fseek(ffile, 0, SEEK_END);
            records_amout=ftell(ffile)/record_lenght;
        }
        else if(ffile == NULL)
        {
            gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYTOOLKIT] Error: %s doesn't exist", file_name);
        }
        else if(record_lenght>=1)
        {
            gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYTOOLKIT] Error: record_lenght<1");
        }
        else
        {
            gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYTOOLKIT] Error");
        }
    fclose(ffile);

    gotoxy(1, 1); textattr(BLACK*16+LIGHTGRAY);
    return (records_amout);
}

void mtk_file_to_table(const char *const file_name, void *pointer, int record_lenght, int records_amount, int all, int record_position)
{
    /** VARIABLES **/
    int file_size = record_lenght*records_amount;
    FILE *ffile = NULL;

    if(all == 0 && record_lenght>=1 && pointer != NULL && record_position>=1) pointer+=(record_lenght*(record_position-1));

    ffile = fopen(file_name,"rb");
        if(all == 1 && ffile != NULL && pointer != NULL && record_lenght>=1 && records_amount>=1) fread(pointer,file_size,1,ffile);
        else if (all == 0 && ffile != NULL && pointer != NULL && record_lenght>=1 && record_position>=1)
        {
            fseek(ffile,record_lenght*(record_position-1),SEEK_SET);
            fread(pointer,record_lenght,1,ffile);
        }
        else if(all != 0 && all !=1)
        {
            gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYTOOLKIT] Error: all!=0 or all!=1");
        }
        else if(ffile == NULL)
        {
            gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYTOOLKIT] Error: %s doesn't exist", file_name);
        }
        else if(pointer == NULL)
        {
            gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYTOOLKIT] Error: pointer is NULL");
        }
        else if(record_lenght<1)
        {
            gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYTOOLKIT] Error: record_lenght<1");
        }
        else if(records_amount<1)
        {
            gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYTOOLKIT] Error: records_amount<1");
        }
        else if(record_position<1)
        {
            gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYTOOLKIT] Error: record_position<1");
        }
        else
        {
            gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYTOOLKIT] Error");
        }
    fclose(ffile);

    gotoxy(1, 1); textattr(BLACK*16+LIGHTGRAY);
}
