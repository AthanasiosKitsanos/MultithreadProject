#include "headers.h"
#include "fsync.h"

void increment(int& counter, std::mutex& mtx)
{
    for(int i = 0; i < 10000; i++)
    {
        std::lock_guard<std::mutex> lock(mtx);
        counter++;
    }
}