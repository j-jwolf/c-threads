# Thread Header File -- Version 0.0.1 by John Wolf
Header file for using threads. Compatible with both C and C++. This program is only compatible if your program is compiled with g++. This will not work with gcc

# Please view the LICENSE.txt file before use

# Contents
1. Usage
2. Troubleshooting
3. Bug Reporting
***
# 1. Usage
## Using the header file in your project:
To use the header file, download the header file and either copy it directly into your project folder or include it via path to the file
### Directly in the source code folder:
``` c
#include "threads.h"
```
### Path to file:
``` c
#include "path/from/src/directory/threads.h"
```
## Creating a Thread:
To create a thread in C:
``` c
struct Thread threadName = makeThread(functionName, arguments...);
```
To create a thread in C++:
``` cpp
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
	* This program will automatically join any threads that are left unjoined after the program ends
		+ This may cause issues with the code still if there is any code that is dependent on the threads
2. Make sure that your machine can handle multithreading
	* Remember that the thread limit is only a guideline, your machine may not be able to handle multithreading
	* More information on threads can be found <a href="https://cplusplus.com/reference/thread/thread">here<a/>
# 3. Bug Reporting
To report a bug, please email jjwolf0330@tutanota.com and try to include the following:
1. The bug in question
2. Steps to recreate the bug
	* If you cannot find the exact steps, try to include details of how the bug was encountered
3. The operating system the bug was encountered on
4. Optionally, the compiler you compiled your program with
	* This program was tested on Windows 10 with the MinGW-64 compiler in both GitBash and PowerShell
***
