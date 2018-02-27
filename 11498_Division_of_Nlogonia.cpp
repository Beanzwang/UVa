#include<cstdlib>
#include<iostream>

int main() {
    int line;
    while(scanf("%d", &line) == 1) {
        int cor_x, cor_y, cur = 0;
        scanf("%d %d", &cor_x, &cor_y);
        while (cur < line) {
            int x, y;
            scanf("%d %d", &x, &y);
            cur++;
            if (x == cor_x || y == cor_y) {
                std::cout << "divisa" << std::endl;
                continue;
            }
            if (x > cor_x) {
                if (y > cor_y) 
                    std::cout << "NE" << std::endl;
                else
                    std::cout << "SE" << std::endl;
            } else {
                if (y > cor_y) 
                    std::cout << "NO" << std::endl;
                else
                    std::cout << "SO" << std::endl;
            }
        }
    }
    return 0;
}