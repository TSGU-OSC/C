#include<stdio.h>

void menu()
{
	printf("*************************************\n");
	printf("****		1.play		0.exit		****\n");
	printf("*************************************\n");
}
void game()
{
	//1.����һ�������
	int ret = 0;
	int guess = 0;
	ret = rand()%100+1;//ʹ0~32367��Ϊ1~100
	//printf("%d\n", ret);
	//2.������
	while (1)
	{
		printf("������֣�>");
		scanf_s("%d", &guess);
		if (guess > ret)
		{
			printf("�´���\n");
		}
		else if (guess < ret)
		{
			printf("��С��\n");
		}
		else
		{
			printf("��ϲ�㣬�¶��ˣ���\n");
				break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//��ʱ�����������������������
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();//����Ϸ�Ĺ���
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;//����switch

		}
	} while (input );
	return 0;
}