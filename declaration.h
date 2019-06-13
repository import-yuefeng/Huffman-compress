// @File:declaration.h
// @Date:2019/04/11
// @Update:2019/04/17
// @Update:2019/05/14
// @Update:2019/06/02
// @Update:2019/06/09
// Author:Cat.1

#define SUCCESS_MKDIR 0
#define FAILED_MKDIR -1
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#define  N 256
#define Maxsize 80
#define  SOME 1
#define Empty 0
#define FULL -1


#ifdef __APPLE__
    #include <sys/uio.h>
    #define CONFIGURE_FILE_PATH "./hfm.conf/default.conf"
    #define CONFIGURE_PATH "./hfm.conf/"
#elif OS_Linux
    #include <sys/io.h>
    #define CONFIGURE_FILE_PATH "/etc/hfm.conf/default.conf"
    #define CONFIGURE_PATH "/etc/hfm.conf/"
#elif OS_Win
    #include <io.h>
    #define CONFIGURE_FILE_PATH "c://etc/hfm/default.conf"
    #define CONFIGURE_PATH "c://etc/hfm/"
#endif

typedef unsigned long int WeightType;
typedef unsigned char MyType;
typedef struct
{
    MyType ch;
	WeightType weight;
	int parent, LChild, RChild;
} HTNode;

typedef struct
{
	int tag;
	int front;
	int rear;
	MyType length;
	char elem[Maxsize];
} SeqQueue;


typedef struct{
	FILE *dst, *srt;
    char filename[100];
    char filepath[100];

} hfmFile;


/* declare func start */

// -------------------func declare start-----------------
void welcome_figlet();
void menu();
void init();
// -------------------main func declare start------------
int InitQueue(SeqQueue * Q);
int InputQueue(SeqQueue * Q, char x);
int OutputQueue(SeqQueue * Q, char *x);
int SizeQueue(SeqQueue * Q);
// -------------------queue func declare end-------------
HTNode *CreatHFM(FILE * fp, short *n, WeightType * FileLength);
char **CrtHuffmanCode(HTNode * ht, short LeafNum);
int SortTree(HTNode * ht);
void SelectMinTree(HTNode * ht, int n, int *k);
// -------------------huffman func declare end-----------
void Compress();
// -------------------compress func declare end----------
MyType GetBits(SeqQueue * Q);
void MaxMinLength(FILE * File, HTNode * ht, char **hc, short NLeaf, MyType * Max, MyType * Min);
short CodeToFile(FILE * fp, char **hc, short n, SeqQueue * Q, MyType * length);
// -------------------DEcode func declare end------------


/* declare func end */