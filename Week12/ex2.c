#include <linux/input.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(){
    int I = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    while(1){
        struct input_event ie;
        if (read(I, (void*) &ie, sizeof(struct input_event)) < sizeof(struct input_event))
            continue;
        if(ie.type == 1)
            printf("PRESSED %x (%d)\n",ie.code,ie.code);
        if(ie.type == 0)
            printf("RELEASED %x (%d)\n",ie.code,ie.code);

    }
    return 0;
}/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>

int main(int ac, char **av)
{
    int fd, col;
    struct input_event ev;

    fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    while (read(fd, (void *) &ev, sizeof(ev))) {
            if (ev.type == EV_KEY && ev.value == 1)
                printf("type: %x code: %x  value: %2x\n",
                    ev.type, ev.code, ev.value);
    }
    printf("\n");
    close(fd);
    return(EXIT_SUCCESS);
}   */
