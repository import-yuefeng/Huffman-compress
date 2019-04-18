// @File:core.c
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

    char *optstr = "s:c:u:d:hv";
    int opterr = 0;
    int opt;
    init();

    while((opt = getopt(argc, argv, optstr)) != -1){
        switch(opt){
            case 'v':
                welcome_figlet();
                printf("\033[32;40m[+] HFM version 0.0.1 beta\033[0m\n");
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
            case 'h':
                // print help information
                printf("Print help information...: %s\n", optarg);
                break;
            case '?':
                // argument error
                if(strchr(optstr, optopt) == NULL){
                    fprintf(stderr, "\033[31;40m[-] unknown option '-%c'\033[0m\n", optopt);
                }else{
                    fprintf(stderr, "\033[31;40m[-] argument need value '-%c'\033[0m\n", optopt);
                }
                return 1;
            }
    }
}
