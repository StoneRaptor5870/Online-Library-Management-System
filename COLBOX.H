#include<iostream.h>
#include <conio.h>
#include <dos.h>
void colorbox(int R1,int C1,int R2,int C2)
{
for(int i=R1;i<=R2;i++)
{
textcolor(i);
gotoxy(i,C1);cprintf("%c",219); //to print VERTICAL LINE
gotoxy(i,C2);cprintf("%c",219);
}
for(int j=C1;j<=C2;j++)
{
textcolor(j);
gotoxy(R1,j);cprintf("%c",219); //to print HORIZONTAL LINE
gotoxy(R2,j);cprintf("%c",219);
}     textcolor(LIGHTGRAY) ;
}