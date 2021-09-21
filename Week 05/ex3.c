#include<stdio.h>
#include<pthread.h>

#define M 30

char s[M];

int position;

int bConSleep, bProSleep;
long long int k;

void* Consume(void *y)
{
	while(1)
	{
		if(bConSleep)
			continue;

		if(position == 0)
		{
			bConSleep = 1;
			bProSleep = 0;
			continue;
		}
		printf("%c", s[position]);
		position--;
	}
	pthread_exit(NULL);
	return NULL;
}
void* Produce(void *y)
{
	while(1)
	{
		if(bProSleep)
			continue;
		
		if(position == 20)
		{
			bConSleep = 0;
			bProSleep = 1;
			printf("Done production with time %lld", k++);
			continue;
		}
		s[position] = 'a' + position;
		position++;
	}

	pthread_exit(NULL);
	return NULL;
}

int main()
{
	//Consumer sleeps at first
	bConSleep = 1;

	pthread_t tProducer, tConsumer;

	pthread_create(&tProducer, NULL, Produce, NULL);
	pthread_create(&tConsumer, NULL, Consume, NULL);

	while(1);
//it stopped at time 96593
	return 0;
}
