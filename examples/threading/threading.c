#include "threading.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Optional: use these functions to add debug or error prints to your application
//#define DEBUG_LOG(msg,...)
#define DEBUG_LOG(msg,...) printf("threading: " msg "\n" , ##__VA_ARGS__)
#define ERROR_LOG(msg,...) printf("threading ERROR: " msg "\n" , ##__VA_ARGS__)

void* threadfunc(void* thread_param)
{
    if(!thread_param)
    {
        ERROR_LOG("Invalid input parameter!!");
        return NULL;
    }

    // TODO: wait, obtain mutex, wait, release mutex as described by thread_data structure
    // hint: use a cast like the one below to obtain thread arguments from your parameter
    struct thread_data* thread_func_args = (struct thread_data *) thread_param;

    DEBUG_LOG("wait %dms to obtain the mutex", thread_func_args->wait_to_obtain_ms);
    usleep(thread_func_args->wait_to_obtain_ms * 1000);

    pthread_mutex_lock(thread_func_args->mtx);
    usleep(thread_func_args->wait_to_release_ms * 1000);

    thread_func_args->thread_complete_success = true;
    DEBUG_LOG("exit the thread");
    pthread_mutex_unlock(thread_func_args->mtx);
    return thread_param;
}


bool start_thread_obtaining_mutex(pthread_t *thread, pthread_mutex_t *mutex,int wait_to_obtain_ms, int wait_to_release_ms)
{
    /**
     * TODO: allocate memory for thread_data, setup mutex and wait arguments, pass thread_data to created thread
     * using threadfunc() as entry point.
     *
     * return true if successful.
     *
     * See implementation details in threading.h file comment block
     */
    struct thread_data* t_data = (struct thread_data *) malloc(sizeof(struct thread_data));
    if(!t_data)
    {
        ERROR_LOG("fail to allocate thread_data!!");
        return false;
    }

    memset(t_data, 0, sizeof(struct thread_data));
    t_data->mtx = mutex;
    t_data->wait_to_obtain_ms = wait_to_obtain_ms;
    t_data->wait_to_release_ms = wait_to_release_ms;

    if(pthread_create(thread, NULL, threadfunc, (void*)t_data) != 0)
    {
        ERROR_LOG("pthread_create error");
        return false;
    }

    return true;
}

