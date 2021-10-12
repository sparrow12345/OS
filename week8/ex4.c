#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/resource.h>
#include<unistd.h>

int main()
{
    const size_t Memory =  10485760;
    int k = 10;

    for(int i = 0;i < k;i++)
    {
        void* p = malloc(Memory);
        memset(p, 0, sizeof(p));
        struct rusage rusage;
        getrusage(RUSAGE_SELF, &rusage);

        printf("%ld\n",rusage.ru_maxrss);

        sleep(1);
    }

    return 0;
}