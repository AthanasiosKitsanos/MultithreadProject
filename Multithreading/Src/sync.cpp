#include  "headers.h"
#include "fsync.h"

int counter = 0;
std::mutex mtx;

int main()
{  
    std::thread t1(increment, std::ref(counter), std::ref(mtx));
    std::thread t2(increment, std::ref(counter), std::ref(mtx));

    t1.join();
    t2.join();

    std::cout << counter << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}