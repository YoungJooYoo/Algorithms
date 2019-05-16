#include "fractionalknapsack.h"

// 퀵정렬을 위해서 ~
int compare_KnapsackItem_ratio(const void *value1, const void *value2){
    KnapsackItem *item1 = (KnapsackItem*)value1;
    KnapsackItem *item2 = (KnapsackItem*)value2;
    
    double ratio1 = item1->profit / item1->weight;
    double ratio2 = item2->profit / item2->weight;
    
    if (ratio1 < ratio2) {
        return 1;
    }
    else if (ratio1 > ratio2) {
        return -1;
    }
    else {
        return 0;
    }
}

// 배낭의 용량 capacity, 물건들의 정보를 저장 구조체 items, 물건의 가짓수인 item_count
double fractionalKnapsack(double capacity, KnapsackItem *items, int item_count) {
    double max_profit = 0, current_weight = 0;
    int i =0;
    
    qsort(items, item_count, sizeof(KnapsackItem), compare_KnapsackItem_ratio);
    
    printf("정렬 결과\n\t무게\t가치\t비율\n");
    for (i = 0; i < item_count; i++) {
        printf("%d\t%.2f\t%.2f\t%.2f\n", i, items[i].weight, items[i].profit,
               items[i].profit / items[i].weight);
    }
    
    
    for (i = 0; i < item_count; i++) {
        // if 구문 로직은, items중 인덱스 순서대로 하나 찍어서 capacity = 가방이 담기는 kg, 즉 용량까지 체크
        if(current_weight + items[i].weight < capacity) { // 가방전체용량 넘어가는지 체크
            items[i].selected = items[i].weight; // capacity양에 따라, 재고량이 선택되어진다. 예제 입력과정 따라가다 보면 무조건 성립한다.
            current_weight = current_weight + items[i].weight ;  // 현재 가방에 담은 무게를 누적하는 과정,
            max_profit += items[i].profit; // 그 물건이 가진 금전적 가치를 누적해서 max_profit을 구한다.
        }
        //  items[i].selected = items[i].weight;  이 부분을 벗어날때쯤 else가 무조건 발생
        else {
            double remaining  = capacity - current_weight; // 최대용량 - 현재용량 =  채워야할 남은 용량
            items[i].selected = remaining; // capcity - current_weight는 일치하는 경우로 끝난다 즉 remaining이 음수로 나올일 없이 0으로 끝 어떤 물건은 선택된 것이 0으로 나오는 것이 이 이유다.
            max_profit += items[i].profit * items[i].selected / items[i].weight; // 물건읠 쪼개서 더하는 것이다. 즉 4키로에 800원이면, 1키로 200원이라는 비율을 계산하기 위해서
            printf("max_profit = %f\n\n",max_profit);
            break;
        }
    }
    
    return max_profit;
}

// 구조체를 함수에 넣어 각 변수들의 초기 값을 입력 받는다. 이미 item_count 갯수만큼 메모리를 할당 받았으므로, 배열을 채워나간다.
void inputItems(KnapsackItem *items, int item_count) {
    int i = 0;
    for (i = 0; i < item_count; i++) {
        printf("%d 번째 물건의 이름을 입력해 주세요\n", i + 1);
        scanf("%s", items[i].name); // name은 배열이므로 &없어도 된다. 배열은 첫주소를 담고 있으므로!
        
        printf("%d 번째 물건의 무게와 가치를 입력해 주세요\n", i + 1);
        scanf("%lf %lf", &items[i].weight, &items[i].profit); // double로 선언하면 lf로 입력 받는다.
        
        items[i].selected = 0; 
    }
}

// 결과 출력 함수
void printResult(KnapsackItem *items, int item_count, double max_profit) {
    int i = 0;
    printf("최대 이익: %.2f\n", max_profit);
    printf("(선택된 무게)\t(전체 무게)\n");
    for (i = 0; i < item_count; i++) {
        printf("%s\t%.2f\t%.2f\n", items[i].name, items[i].selected, items[i].weight);
    }
}
