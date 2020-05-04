#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINELENGTH 80
#define LINESPERPAGE 10

void printP(FILE *ifp, FILE *ofp)
{
    int C;
    int L=0; //line
    int Pg=1; //page
    while ((C = getc(ifp)) != EOF)
    {
        putc(C, ofp);
        if (C == '\n') {
            L = L + 1;
            if (L == LINESPERPAGE)
            {
                fprintf(stdout, "\n\t\t\tPage %d End.\n\n", Pg);
                Pg = Pg + 1;
                L = 0;
            }
        }
    }
}


int main(int argc, char *argv[]) {
    FILE *fpgr;  //file
    char *prog = argv[0];
    int Lcount = 0; //line count
        while (--argc > 0)
            if ((fpgr = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n",
                        prog, *argv);
                exit(1);
            }
            else {
                fprintf(stdout,"\n\n\nFile: %s\n\n", *argv);
                printP(fpgr, stdout);
                fclose(fpgr);
            }

    return 0;
  }
