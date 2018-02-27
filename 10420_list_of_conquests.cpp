#include <iostream>
#include <string>
#include <map>

int main(int argc, const char *argv[]) {
    int n = 0;
    std::map <std::string, int> cMap;
    std::map <std::string, int>::iterator iter;

    std::cin >> n;
    while(n > 0) {
        std::string country, name;
        std::cin >> country;
        getline(std::cin, name);

        iter = cMap.find(country);
        if(iter != cMap.end()) 
            cMap[country] += 1;
        else
            cMap[country] = 1;
        n--;
    }

    for (std::map<std::string, int>::iterator it = cMap.begin(); it != cMap.end(); ++it)
        std::cout << it->first << " " << it->second << '\n';

    return 0;
}