// @File:menu.c
// @Date:2019/04/17
// @Update:2019/05/14
// Author:Cat.1

#include <stdio.h>


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

