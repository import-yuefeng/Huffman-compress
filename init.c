// @File:init.c
// @Date:2019/04/16
// @Update:2019/04/17
// Author:Cat.1

#include <stdio.h>
#include<errno.h>
#define errno (*__error())


void welcome_figlet(){
    const char HAFFMAN[500] = "\
  _   _        __  __\n \
| | | | __ _ / _|/ _|_ __ ___   __ _ _ __\n \
| |_| |/ _` | |_| |_| '_ ` _ \\ / _` | '_ \\ \n \
|  _  | (_| |  _|  _| | | | | | (_| | | | | \n \
|_| |_|\\__,_|_| |_| |_| |_| |_|\\__,_|_| |_| \n \\ ";
    printf("%s\n", HAFFMAN);
    const char COMPRESS[500] = "\
  ____\n\
 / ___|___  _ __ ___  _ __  _ __ ___  ___ ___\n\
| |   / _ \\| '_ ` _ \\| '_ \\| '__/ _ \\/ __/ __|\n\
| |__| (_) | | | | | | |_) | | |  __/\\__ \\__ \\ \n\
 \\____\\___/|_| |_| |_| .__/|_|  \\___||___/___/\n \
                     |_|\n";
    printf("%s\n", COMPRESS);
}


void init(){
    FILE *file_link;
    welcome_figlet();
    if(access(CONFIGURE_PATH, 0) == 0 ){
        if (access(CONFIGURE_FILE_PATH, 0) == 0){
            printf("\033[31;40m[-] Init failed... %s exist.\033[0m\n", CONFIGURE_FILE_PATH);
            printf("\033[32;40m[+] HFM find configure file!\033[0m\n");
            printf("\033[33;40m[~] So you didn't need to init!\033[0m\n");
        }else{
            file_link = fopen(CONFIGURE_FILE_PATH, "w+");
            fclose(file_link);
            printf("\033[32;40m[+] Init Success.\033[0m\n");
        }
        exit(0);
    }else{
        printf("\033[33;40m[~] INIT HFM Program...\033[0m\n");
        if(mkdir(CONFIGURE_PATH, S_IRWXU) == FAILED_MKDIR){
            printf("\033[31;40m[-] Init failed... mkdir %s error.\033[0m\n", CONFIGURE_PATH);
            printf("\033[31;40m[-] Please check your have Permission to create dir(%s).\033[0m\n", CONFIGURE_PATH);
        }else{
            file_link = fopen(CONFIGURE_FILE_PATH, "w+");
            fclose(file_link);
            printf("\033[32;40m[+] Init Success.\033[0m\n");
        }
    }
}



