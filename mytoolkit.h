#ifndef MYTOOLKIT_H_INCLUDED
#define MYTOOLKIT_H_INCLUDED



/** ========== MY GAMES ========== **/
///                                ///
/// author: Denis Christopher      ///
/// name: mytoolkit                ///
/// kind: librairy                 ///
/// creation: 07-03-2018           ///
///                                ///
/** ============================== **/



/** ========== LIBRAIRIES ========== **/
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conioplus.h>

/** ========== PROTOTYPES ========== **/
    /// files_functions
unsigned int mtk_get_file_size(const char * const file_name);
unsigned int mtk_get_records_amout(const char *const file_name, int record_lenght);
void mtk_file_to_table(const char *const file_name, void *pointer, int record_lenght, int records_amount, int all, int record_position);
    /// interface_functions
void mtk_animated_text(char *text, int speed, int x, int y, int limit, int color, int text_color);;
    /// account_functions
void mtk_sign_up(char pseudo[], int size_pseudo, char password[], int size_password, int isHidden, int check, int x, int y, int color, int text_color);
void mtk_pseudo_creation(char pseudo[], int size_pseudo, int x, int y, int color, int text_color);
void mtk_password_creation(char password[], int size_password, int isHidden, int check, int x, int y, int color, int text_color);
    ///modified_functions
int mtk_myfgets(char *chain, int ln);
void mtk_empty_ke();
    ///time_functions
unsigned int mtk_check_date(int jj, int mm, int aa);
#endif // MYTOOLKIT_H_INCLUDED
