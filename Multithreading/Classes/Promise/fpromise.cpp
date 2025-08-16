#include "headers.h"
#include "fpromise.h"

void compute(std::promise<int> prom)
{
    prom.set_value(42);
}

void increment(std::promise<int> prom)
{   
    int result = 0;

    for(int i = 1; i <= 15; i++)
    {
        result += i;
    }

    prom.set_value(result);
}