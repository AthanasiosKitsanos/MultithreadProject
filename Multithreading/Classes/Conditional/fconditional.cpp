#include "headers.h"
#include "fconditional.h"

std::mutex mtx;
std::condition_variable cv;
int data = 0;
std::queue<int> intQueue;
bool done = false;

void waiting_thread()
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return data > 0; });

    std::cout << "Waiting thread is notified" << std::endl;
}

void notifying_thread()
{
    std::lock_guard<std::mutex> lock(mtx);
    data++;

    cv.notify_one();
    std::cout << "Notifying thread has finished" << std::endl; 
}

void producer(int number)
{   
    for(int i = 0; i <= number; i++)
    {
        
        {
            std::lock_guard<std::mutex> lock(mtx);
            intQueue.emplace(i);
            cv.notify_one();
            std::cout << i << " was added in the queue" << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    done = true;
    cv.notify_one();
}

void consumer()
{
    while(true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !intQueue.empty() || done; });

        if(done)
        {
            break;
        }

        std::cout << "Consumer was notified" << std::endl;
        std::cout << "Consumed: " << intQueue.front() << std::endl;
        intQueue.pop();
    }
}