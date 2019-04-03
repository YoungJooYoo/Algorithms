#include <stdio.h>
#include "coinchange.h"

int main() {
    CoinItem *items = NULL;
    // 헤더파일에서 정의한 구조체 타입 CoinItem을 포인터로 선언하고 NUL로 초기화
    
    int item_count = 0; // 아이템을 카운트할 변수 선언 후 초기화
    int change_total = 0, remained = 0;
//    입력 받은 거스름돈,    남은돈이다. 입력된 거스롬 돈 이외에 남은 돈.
    
    printf("거스름돈은 얼마인가요?\n");
    scanf("%d", &change_total);
    
    printf("동전의 종류는 몇 가지인가요?\n");
    scanf("%d", &item_count);
    
    // 입력 받은 거스름돈과 동전의 종류가 0을 초과하는 조건을 만족하는지 보고 코드를 실행한다.
    if (item_count > 0 && change_total > 0) {
        items = (CoinItem *)malloc(sizeof(CoinItem) * item_count);
        // 동전의 종류는 몇 가지인가요? 에서 3개 입력하면 item count 3이 되어,
        // 공간이 그때그때 할당되게 하는 것이다.
        if (NULL != items) {
            // 위의 코드에서, 사용자에 입력 받은만큼 메모리를 할당을 제대로 받았는지
            // 확인하기 위한 조건으로 NULL ! = items
            
            inputItems(items, item_count);
            
            remained = getChange(change_total, items, item_count);
            
            printResult(items, item_count, remained);
            
            free(items); // 아이템 변수(구조체)의 사용이 모두 끝났으니 free를 통해 메모리에서 해제해준다.
        }
    }
    else {   //예외처리를 하는 것이다.
        printf("용량과 물건의 개수는 0보다 커야 합니다\n");
    }
    
    return 0;
}
