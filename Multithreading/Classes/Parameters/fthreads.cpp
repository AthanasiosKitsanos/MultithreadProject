#include "headers.h"
#include "fthreads.h"

void printMessage(const std::string& msg, const int& counter)
{
    for(int i = 0; i < counter; i++)
    {
        std::cout << msg << " (" << i + 1 << ")" << std::endl;
    }
}