#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

#define THREADS_COUNT 10

void* PrintHello(void* ThreadID)
{
	int s = (int)ThreadID;
	printf("Hello from thread %d\n", s);
	pthread_exit(NULL);
}
int main()
{
	pthread_t threads[THREADS_COUNT];
	int q;
	for (int i = 0; i < THREADS_COUNT; i++)
	{
		printf("creating thread number %d\n", i);
		x = pthread_create(&threads[i], NULL, PrintHello, (void*)i);
		if (q)
		{
			printf("error while creating thread %d", i);
			exit(-1);
		}
	}
	pthread_exit(NULL);
	return 0;
}