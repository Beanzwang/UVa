#include <iostream>
#include <cmath>
#include <iomanip>

int main(int argc, const char *argv[]) {
    int H, M;
    while(scanf("%d:%d\n", &H, &M) == 2) {
        if (H == 0 && M == 0)
            break;
        float angle = std::abs(0.5 * (60 * H - 11 * M));
        if (angle > 180)
            angle = 360 - angle;
        std::cout << std::fixed << std::setprecision(3) << angle << std::endl;
    }
    return 0;
}