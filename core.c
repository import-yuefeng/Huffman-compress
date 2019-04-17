// @File:compress_core.c
// @Date:2019/04/11
// @Update:2019/04/17
// Author:Cat.1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "declaration.h"
#include "filestruct.h"
#include "haffman.c"
#include "menu.c"
#include "init.c"


// Global var defined start

// Global var defined end

int main(int argc, char *argv[]){
    // file a;
    // welcome_figlet();
    // menu();
    char *optstr = "s:c:u:d:hi";
    int opterr = 0;
    int opt;

    while((opt = getopt(argc, argv, optstr)) != -1){
        switch(opt){
            case 'v':
                // print hfc version
                printf("hfc version 0.0.1 beta\n");
                return 0;
            case 'c':
                // TODO add compress func
                printf("compress path: %s\n", optarg);
                break;
            case 'u':
                // TODO add uncompress func
                printf("uncompress path: %s\n", optarg);
                break;
            case 'd':
                // TODO add diff func
                printf("diff check(path): %s\n", optarg);
                break;
            case 'i':
                // process init argument
                init();
                break;
            case 'h':
                // print help information
                printf("Print help information...: %s\n", optarg);
                break;
            case '?':
                // argument error
                if(strchr(optstr, optopt) == NULL){
                    fprintf(stderr, "unknown option '-%c'\n", optopt);
                }else{
                    fprintf(stderr, "argument need value '-%c'\n", optopt);
                }
                return 1;
            }
    }
}
