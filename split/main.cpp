#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    const std::string input = "1;2;3;4;5"; // Or string_view in C++17
    std::vector<std::string> output;

    boost::split(output, input, boost::is_any_of(";"));
    for (auto& i : output) {
        std::cout << i << std::endl;
    }

    return 0;
}
