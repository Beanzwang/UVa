#include <iostream>
#include <cmath>

// ref: https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%2010360%20-%20Rat%20Attack/src/UVa%2010360%20-%20Rat%20Attack.cpp

const int max_len = 1025;
int main() {
    int scenario;
    std::cin >> scenario;
    while(scenario > 0) {
        int d, n;
        std::cin >> d;
        std::cin >> n;
        int killed[max_len][max_len] = {{0}};

        while(n > 0) {
            int x, y, num;
            std::cin >> x;
            std::cin >> y;
            std::cin >> num;

            for (int i = x - d; i <= x + d; ++i) {
                if (i < 0 || i >= max_len)
                    continue;
                for (int j = y - d; j <= y + d; ++j) {
                    if (j < 0 || j >= max_len)
                        continue;
                    killed[i][j] += num;
                }
            }
            n--;
        }

        int max_x = -1, max_y = -1, max_num = -1;

        for (int i = 0; i < max_len; ++i) {
            for (int j = 0; j < max_len; ++j) {
                if (killed[i][j] > max_num) {
                    max_x = i;
                    max_y = j;
                    max_num = killed[i][j];
                }
            }
        }
        
        std::cout << max_x << " " << max_y << " " << max_num << std::endl;
        scenario--;
    }
    return 0;
}