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

    char *optstr = "s:c:u:d:hv";
    int opterr = 0;
    int opt;
    // init();
	printf("\033[32;40m[+] Welcome use HFM Compress Program! ... \033[0m\n");

    while((opt = getopt(argc, argv, optstr)) != -1){
        switch(opt){
            case 'v':
                welcome_figlet();
                printf("\033[32;40m[+] HFM version 0.0.1 beta\033[0m\n");
                return 0;
            case 'c':
                // TODO add compress func
                printf("compress path: %s\n", optarg);
				char rename[80];
				Compress(optarg, rename);
				printf("Press Enter to continue...");
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


// int main(int argc, char *argv[])
// {
// 	char choice, blank[] = "              ";
// 	//      writeFile();
// 	system("color 8a");
// 	while (1) {
// 		system("clear");	//清屏
// 		puts("          * * * *Welcome use huffman encoder\\decoder* * *");
// 		puts("          **********************^_^***********************");
// 		puts("          *                                              *");
// 		printf("          * %s 1 ]. Compress   %s*\n", blank, blank);
// 		puts("          *                                              *");
// 		printf("          * %s 2 ]. Uncompress%s *\n", blank, blank);
// 		puts("          *                                              *");
// 		printf("          * %s 3 ]. Exit  ^_^ %s *\n", blank, blank);
// 		puts("          *                                              *");
// 		puts("          ************************************************");
// 		printf
// 		    ("          (Apply to text file) Copyright 2011 By Bocai\n");
// 		printf("          Choose (1 to 3):");
// 		choice = getchar();

// 		puts("");
// 		getchar();
// 		fflush(stdin);	//清空输入缓冲区域，否则键入的回车符将作为程序结尾处的scanf输入，此函数在stdio.h中
// 		switch (choice) {
// 		case '1':
// 			Compress();
// 			printf("Press Enter to continue...");
// 			getchar();
// 			break;
// 		}
// 	}
// 	return 0;
// }
