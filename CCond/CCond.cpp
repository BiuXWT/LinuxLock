#include"CCond.h"

CCond::CCond()
{
	m_cond=PTHREAD_COND_INITIALIZER;
    m_pmutex=m_mutex.getmutex();

}

CCond::~CCond()
{
	pthread_cond_destroy(&m_cond);
}


int CCond::wait()
{
	return pthread_cond_wait(&m_cond,m_pmutex);
}

int CCond::timedwait(int sec,int nsec=0)
{
	struct timespec stime;
	time_t curtime=time(NULL);
	stime.tv_sec=curtime + sec;
	stime.tv_nsec=nsec;

	
	return pthread_cond_timedwait(&m_cond,m_pmutex,&stime);
}

int CCond::signal()
{
	return pthread_cond_signal(&m_cond); 
}

int CCond::broadcast()
{
	return pthread_cond_broadcast(&m_cond);
}

pthread_cond_t* CCond::getcond()
{
	return &m_cond;
}

int CCond::lock()
{
	return m_mutex.lock();
}

int CCond::unlock()
{
	return m_mutex.unlock();
}

int CCond::trylock()
{
	return m_mutex.trylock();
}
