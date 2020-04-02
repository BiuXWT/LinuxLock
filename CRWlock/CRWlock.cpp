#include"CRWlock.h"

CRWlock::CRWlock(int shared=0,pthread_rwlock_t **lock=nullptr)
{
    pthread_rwlockattr_t attr;
    if (shared)
    {
        pthread_rwlockattr_setpshared( &attr, PTHREAD_PROCESS_SHARED );
    }
    if (lock)
    {
        if (*lock==nullptr)
        {
            *lock=new pthread_rwlock_t;
        }
        m_rwlock=*lock;
    }
    else
    {
        m_rwlock=new pthread_rwlock_t;
    }
    
    pthread_rwlock_init(m_rwlock,&attr);
}

CRWlock::~CRWlock()
{
    pthread_rwlock_destroy(m_rwlock);
    delete m_rwlock;
}

int CRWlock::rdlock()
{
    return pthread_rwlock_rdlock(m_rwlock);
}

int CRWlock::wrlock()
{
    return pthread_rwlock_wrlock(m_rwlock);
}

int CRWlock::tryrdlock()
{
    return pthread_rwlock_tryrdlock(m_rwlock);
}

int CRWlock::trywrlock()
{
    return pthread_rwlock_trywrlock(m_rwlock);
}

int CRWlock::unlock()
{
    return pthread_rwlock_unlock(m_rwlock);
}

pthread_rwlock_t* CRWlock::getrwlock()
{
    return m_rwlock;
}
