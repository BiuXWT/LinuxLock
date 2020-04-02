#pragma once
#include<pthread.h>

class CRWlock
{
private:
    pthread_rwlock_t *m_rwlock;

public:
    CRWlock( int shared=0,pthread_rwlock_t** lock=nullptr);
    ~CRWlock();
    int rdlock();
    int wrlock();
    int tryrdlock();
    int trywrlock();
    int unlock();
    pthread_rwlock_t* getrwlock();
};