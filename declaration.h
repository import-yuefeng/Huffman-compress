// @File:declaration.h
// @Date:2019/04/11
// @Update:2019/04/17
// Author:Cat.1

#define SUCCESS_MKDIR 0
#define FAILED_MKDIR -1


#ifdef __APPLE__
        #include <sys/uio.h>
        #define CONFIGURE_FILE_PATH "/usr/etc/hfm/default.conf"
        #define CONFIGURE_PATH "/usr/etc/hfm/"
#elif OS_Linux
        #include <sys/io.h>
        #define CONFIGURE_FILE_PATH "/etc/hfm/default.conf"
        #define CONFIGURE_PATH "/etc/hfm/"
#elif OS_Win
        #include <io.h>
        #define CONFIGURE_FILE_PATH "c://etc/hfm/default.conf"
        #define CONFIGURE_PATH "c://etc/hfm/"
#endif

// declare func start

void welcome_figlet();
void menu();
void init();

// declare func end