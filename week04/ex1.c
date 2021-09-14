#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    int n = 7;
    pid_t x = fork();
    if(x < 0)
	    return EXIT_FAILURE;
    else if(x == 0)
	    printf("Hello from Child %d, n = %d\n",getpid(),n);
    else
	    printf("Hello from Parent %d, n = %d\n",getpid(),n);
    
    
    return 0;
}
