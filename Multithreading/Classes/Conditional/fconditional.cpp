#include "headers.h"
#include "fconditional.h"

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void waiting_thread()
{

}

void notifying_thread()
{
    
}