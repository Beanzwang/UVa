#include<cstdlib>
#include<iostream>

int main() {
    int i, j;
    while(scanf("%d %d\n", &i, &j) != EOF) {
        bool swap = false;
        if (i > j) {
            swap = true;
            int temp = i;
            i = j;
            j = temp;
        }
        int cur = i;
        int largest = 0;
        while(cur <= j) {
            int n = cur;
            int num = 1;
            while (n != 1) {
                num++;
                if (n % 2 != 0)
                    n = 3 * n + 1;
                else
                    n = n >> 1;
            }
            if (num > largest) 
                largest = num;
            cur++;
        }
        if (swap) 
            std::cout << j << " " << i << " " << largest << std::endl;
        else
            std::cout << i << " " << j << " " << largest << std::endl;
    }

    return 0;
}