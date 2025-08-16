#include  "headers.h"
#include "fthreads.h"

int main()
{  
    std::thread t1(printMessage, "Thread 1 is running", 3);
    std::thread t2(printMessage, "Thread 2 is running", 5);

    t1.join();
    t2.join();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}