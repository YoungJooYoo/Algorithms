#include "stdio.h"
#define SIZE 7

static char queue[SIZE];
int front = -1;
int rear = -1;

/************************************************* 
큐는 배열로 구현했기에, Index가 0부터 시작하므로,
SIZE-1을 통해 인덱스 위치를 정확하게 인지해야한다.
**************************************************/
void insertQ(char data) {
	if (rear == SIZE - 1) {
		printf("queue overflows.");
		system("pause");
		exit(1);
	}
	else {
		rear++;
		queue[rear] = data;
	}
}
/*************************************************
큐는 배열로 구현했기에, 저장된 자료를 실제 삭제가
아닌 값을 return을 하며, 논리적으로 삭제했다고,
가정을 하는 것이다. 실제 메모리에는 자료가 남아 있다.
**************************************************/
char deleteQ() {
	if (front == rear) {
		printf("queue empty.");
		system("pause");
		exit(1);
	}
	else {
		front++;
		return(queue[front]);
	}
}

void main() {
	int  suntaek;
	char item;

	printf("queue의 주소=%d,  front의 주소=%d, rear의 주소=%d \n", &queue[0], &front, &rear);

	while (1) {
		fflush(stdin);                              /* 키보드버퍼를 비운다 */
		printf("\n 1:insertQ  2:deleteQ   3:종료 ...? ");
		scanf_s("%d", &suntaek);

		switch (suntaek)
		{
		case 1:
			printf("자료 (A-Z, a-z 입력)...? ");
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
