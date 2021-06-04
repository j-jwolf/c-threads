#ifndef THREADS_H
#define THREADS_H

#include <thread>
using namespace std;

int gl_activeThreads = 0;
int gl_threadLimit = thread::hardware_concurrency();
int gl_coreCount = gl_threadLimit/2;

struct Thread
{
	thread* _thread;
	int _id;
};
template<typename FUNC, typename ... ARGS> Thread makeThread(FUNC&& func, ARGS&&... args)
{
	Thread t;
	t._thread = new thread(forward<FUNC>(func), forward<ARGS>(args)...);
	t._id = gl_activeThreads++;
	return t;
}
void join(Thread& t)
{
	t._thread->join();
	delete(t._thread);
	gl_activeThreads--;
}
int activeThreads() {return gl_activeThreads;}
int threadLimit() {return gl_threadLimit;}
int coreCount() {return gl_coreCount;}

#endif /* THREADS_H */
