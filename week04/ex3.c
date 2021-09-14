#include <unistd.h>
#include <stdio.h>


int main()
{
	char s[30];
	while(1){
		scanf("%s",s);
		system(s);
	}


	return 0;
}
