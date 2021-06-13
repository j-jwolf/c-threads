#ifndef THREADS_H
#define THREADS_H

#include <thread>
#include <memory>
#include <vector>
#include <cstdio>
using namespace std;

// global variables
int gl_activeThreads = 0; // count of active threads not joined
const int gl_threadLimit = thread::hardware_concurrency(); // threads machine can potentially handle. be aware your machine may or may not be able to handle this amount
const int gl_coreCount = gl_threadLimit/2; // number of physical cores on machine

// thread structure for use in c/c++
struct Thread // If modifying this code, be aware that adding any methods to this structure will make this program no longer C compatible
{
	thread* _thread; // pointer to thread object
	int _id; // thread id
};
// deleter for unique thread pointers, tries to join and delete thread. if thread has already been joined, this gets caught as an exception.
// for catching unjoined threads
auto deleter = [](Thread* t)
{
	puts("In Ptr deleter\n");
	fflush(stdout);
	try
	{
		t->_thread->join();
		delete(t->_thread);
		if(gl_activeThreads > 0) {gl_activeThreads--;}
	} catch(const exception& e) {}
};
using Ptr = unique_ptr<Thread, decltype(deleter)>;
// thread handler class for auto 'joining' threads that were unjoined
// this is implemented AFTER the code has finished
class Handler
{
	vector<Ptr> _threads;
public:
	Handler() {}
	~Handler() {}
	void addThread(Thread* t) {_threads.push_back(Ptr(t, deleter));}
	Thread* getLast() {return _threads.back().get();}
};
Handler handler;
// functions
template<typename FUNC, typename ... ARGS> Thread makeThread(FUNC&& func, ARGS&&... args) // templated constructor for a thread structure
{
	/*
	* this constructor is perfect-forwarded
	*
	* this allows for C compatiblility since there are no template arguments
	*/
	handler.addThread(new Thread);
	handler.getLast()->_thread = new thread(forward<FUNC>(func), forward<ARGS>(args)...);
	handler.getLast()->_id = gl_activeThreads++;
	return *handler.getLast();
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
