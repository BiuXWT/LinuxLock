#pragma once
#include<semaphore.h>
#include<stdlib.h>
#include<time.h>

class CSem{
private:
    sem_t m_sem;

public:
    CSem();
    CSem(int n);
    ~CSem();

    int wait();
    int trywait();
    int timedwait(int sec,int nsec);
    int post();
    sem_t* getsem();
};




