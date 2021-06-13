#include <stdio.h>
#include <time.h>

#include "threads.h"

void test(const int& val)
{
	double start = time(0), end;
	do
	{
		end = time(0);
	} while(difftime(end, start) < 4.0);
	printf("val: %d\n", val);
	fflush(stdout);
}
int main()
{
	int testVal = 300;
	struct Thread t = makeThread(test, testVal);
	double start = time(0), end;
	do
	{
		end = time(0);
	} while(difftime(end, start) < 2.0);
	printf("Main finished\nActive threads: %d\n", activeThreads());
	fflush(stdout);
	//join(t);
	printf("Thread joined\nActive threads: %d\n", activeThreads());
	fflush(stdout);
	return 0;
}

