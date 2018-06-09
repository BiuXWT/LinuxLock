#pragma once
#include<pthread.h>
#include"../CMutex/CMutex.h"

class CCond
{
private:
    pthread_cond_t m_cond;
    pthread_mutex_t *m_pmutex;
    CMutex m_mutex;
public:
    CCond();
    ~CCond();

    int lock();
    int unlock();
    int trylock();

    int wait();
    int timedwait(int sec,int msec/*纳秒*/);
    int signal();
    int broadcast();
    pthread_cond_t* getcond();
};