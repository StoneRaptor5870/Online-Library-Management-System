#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
void copy(char s[200],char d[200])
{
    fflush(stdout);
    char x[]="copy ";
    strcat(x,s);
    strcat(x," ");
    strcat(x,d);
    system(x);
    system("pause");
}
void md(char *m)
{
    char x[]="md ";
    strcat(x,m);
    system(x);
    getch();
}
