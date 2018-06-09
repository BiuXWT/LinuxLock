#include"CSem.h"

CSem::CSem()
{
	sem_init(&m_sem,0,10);
}

CSem::CSem(int n)
{
	sem_init(&m_sem,0,n);
}

CSem::~CSem()
{
	sem_destroy(&m_sem);
}


int CSem::wait()//--
{
	return sem_wait(&m_sem);
}

int CSem::trywait()
{
	return sem_trywait(&m_sem);
}

int CSem::timedwait(int sec,int nsec=0)
{
    struct timespec stime;
    time_t currtime=time(NULL);
    stime.tv_sec=currtime+sec;
    stime.tv_nsec=nsec;
	return sem_timedwait(&m_sem,&stime);
}

int CSem::post()//++
{
	return sem_post(&m_sem);
}

sem_t* CSem::getsem()
{
	return &m_sem;
}
