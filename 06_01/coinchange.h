#ifndef coinchange_h // coinchange.c에서도 main에서도 참조하니 중복 참조 방지를 위해 선언
#define coinchange_h

#include <stdio.h>
#include <stdlib.h>

typedef struct CoinItem {
    int value; // 동전의 500원, 100원의 값 등
    int selected; // 선택 되어진 값, 즉 몇개 선택 되었니?
} CoinItem; // 타입을  CoinItem로 정의함

void inputItems(CoinItem *items, int item_count); // 이제 입력을 받자
int getChange(int change_total, CoinItem *items, int item_count); // 잔돈 계산
void printResult(CoinItem *items, int item_count, int remained); // 결과를 출력

#endif

