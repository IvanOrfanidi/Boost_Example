#include <boost/chrono.hpp>
#include <boost/thread.hpp>

#include <iostream>
#include <string>
#include <vector>

void output()
{
    std::cout << "Hello World" << std::endl;
}

int main()
{
    boost::thread th(output);
    th.join();
    return 0;
}
