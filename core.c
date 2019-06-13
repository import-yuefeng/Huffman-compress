// @File:core.c
// @Date:2019/04/11
// @Update:2019/04/17
// @Update:2019/05/14
// @Update:2019/06/02
// @Update:2019/06/09
// Author:Cat.1


#include "declaration.h"
#include "bitDEcode.c"
#include "haffman.c"
#include "Compress.c"
#include "queue.c"
#include "menu.c"
#include "init.c"

// Global var defined start

// Global var defined end

int main(int argc, char *argv[]){

    char *optstr = "i:s:c:u:d:hv";
    int opterr = 0;
    int opt;
	printf("\033[32;40m[+] Welcome use HFM Compress Program! ... \033[0m\n");

    while((opt = getopt(argc, argv, optstr)) != -1){
        switch(opt){
            case 'i':
                init();
                return 0;
            case 'v':
                welcome_figlet();
                printf("\033[32;40m[+] HFM version 0.1.0 beta\033[0m\n");
                return 0;
            case 'c':
                printf("Compress file: %s\n", optarg);
				char rename[80];
				Compress(optarg, rename);
				getchar();
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
	return 1;
}
