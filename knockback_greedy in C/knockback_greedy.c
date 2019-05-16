/************************************************
 코드 출처 : 코드와 그림으로 마스터하는 알고리즘 -이상진 저-
 주석 : 나
 ************************************************/

#include <stdio.h>
#include "fractionalknapsack.h"

int main() {
    KnapsackItem *items = NULL;
    
    int item_count = 0;
    double capacity = 0, max_profit = 0;  // capacity 용량을 꽉채우는 것이 최대 이익이 나온다.
    
    printf("가방의 전체 용량을 입력해 주세요\n");
    scanf("%lf", &capacity);
    
    printf("물건은 몇 개인가요?\n");
    scanf("%d", &item_count);
    
    // 사전에 item_count 사이즈만큼 할당한다. 즉 items메모리를 item_count 만큼 곱해서 메모리를 찍어낸다. 즉 배열이지
    if (item_count > 0 && capacity > 0) {
        items = (KnapsackItem *)malloc(sizeof(KnapsackItem) * item_count);
        if (NULL != items) {
            inputItems(items, item_count);
            
            max_profit = fractionalKnapsack(capacity, items, item_count);
            
            printResult(items, item_count, max_profit);

            free(items);
        }
    }
    else {
        printf("용량과 물건의 개수는 0보다 커야 합니다\n");
    }
    
    return 0;
}



// https://dojang.io/mod/page/view.php?id=318 동적메모리 반복문으로 할당하기 참조
