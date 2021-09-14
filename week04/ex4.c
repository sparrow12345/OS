#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char a[101];
	char *p[40];
	while(1)
	{
		fgets(a,100,stdin);
		char *tok= strtok(a," ");
		int i=0;
		while(tok != NULL)
		{
			p[i] = tok;
			tok = strtok(NULL," ");
			i++;
		}
		p[i]=NULL;
		if(i>0)
		{	
			p[i-1][strlen(p[i-1])-1] = '\0';
		}
		pid_t x = fork();
		if( x == 0 ){
				execvp(p[0],p);
		}
		
	}
	return 0;
}
