#include <iostream>

int main(int argc, const char * argv[]) {
    float H = 0, U = 0, D = 0, F = 0;
    
    while(std::cin >> H >> U >> D >> F) {
        if (H == 0) break;

        float cur = 0, fatigue = U * (F / 100);
        int day = 1;

        while (true) {
            cur += U;
            U -= fatigue;
            if (U < 0) U = 0;
            if (cur > H) break;  // reach the well
            cur -= D;
            if (cur < 0) break;  // fall to bottom
            day++;
        }
        if (cur > H)
            std::cout << "success on day " << day << std::endl;
        else
            std::cout << "failure on day " << day << std::endl;
    }
    return 0;
}