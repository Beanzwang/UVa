#include<iostream>
#include<cstdlib>
#include<algorithm>

int main() {
    int line, cur = 0;
    scanf("%d", &line);
    while (cur < line) {
        int arr[3];
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
        std::sort(arr, arr + 3);
        std::cout << "Case " << cur + 1 << ": " << arr[1] << std::endl;
        cur++;
    }
    return 0;
}