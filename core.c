// @File:compress_core.c
// @Date:2019/04/11
// Author:Cat.1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "filestruct.h"
#include "declaration.h"
#include "haffman.c"


int main(){
    file a;
    welcome_figlet();
    menu();
    return 1;
}


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


void menu(){
    char choice;
    printf("%s\n", "Welcome to haffman compress tools!");

    do{

        printf("%s\n", "1. Compress");
        printf("%s\n", "2. Uncompress");
        printf("%s\n", "3. Compress size diff");
        printf("%s\n", "4. quit");
        printf("%s\n", "Scanf your choice!");
        scanf("%c", &choice);

        switch (choice){

            case '1' :
                system("clear");
                printf("\n%s\n\n", "Your choice is Compress.");
                printf("%s\n", "System run end...");
                printf("%s\n", "------------------------------------");
                break;
            case '2' :
                system("clear");
                printf("\n%s\n\n", "Your choice is Uncompress");
                printf("%s\n\n", "System run end...");
                printf("%s\n", "------------------------------------");
                break;
            case '3' :
                system("clear");
                printf("\n%s\n\n", "Your choice is Compress size diff");
                printf("%s\n\n", "System run end...");
                printf("%s\n", "------------------------------------");
                break;
            case '4' :
                system("clear");
                printf("\n%s\n\n", "Your choice is quit");
                printf("%s\n\n", "System run end...");
                printf("%s\n", "------------------------------------");
                exit(1);
                break;
            default :
                printf("\n%s\n\n", "Ignore!");
                printf("%s\n\n", "Please again enter your choice...");
                printf("%s\n", "------------------------------------");
                break;
       }
    }while(scanf("%c", &choice) != EOF);


}



