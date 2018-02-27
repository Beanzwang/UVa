#include<cstdlib>
#include<iostream>

int main() {
    int line, cur = 0;
    scanf("%d", &line);
    while(cur < line) {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        if (num1 > num2) 
            std::cout << ">" << std::endl;
        else if(num1 < num2)
            std::cout << "<" << std::endl;
        else
            std::cout << "=" << std::endl;
        cur++;
    }
    return 0;
}