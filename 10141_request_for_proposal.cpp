#include <iostream>
#include <string>
#include <limits>

int main(int argc, const char *argv[]) {
    // Ref: https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%2010141%20-%20Request%20for%20Proposal/src/UVa%2010141%20-%20Request%20for%20Proposal.cpp
    int n = 0, p = 0, count = 1;
    std::string str;
    while(std::cin >> n >> p, n || p) {
        std::string name, tName;
        float price = std::numeric_limits<float>::max(), tPrice;
        int req = -1, tReq;

        if(count > 1)
            std::cout << std::endl;
        
        std::cin.ignore();

        for (int i = 0; i < n; ++i) 
            getline(std::cin, str);

        while(p--) {
            getline(std::cin, tName);
            std::cin >> tPrice >> tReq;
            std::cin.ignore();

            for (int i = 0; i < tReq; ++i)
                getline(std::cin, str);

            if (req < tReq) {
                req = tReq;
                name = tName;
                price = tPrice;
            } else if ((req == tReq) && (price > tPrice)) {
                name = tName;
                price = tPrice;
            }
        }

        std::cout << "RFP #" << count++ << std::endl;
        std::cout << name << std::endl;
    }
    return 0;
}