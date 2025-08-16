#include  "headers.h"
#include "functions.h"

int main()
{   
    std::thread t1(function1);
    std::thread t2(function2);

    t1.join();
    t2.join();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}