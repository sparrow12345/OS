#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

//the pages swap out while the program is running

int main()
{
    const size_t Memory =  10485760;
    int k = 10;

    for(int i = 0;i < k;i++)
    {
        void* p = malloc(Memory);
        memset(p, 0, sizeof(p));

        sleep(1);
    }

    return 0;
}