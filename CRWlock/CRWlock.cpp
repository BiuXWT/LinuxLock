#include"CRWlock.h"

CRWlock::CRWlock()
{
    m_rwlock=PTHREAD_RWLOCK_INITIALIZER;
}

CRWlock::~CRWlock()
{
    pthread_rwlock_destroy(&m_rwlock);
}

int CRWlock::rdlock()
{
    return pthread_rwlock_rdlock(&m_rwlock);
}

int CRWlock::wrlock()
{
    return pthread_rwlock_wrlock(&m_rwlock);
}

int CRWlock::tryrdlock()
{
    return pthread_rwlock_tryrdlock(&m_rwlock);
}

int CRWlock::trywrlock()
{
    return pthread_rwlock_trywrlock(&m_rwlock);
}

int CRWlock::unlock()
{
    return pthread_rwlock_unlock(&m_rwlock);
}

pthread_rwlock_t* CRWlock::getrwlock()
{
    return &m_rwlock;
}
