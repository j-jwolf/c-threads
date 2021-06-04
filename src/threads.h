#ifndef THREADS_H
#define THREADS_H

#include <thread>
using namespace std;

// global variables
int gl_activeThreads = 0; // count of active threads not joined
int gl_threadLimit = thread::hardware_concurrency(); // threads machine can potentially handle. be aware your machine may or may not be able to handle this amount
int gl_coreCount = gl_threadLimit/2; // number of physical cores on machine

// structures
struct Thread // If modifying this code, be aware that adding any methods to this structure will make this program no longer C compatible
{
	thread* _thread; // pointer to thread object
	int _id; // thread id
};
// functions
template<typename FUNC, typename ... ARGS> Thread makeThread(FUNC&& func, ARGS&&... args) // templated constructor for a thread structure
{
	/*
	* this constructor is perfect-forwarded
	*
	* this allows for C compatiblility since there are no template arguments
	*/
	Thread t;
	t._thread = new thread(forward<FUNC>(func), forward<ARGS>(args)...); // construction of new thread in memory
	t._id = gl_activeThreads++; // sets the thread id to the active thread count and increments the global value
	return t;
}
void join(Thread& t)
{
	/*
	* joins the current thread and deallocates the pointer from memory
	*/
	t._thread->join();
	delete(t._thread);
	gl_activeThreads--; // decrements active thread count
}
int activeThreads() {return gl_activeThreads;} // returns the active thread count
int threadLimit() {return gl_threadLimit;} // returns the theoretical thread limit
int coreCount() {return gl_coreCount;} // returns the core count

#endif /* THREADS_H */
