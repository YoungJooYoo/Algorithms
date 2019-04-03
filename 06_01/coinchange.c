#include "coinchange.h"

/*********************************************************************************
 *c언어에서 제공해주는 퀵정렬을 사용하기
 *
 *stdlib.h 헤더 파일에 선언
 *qsort(정렬할배열, 요소개수, 요소크기, 비교함수);
 *qsort(정렬할메모리주소, 요소개수, 요소크기, 비교함수);
 *void qsort(void *_Base, size_t _NumOfElements, size_t _SizeOfElements, int (*_PtFuncCompare)(void const *, void const *));
 *먼저 qsort 함수를 사용하기 전에 비교(compare) 함수를 만들어야 합니다.
 
 *출처: c언어 코딩 도장
 *URL: https://dojang.io/mod/page/view.php?id=638
 *********************************************************************************/


// qsort 사용을 하기위한 비교함수를 만든다.
//함수 파라미터로 있는 const void *a 는, 포인터 형을 인자로 받되 포인터가 어떤 특정 데이터 타입의 포인터 인지를 상관하지 않고 무조건 포인터면 받겠다는 의지가 담겨있으면서, 함수 내에서 a 가 가리키는(포인팅하는) 주소값이 변경되지 않고 받은 그대로만 쓸 수 있도록 const 를 붙였네요. 그래서 함수 내에서는 그냥 a 는 그냥 주소값을 포인팅하는 포인터일뿐 그게 어떤 데이터 타입을 가리키고 있는지는 모르는 거죠. 그러니 그 값을 얻어오려면 데이터 타입을 알려줘야 합니다. 그래서 char* 로 형변환을 하고 형변환된 포인터에 * 를 붙여 char 짜리 값을 얻어오는 겁니다. 포인터는 사실 데이터 타입이랄게 없습니다. 그냥 주소값을 포인트 하는 넘이기 때문에 어떤 타입의 포인터든 다 똑같죠. 근데 뭐가 다르냐면 * 로 값을 가져올 때 포인팅된 주소부터 몇바이트를 읽어서 값으로 만들꺼냐 하는거죠. 어차피 메모리는 선형으로 죽~ 이어져 있고, 포인터는 그 중에 한 점을 지정하는 거기 때문에 특별히 타입 지정 안해도 별 상관 없습니다. 그래서 void* 이라는 표현이 가능하죠(이건 꼭 캐스팅 해서 써야 합니다), 그리고 아무 타입의 포인터로도 형변환 시킬 수 있습니다. 즉 데이터가 더블, 롱에 따라 읽는 바이트가 달라지니 그것을, 미리 알려주는 것
// 출처: http://cluster1.cafe.daum.net/_c21_/bbs_search_read?grpid=LtXl&fldid=5mz0&datanum=1207

int compare_CoinItem_value(const void *value1, const void *value2) {
    CoinItem *item1 = (CoinItem*)value1;
    CoinItem *item2 = (CoinItem*)value2;
    
    if (item1->value < item2->value) {
        return 1;
    }
    else if (item1->value > item2->value) {
        return -1;
    }
    else {
        return 0;
    }
}
// 지금 위의 함수는 C언어에서 기본으로 제공하는 퀵정렬 함수에 대한 필수요소중 하나인 비교함수를 작성한 것.
// 리턴 값에 따라, 스왑읠 결정한다 1이면 스왑!




//현재 잔돈과, 구조체에 들어가 있는 동전별 화폐 단위를 입력을 받는 함수이다.
int getChangeCount(int target_change, int coin_value) {
    int count = 0;
    
    // 나 몫을 구해버려서 코인 카운트 갯수를 구한다.
    if (target_change >= coin_value) {
        count = target_change / coin_value;
    }
    
    return count;  // 구해진 몫을 리턴한다.
}


int getChange(int change_total, CoinItem *items, int item_count) {
    int current_change = change_total;   // 사용자로 입력 받은 거스름돈을 대입
    int i =0;
    
    qsort(items, item_count, sizeof(CoinItem), compare_CoinItem_value);
    // c언어에서 제공해주는 퀵정렬, 구조체 비교라 그냥 함수를 선언하고 끝
    // 퀵소트 원형에 의하면 포인터형 함수를 compare를 만들어서 넣고, 리턴 값에 따라 스왑을 결정해 정렬을 한다.
    // 이 함수를 실행하면 이미 "배열"내의 모든 값이 정렬이 끝났다.
    // 즉 입력 받은 화폐 단위를 정렬한다.
    
    printf("정렬 결과\n\t값\n");
    
    for (i = 0; i < item_count; i++) {
        printf("%d\t%d\n", i, items[i].value);
        // 500원짜리등 단위 화폐 , 입력 받은 단위화폐를 출력핟나.
    }
    for (i = 0; i < item_count; i++) {
        int count = getChangeCount(current_change, items[i].value);
        items[i].selected = count;  // 카운트된 단위화폐를 변수에 넣어주고
        current_change = current_change - count * items[i].value; // 잔돈에 단위화폐를 빼어준다.
    }
    
    return current_change;   // 단위 화폐를 통해 빠진 남은 잔액을 리턴하고, 이것으로 다시 계산한다.
}



// 사용자에게 입력받은 items, item_count 변수를 받는다.
void inputItems(CoinItem *items, int item_count) {
    int i = 0;
    for (i = 0; i < item_count; i++) {
        printf("%d 번째 동전의 단위를 입력해 주세요 (예, 100)\n", i + 1);
        scanf("%d", &items[i].value);  //입력 받은 아이템 갯수를 반복문과, 값을 할당에 인덱스로 사용
        
        items[i].selected = 0; // items는 구조체고, 위에서 value를 항당 받고, selected에도 초기화
    }
}


void printResult(CoinItem *items, int item_count, int remained) {
    int i = 0;
    printf("(동전)\t(동전 개수)\n");
    for (i = 0; i < item_count; i++) {
        printf("%d\t%d\n", items[i].value, items[i].selected); // 500원짜리 같은 동전의 값과 몇개 거슬러주는지 출력한다.
    }
    printf("남은 거스름돈: %d\n", remained);  // 주어진 단위 화폐를 벗어나 남은 돈을 의미한다.
}

