#include<iostream>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<climits>

int main() {
    // BGC
    int list[] = {1, 2, 3};
    std::sort(list, list + 3);
    std::string line;
    char split_char = ' ';
    while(std::getline(std::cin, line)) {
        int data[3][3];
        std::istringstream iss(line);
        iss >> data[0][0] >> data[0][2] >> data[0][1] >> data[1][0] >> data[1][2] >> data[1][1]
            >> data[2][0] >> data[2][2] >> data[2][1];
        int bin[3];
        for(int i = 0; i < 3; ++i) {
            bin[i] = data[i][0] + data[i][1] + data[i][2];
        }
            
        int min = INT_MAX;
        int min_list[3];
        do {
            int cur = 0;
            int t[3];
            for (int i = 0; i < 3; ++i) {
                t[i] = bin[i];
                t[i] -= data[i][list[i] - 1];
                cur += t[i];
            }
            if (min > cur) {
                min = cur;
                for (int i = 0; i < 3; ++i)
                    min_list[i] = list[i];
            }
        } while (std::next_permutation(list, list + 3));
        for (int i = 0; i < 3; ++i) {
            switch(min_list[i]){
                case 1:
                    std::cout << 'B';
                    break;
                case 2:
                    std::cout << 'C';
                    break;
                case 3:
                    std::cout << 'G';
                    break;
                default:
                    std::cout << "default!!" << std::endl;
                    break;
            }
        }
        std::cout << ' ' << min << std::endl;
    }
    return 0;
}