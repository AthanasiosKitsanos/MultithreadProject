#include "headers.h"
#include "fconditional.h"

int main()
{
    std::thread t1(consumer);
    std::thread t2(producer, 5);

    t1.join();
    t2.join();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Preass any key to exit...";
    std::cin.get();
    return 0;
}