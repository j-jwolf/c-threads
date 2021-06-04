#include <stdio.h>
#include <time.h>

#include "threads.h"

void test(const int& val)
{
	printf("val: %d\n");
	fflush(stdout);
}
int main()
{
	printf("This machine has %d cores and can safely handle %d threads\n", coreCount(), threadLimit());
	fflush(stdout);
	int testVal = 100;
	struct Thread t = makeThread(test, testVal);
	double start = time(0), end = time(0);
	while(difftime(end, start) < 3.0) {end = time(0);}
	printf("Main finished\nActive threads: %d\n", activeThreads());
	fflush(stdout);
	join(t);
	printf("Thread joined\nActive threads: %d\n", activeThreads());
	fflush(stdout);
	return 0;
}

