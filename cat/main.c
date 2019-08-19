#include <stdio.h>

void filecopy(FILE *, FILE *);

int main(int argc, char **argv)
{
    FILE *fp;

    if (argc == 1) {
        filecopy(stdin, stdout);
    }
    else
    {
        while(--argc > 0)
        {
            if ((fp = fopen(*++argv, "r")) == NULL)
            {
                printf("fuck! it does not work!\n");
                return 1;
            }
            else
            {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
}

void filecopy(FILE *ifp, FILE* ofp)
{
    int c;
    while((c = getc(ifp)) != EOF)
    {
        putc(c, ofp);
    }
}
