#include <stdio.h>
#include <stdlib.h>
#include <sys\stat.h>
#include "sort.hpp"

size_t fileLen(const char * file);
int setbuf(char* buf, char** pointers, size_t flen, FILE* fileEO);
void printBuf(char **pointers);

int main()
    {
    char filename[] = "onev.txt";
    FILE *fileEO = fopen("onev.txt", "rb");
    if (fileEO == NULL)
        {
        printf("FILE_ERROR\n");
        return -1;
        }
    size_t flen = fileLen(filename);
    char* buf = (char*) calloc(flen, sizeof(char));
    char** pointers = (char**) calloc(flen, sizeof(char*));
    int cnt = setbuf(buf, pointers, flen, fileEO);
    printf("buf\n");
    puzirikSortir(pointers, cnt, sizeof(char**), strComp, intswap);
    printBuf(pointers);
    fclose(fileEO);
    return 0;
    }


size_t fileLen(const char * file)
    {
    struct stat st;
    if (stat(file, &st) == 0)
        return (size_t) st.st_size;
    return 0;
    }


int setbuf(char *buf, char **pointers, size_t flen, FILE* fileEO)
    {
    int cnt = 0;
    fread(buf, sizeof(char), flen, fileEO);
    int buf_i = 0;
    int poi_j = 0;
    while (buf_i + 2 < flen)
        {
        if (buf[buf_i] == '\r')
            {
            pointers[poi_j] = &(buf[buf_i + 2]);
            buf_i += 2;
            poi_j++;
            cnt++;
            }
        else if (buf[buf_i] == '\n')
            {
            pointers[poi_j] = &(buf[buf_i + 1]);
            buf_i++;
            poi_j++;
            cnt++;
            }
        else
            {
            buf_i++;
            }
        }
    pointers[poi_j] = 0;
    printf("jgkjg\n\n");
    return cnt;
    }  

void printBuf(char **pointers)
    {
    while (*pointers != 0)
        {
        int i = 0;
        while (*(*pointers + i) != '\r')
            {
            putchar(*(*pointers + i));
            i++;
            }
        putchar('\n');
        pointers++;
        }
    }