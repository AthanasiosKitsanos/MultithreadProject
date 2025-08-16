#include "headers.h"
#include "fatomic.h"

std::atomic<int> count = 0;

void increment()
{
    for(int i = 1; i <= 1000; i++)
    {
        count++;
        std::cout << count << std::endl;
    }
}