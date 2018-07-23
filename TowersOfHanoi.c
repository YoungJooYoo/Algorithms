#include <stdio.h>

void hanoi_tower(int n, char from, char temp, char to) {
    
    printf("함수실행 %d \n", n);
    
    if (n == 1) {
        printf( "원판 1을 %c에서 %c로 옮겼습니다\n", from, to);
    }
    else {
        hanoi_tower(n - 1, from, to, temp);
        printf("원판 %i를 %c에서 %c로 옮겼습니다  바보\n", n, from, to);
        hanoi_tower(n - 1, temp, from, to);
    }
}

int main(int arc, char **argv) {
    char from = 'A';
    char temp = 'B';
    char to = 'C';
    
    hanoi_tower(7, from, temp, to);
    
    return 0;
}
