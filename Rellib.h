#ifndef __RELLIB_H__
#define __RELLIB_H__

#include <stdio.h>

//For learning purposes, haha :)
//Just to make sure things were working
int r_print(char *text)
{
    printf("%s\n", text);

}

//MSGBOX(title, msgtext) - Function
int r_msgBox(char *titre, char *msgtext)
{ 
     MessageBox(NULL, titre, msgtext, MB_OK); 

}

#endif
