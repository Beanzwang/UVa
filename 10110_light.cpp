#include <iostream>
#include <cmath>

int main(int argc, const char *argv[]) {
    unsigned int n, x;
    while(std::cin >> n) {
        if (n == 0)
            break;
        x = sqrt(n);
        if (n == x*x)
            std::cout << "yes" << std::endl;
        else
            std::cout << "no" << std::endl;
    }
    return 0;
}