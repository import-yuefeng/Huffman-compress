// @File:init.c
// @Date:2019/04/16
// @Update:2019/04/17
// Author:Cat.1

#include <stdio.h>

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
    if(access(CONFIGURE_FILE_PATH, 0) == 0 ){
        printf("HFC find configure file!\n");
        printf("So you didn't need to init!\n");
        exit(0);
    }else{
        printf("INIT HFC Program...");

        welcome_figlet();

        if(access(CONFIGURE_PATH, 0) == 0){

        }
        else{
            if(mkdir(CONFIGURE_PATH, S_IRWXU) == FAILED_MKDIR){
                // TODO Fix mkdir bug.
                printf("Init failed... mkdir %s error.\n", CONFIGURE_PATH);
            }
            else{
                // TODO add create configure file.
                printf("Init Success.");
            }
        }
    }
}