#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "sort.hpp"

#define MIN(a,b)                 \
        ({                       \
        __typeof__(a) c = a;     \
        __typeof__(b) d = b;     \
        c < d ? c : d;           \
        }) 


void puzirikSortir(void *data, size_t size, size_t elemSize, CompareFunc_t *CompareFunc, SwapFunc_t *swap)
    {
    for (size_t i = 0; i < size; i++)
        {
        for (size_t j = 0; j < size - i; j++)
            {
            if (CompareFunc((data + j * elemSize), (data + (j + 1) * elemSize)) > 0)
                {
                printf("%c ==== %c\n", **(char**)(data + j * elemSize), **(char**)(data + (j + 1) * elemSize));
                char *vspm = *(char**)(data + j * elemSize);
                *(char**)(data + j * elemSize) = *(char**)(data + (j + 1) * elemSize);
                *(char**)(data + (j + 1) * elemSize) = vspm;
                printf("%c ==== %c\n\n\n", **(char**)(data + j * elemSize), **(char**)(data + (j + 1) * elemSize));
                }
            }
        }        
    }

int intComp(const void *a, const void *b)
    {
    return (*(const int*) a - *(const int*) b);
    }

void intswap(void *data, size_t a, size_t b)
    {
    int c = *((int*) data + a);
    *((int*) data + a) = *((int*) data + b);
    *((int*) data + b) = c;
    }

int strComp(const void *a, const void *b)
    {
    const char *c = (const char*)a;
    const char *d = (const char*)b;
    int ns1 = strlen(c);
    int ns2 = strlen(d);
    int a_i = 0;
    int b_i = 0;
    while (a_i < MIN(ns1, ns2) & b_i < MIN(ns1, ns2))
        if (!isalpha(*(c + a_i)))
            {
            a_i++;
            }
        else if (!isalpha(*(d + b_i)))
            {
            b_i++;
            }
        else if (*(c + a_i) != *(d + b_i))
            {
            if (*(c + a_i) > *(d + b_i))
                return 1;
            else
                return -1;
            }
        else
            {
            a_i++;
            b_i++;
            }
        
    if (ns1 > ns2)
        return 1;
    else if (ns1 < ns2)
        return -1;
    else
        return 0;
    }
/*
void strSwap(void *data, size_t a, size_t b)
    {
    
    }
*/
