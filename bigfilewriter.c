//license MIT Ahmad Retha 2016

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ONE_MB 1024*1024

int main(int argc, char * argv[])
{
    if (argc != 3)
    {
        printf("Invalid arguments!\nUsage: bigfilewriter.exe file_name size_in_mb");
        return 1;
    }
    else
    {
        clock_t start, finish;
        start = clock();
        unsigned int c = atoi(argv[2]);
        FILE * pFile;
        pFile = fopen(argv[1], "wb");
        char * a = (char *) calloc(ONE_MB, 1);
        unsigned int i;
        for (i = 0; i < c; i++) {
            fwrite(a, 1, ONE_MB, pFile);
        }
        free(a);
        fclose(pFile);
        finish = clock();
        printf("Finished writing %uMB to %s in %.2fs\n", c, argv[2], (double)(finish-start)/CLOCKS_PER_SEC);
        return 0;
    }
}
