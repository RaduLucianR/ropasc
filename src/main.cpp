#include <iostream>
#include <utils.hpp>

int main()
{
    int a;
    int b;

    a = 0;
    b = 0;

    std::cin >> a;
    std::cin >> b;
    std::cout << sum(a, b);

    return 0;
}