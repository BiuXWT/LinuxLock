#pragma once
#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

#define MUTEX_SHARED 1
#define MUTEX_PRIVATE 0

class CMutex{
public:
    CMutex(int shared);//SHARED PRIVATE
    CMutex();
    ~CMutex();
    int lock();
    int unlock();
    int trylock();
    pthread_mutex_t* getmutex();

private:
    pthread_mutex_t m_Mutex;
    pthread_mutexattr_t m_Attr;

};