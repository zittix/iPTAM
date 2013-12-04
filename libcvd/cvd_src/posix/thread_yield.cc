#include <cvd/thread.h>
#include <pthread.h>
#include <sched.h>

namespace CVD{
	void Thread::yield()
	{
        sched_yield();
	}
}
