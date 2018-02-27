#include <iostream>
#include <climits>

int main(int argc, const char * argv[]) {
    int N, B, H, W;
    while (std::cin >> N >> B >> H >> W) {
        int curH = 0;
        int found = 0;
        int min_total_price = INT_MAX;
        while (curH < H) {
            int price = 0;
            int curW = 0;

            std::cin >> price;
            curH++;

            while(curW < W) {
                int curN = 0;
                std::cin >> curN;
                int total_price = price * N;
                
                if (total_price < min_total_price) 
                    min_total_price = total_price;
                
                if (curN >= N && (B >= total_price))
                    found = 1;
                curW++;
            }
        }
        if (!found)
            std::cout << "stay home" << std::endl;
        else
            std::cout << min_total_price << std::endl;
        found = 0;
    }
    return 0;
}