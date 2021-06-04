# Thread Header File -- Version 0.0.1
Header file for using threads in both C and C++ by John Wolf

# Please view the LICENSE.txt file before use

# Contents
1. Usage
2. Troubleshooting
3. Bug Reporting
***
# 1. Usage
## Creating a Thread:
``` c
struct Thread threadName = makeThread(functionName, arguments...);
```
``` cpp
To create a thread in C++:
Thread threadName = makeThread(functionName, arguments...);
```
## Joining a Thread:
``` c
join(threadName);
```
* Joining a thread will automatically deallocate it from memory
## Checking the number of active threads:
``` c
int activeThreadCount = activeThreads();
```
## Checking the max threads your machine can handle:
``` c
int threadLimit = threadLimit();
```
## Checking number of cores your machine has:
``` c
int numberOfCores = coreCount();
```
* This is niche but included just in case
# 2. Troubleshooting
1. Make sure that every thread is joined back into the program at some point
	* There are plans to make sure that each thread is automatically joined if one is forgotten
2. Make sure that your machine can handle multithreading
	* Remember that the thread limit is only a guideline, your machine may not be able to handle multithreading
	* More information on threads can be found at <a href="https://cplusplus.com/reference/thread/thread<a/>
# 3. Bug Reporting
To report a bug, please email jjwolf0330@tutanota.com and try to include the following:
1. The bug in question
2. Steps to recreate the bug
	* If you cannot find the exact steps, try to include details of how the bug was encountered
3. The operating system the bug was encountered on
4. Optionally, the compiler you compiled your program with
	* This program was tested on Windows 10 with the MinGW-64 compiler
***
