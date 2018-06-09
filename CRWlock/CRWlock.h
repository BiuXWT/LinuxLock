#pragma once
#include<pthread.h>

class CRWlock
{
private:
    pthread_rwlock_t m_rwlock;

public:
    CRWlock();
    ~CRWlock();
    int rdlock();
    int wrlock();
    int tryrdlock();
    int trywrlock();
    int unlock();
    pthread_rwlock_t* getrwlock();
};