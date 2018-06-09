#include "CMutex.h"

CMutex::CMutex(int shared)
{
    if (shared == MUTEX_SHARED)
    {
        pthread_mutexattr_init(&m_Attr);
        pthread_mutexattr_setpshared(&m_Attr, PTHREAD_PROCESS_SHARED);
        pthread_mutex_init(&m_Mutex, &m_Attr);
    }
    else if (shared == MUTEX_PRIVATE)
    {
        pthread_mutexattr_init(&m_Attr);
        m_Mutex = PTHREAD_MUTEX_INITIALIZER;
    }
    else
    {
        perror("wrong method");
    }
}

CMutex::CMutex()
{
    pthread_mutexattr_init(&m_Attr);
    m_Mutex = PTHREAD_MUTEX_INITIALIZER;
}

CMutex::~CMutex()
{
    pthread_mutex_destroy(&m_Mutex);
    pthread_mutexattr_destroy(&m_Attr);
}

int CMutex::lock()
{
    return pthread_mutex_lock(&m_Mutex);
}

int CMutex::unlock()
{
    return pthread_mutex_unlock(&m_Mutex);
}

int CMutex::trylock()
{
    return pthread_mutex_trylock(&m_Mutex);
}

pthread_mutex_t *CMutex::getmutex()
{
    return &m_Mutex;
}
