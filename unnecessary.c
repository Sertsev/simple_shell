#include "simishell.h"

/**
 * farewell - a function saying goodbye
 * 
 * Return: void
 */
 
void farewell()
{
    printstar();
    printstr(" :( Quiting ... ");
    printstar();
}

/**
 * description -  a function to discription about the program
 * 
 * Return: void
 */
 
void description()
{
        printstar();
        printstar();
        printstr("~- H.E.L.L.O _ W.A.R.M _ W.E.L.C.O.M.E -~");
        printstr("");
        printstr("This is a simple bash shell project.");
        printstr("Designed by sertse for ALX SE ");
        printstr("https://github.com/sertsev");
        printstar();
        printstar();
}


/**
 * printstar - prints a star line
 * 
 * Return: void
 */ 
 
void printstar()
{
  int i = 0;
  printf ("\n\t\t\t");

  while (i < 75)
    {
      printf ("*");
      i++;
    }
}

/**
 * printstr - a function to print a given string between a stars
 * @s: a string location pointer
 * 
 * Return: void
 */ 

void printstr(char *s)
{
  int len = strleng(s), spc, m = 0;

  printf ("\n\t\t\t***\t");

  spc = (60 - len) / 2;

  while (m < spc)
    {
      printf (" ");
      m++;
    }

  printf ("%s", s);

  while (m > 0)
    {
      printf (" ");
      m--;
    }

  printf ("\t***");
}
