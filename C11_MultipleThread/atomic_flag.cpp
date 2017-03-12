//use atomic_flag (atomit<bool>) implement

#include <iostream>
#include <atomic>
#include <thread>
#include <sstream>
#include <vector>

std::atomic_flag lockStream = ATOMIC_FLAG_INIT;
std::stringstream stream;

void apendNumber(int i)
{
    while(lockStream.test_and_set());

    stream << "thread #" << i <<"\n";

    lockStream.clear();
}

int main()
{
    std::vector<std::thread> threads;
    for(int i = 0; i < 10; i++)
    {
        threads.push_back(std::thread(apendNumber,i));
    }

    for(auto th : threads)
    {
        th.join();
    }
    
    std::cout<<stream.str();

    return 0;
}