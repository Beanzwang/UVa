#include <iostream>
#include <climits>

int main(int argc, const char * argv[]) {
    int T = 0, n_case = 1;
    std::cin >> T;
    while(T != 0) {
        int n_creature = 0, max_speed = INT_MIN, cur_speed = 0;
        std::cin >> n_creature;
        for (int i = 0; i < n_creature; ++i) {
            std::cin >> cur_speed;
            if (cur_speed > max_speed)
                max_speed = cur_speed;
        }
        std::cout << "Case " << n_case << ": " << max_speed << std::endl;
        n_case++;
        T--;
    }
    return 0;
}