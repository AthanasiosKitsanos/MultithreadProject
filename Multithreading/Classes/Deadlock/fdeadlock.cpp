#include "headers.h"
#include "fdeadlock.h"

std::mutex mtx1, mtx2;

void ThreadA()
{
    std::lock(mtx1, mtx2);
    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);
    std::cout << "Thread A has finished" << std::endl;
}

void ThreadB()
{
    std::lock(mtx1, mtx2);
    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);
    std::cout << "Thread B has finished" << std::endl;
}