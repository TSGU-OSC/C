#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<time.h>

# define PI 3.14159265

int main() {




	initgraph(800, 600);
	setorigin(400, 300);
	//��ɫ��䱳��
	outtextxy(100, 200, L"��Դ����");

	setbkcolor(LIGHTGRAY);
	cleardevice();
	//����
	setfillcolor(RGB(7, 190, 234));//ͷ
	setlinecolor(BLACK);
	fillroundrect(-135, -206, 135, 54, 248, 248);
	setfillcolor(WHITE);//��
	fillellipse(-115, -144, 115, 46);
	fillroundrect(-63, -169, 0, -95, 56, 56);//����
	fillroundrect(0, -169, 63, -95, 56, 56);//����
	setfillcolor(BLACK);
	solidcircle(-16, -116, 6);//������
	solidcircle(16, -116, 6);//������
	setfillcolor(RGB(201, 62, 0));//����
	fillcircle(0, -92, 15);
	line(0, -77, 0, -4);
	arc(-108, -220, 108, -4, PI * 5 / 4, PI * 7 / 4);
	line(-42, -73, -90, -91);
	line(42, -73, 90, -91);
	line(-41, -65, -92, -65);
	line(41, -65, 92, -65);
	line(-42, -57, -90, -39);
	line(42, -57, 90, -39);
	//������
	line(-81, 32, -138, 72);
	line(81, 32, 138, 72);
	line(-96, 85, -96, 178);
	line(96, 96, 116, 110);
	line(-96, 85, -96, 178);
	line(96, 85, 96, 178);
	arc(-10, 168, 10, 188, 0, PI);
	setfillcolor(WHITE);
	fillcircle(-140, 99, 27);
	fillcircle(140, 99, 27);
	fillroundrect(-2, 178, -112, 205, 24, 24);
	fillroundrect(2, 178, 112, 205, 24, 24);
	setfillcolor(RGB(7, 190, 234));
	floodfill(0, 100, BLACK);
	setfillcolor(WHITE);
	fillcircle(0, 81, 75);
	solidrectangle(-60, 4, 60, 24);
	pie(-58, 23, 58, 139, PI, 0);
	setfillcolor(RGB(169, 38, 0));
	fillroundrect(-100, 23, 100, 42, 12, 12);
	setfillcolor(RGB(245, 237, 38));
	fillcircle(0, 49, 19);
	setfillcolor(BLACK);
	solidellipse(-4, 50, 4, 57);
	setlinestyle(PS_SOLID, 3);
	line(0, 57, 0, 68);

	setlinestyle(PS_SOLID, 1);
	line(-16, 40, 16, 40);
	line(-18, 44, 18, 44);
	srand((unsigned int)time(NULL));
	while (!_kbhit()) {
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		settextstyle(50, 50, L"����");
		outtextxy(-350, -250, L"ף��Դ�������!");
		Sleep(500);
	}

	_getch();
	closegraph;
	return 0;
}