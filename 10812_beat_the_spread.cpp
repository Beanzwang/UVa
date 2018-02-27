#include <iostream>

int main(int argc, const char *argv[]) {
    int n;
    std::cin >> n;
    while(n > 0) {
        double s, d;
        double a, b; // the score of first & second team.
        std::cin >> s >> d;
        a = (s + d) / 2;
        b = s - a;
        
        if (a < 0 || b < 0)
            std::cout << "impossible" << std::endl;
        else if ((a != (int)a) || (b != (int)b))
            std::cout << "impossible" << std::endl;
        else
            std::cout << (int)a << " " << (int)b << std::endl;
        n--;
    }
    return 0;
}