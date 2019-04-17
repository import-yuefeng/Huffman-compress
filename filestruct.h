// @File:filestruct.h
// @Date:2019/04/11
// Author:Cat.1

#include <stdio.h>

FILE *fopen( const char * filename, const char * mode );

typedef struct{
    FILE *fopen;
    char filename[100];
    char filepath[100];

} file;





