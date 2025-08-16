#include "headers.h"
#include "fpromise.h"

int main()
{
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();

    std::thread t(increment, std::move(prom));

    std::cout << "The result is: " << fut.get() << std::endl;

    t.join();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();
    return 0;
}