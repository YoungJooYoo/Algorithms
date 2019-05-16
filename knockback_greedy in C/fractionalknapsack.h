#ifndef fractionalknapsack_h
#define fractionalknapsack_h

#include <stdio.h>
#include <stdlib.h>

typedef struct _KnapsackItem {
    char name[100]; // 해당 물건의 이름
    double weight; // 해당 물건의 총 보유 재고량
    double profit; // 이익
    double selected; // 보유한 총양에서 일부 선택된 양을 나타낸다.
    // 즉 무게가 4kg이고 가격이 800원인 물건 A를 배낭에 1kg만큼 담으면, 멤버 변수 weight profit selcted 4,800,1이 저장된다.
} KnapsackItem;

void inputItems(KnapsackItem *items, int item_count); // 배낭에 담길 물건들의 정보를 사용자에게 입력 받는다.
double fractionalKnapsack(double capacity, KnapsackItem *items, int item_count); // 실제 최적의 해를 구하는 함수이다.
void printResult(KnapsackItem *items, int item_count, double max_profit);

#endif
