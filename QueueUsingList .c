#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define _CRT_SECURE_NO_WARNINGS

typedef struct queue_node {
	char data;
	struct queue_node *link;
} queue_node;
queue_node *front = NULL, *rear = NULL, *new_node = NULL, *ptr = NULL;
char temp = NULL;


/*************************************************
if 구문에서 메모리 할당 실패를 대비한 확인 절차이다.
실제로 일어나는 경우는 없다고 볼정도로 거의 없지만,
절차상 반드시 넣는 것은 중요하다.
리스트로 구현하느 만큼 기본적인 논리는 연결리스트
만드는 과정과 똑같다. 
**************************************************/
void insertQ(char data) {
	new_node = malloc(sizeof(queue_node));
	if (new_node == NULL) {
		printf("memory allocation error\n");
		exit(1);
	}
	new_node->data = data;
	new_node->link = NULL;
	if (front == NULL)
		front = new_node;
	else
		rear->link = new_node;
		rear = new_node;
}


/*************************************************
스택에서 구현한 큐와 다르게, 리스트로 구현한 큐의
삭제작업은 free를 이용해 실제 메모리에서 지워버린다
**************************************************/
char deleteQ() {

	if (front == NULL) {
		printf("queue empty.");
		exit(1);
	}
	temp = front->data;
	ptr = front;
	front = front->link;
	free(ptr);
	if (front == NULL) 
		rear = NULL;
	return(temp);
}

main() {

	int  suntaek;
	char item = NULL;

	for (;;) {
		fflush(stdin);                              /* 키보드버퍼를 비운다 */
		printf("\n 1:insertQ  2:deleteQ   3:종료 ...? ");
		scanf_s("%d", &suntaek);

		switch (suntaek)
		{
		case 1:
			printf("자료 (A-Z, a-z)...? ");
			scanf_s("%s", &item, sizeof(&item));
			insertQ(item);
			printf("insert후의 rear의 값 = %d, insert되어 삽입된 data = %c\n", rear, item);
			break;
		case 2:
			item = deleteQ();
			printf("delete후의 front의 값 = %d, delete되어 삭제된 data = %c\n", front, item);
			break;
		case 3:
			return;
		}
	}
	printf("\n 프로그램 종료");
}
