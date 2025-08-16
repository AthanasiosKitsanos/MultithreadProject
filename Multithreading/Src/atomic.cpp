#include "headers.h"
#include "fatomic.h"

int main()
{
    std::thread t1(increment);
    std::thread t2(increment);
    std::thread t3(increment);
    std::thread t4(increment);
    std::thread t5(increment);
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    
    std::cout << count << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();
    return 0;
}