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
        pFile = fopen(argv[1], "w");
		if (!pFile) {
			fprintf(stderr, "Error. Failed to open file for writing!\n");
			return 1;
		}
        char * a = (char *) malloc(ONE_MB + 1);
        unsigned int i;
		for (i = 0; i < ONE_MB; i++) {
			a[i] = '1';
		}
		a[ONE_MB] = '\0';
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
