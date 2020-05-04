#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void comparefiles( char *L1, char *L2)
{
  if(strcmp (L1, L2) < 0 || strcmp (L1, L2) > 0)
    printf( "%s\n%s\n", L1, L2);
}

int main(int argc, char *argv[] )
{
  FILE *f1, *f2;    //file1, file2
  char f1L[MAXLINE], f2L[MAXLINE]; //File1Line , File2Line
  int i;
  f1 = fopen( argv[1], "r" );
  f2 = fopen( argv[2], "r" );
  while ( (fgets(f1L, MAXLINE, f1) != NULL)&& (fgets(f2L, MAXLINE, f2) != NULL))
  {
    comparefiles( f1L, f2L);
  }
  return 0;
}
