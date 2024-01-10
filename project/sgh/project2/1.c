#include<stdio.h>

void menu()
{
	printf("*************************************\n");
	printf("****		1.play		0.exit		****\n");
	printf("*************************************\n");
}
void game()
{
	//1.生成一个随机数
	int ret = 0;
	int guess = 0;
	ret = rand()%100+1;//使0~32367变为1~100
	//printf("%d\n", ret);
	//2.猜数字
	while (1)
	{
		printf("请猜数字：>");
		scanf_s("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你，猜对了！！\n");
				break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//用时间戳来设置随机数的生成起点
	do
	{
		menu();
		printf("请选择>:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();//玩游戏的过程
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;//结束switch

		}
	} while (input );
	return 0;
}