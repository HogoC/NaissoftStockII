#include "Arts.h"


#include <stdio.h>
#include <Windows.h>

void startLogo()
{
	setcursortype(NOCURSOR);

	Sleep(500);
	textcolor(8);
	gotoxy(48, 15), printf("�� 2013~2016 Naissoft");
	Sleep(65);
	textcolor(7);
	gotoxy(48, 15), printf("�� 2013~2016 Naissoft");
	Sleep(65);
	textcolor(15);
	gotoxy(48, 15), printf("�� 2013~2016 Naissoft");
	Sleep(1000);
	textcolor(7);
	gotoxy(48, 15), printf("�� 2013~2016 Naissoft");
	Sleep(65);
	textcolor(8);
	gotoxy(48, 15), printf("�� 2013~2016 Naissoft");
	Sleep(65);
	system("cls");
	textcolor(7);
	Sleep(1000);
	textcolor(8);
	gotoxy(1, 1), printf("����");
	Sleep(75);
	textcolor(7);
	gotoxy(1, 1), printf("����");
	Sleep(75);
	textcolor(15);
	gotoxy(1, 1), printf("����");
	Sleep(600);
	gotoxy(1, 3);
	printf("�� ������ ���� �ֽ� ���ڿ� �ٸ��ϴ�. ������ �ֽ� ���ڸ� �� �� �����Ͻʽÿ�.\n ���� ���� ȸ��� ���� ȸ�縦 �������� ������, �� ������ ��� �㱸�Դϴ�.\n �ҽ� �ڵ�� �����Ǿ� ������,");
	printf(" �����Ͽ� �Ǹ��ϴ� ���� ����� ������ �� �� �����ϴ�.");
	Sleep(3000);
	textcolor(7);
	gotoxy(1, 1), printf("����");
	Sleep(75);
	textcolor(8);
	gotoxy(1, 1), printf("����");
	Sleep(75);
	system("cls");
	textcolor(7);
	Sleep(1000);

	setcursortype(NORMALCURSOR);
}

void printMainMenu()
{
	printf("\n\n\t\t\t\t\t         Stock II - �ֽ� ���� 2");
	printf("\n\n\n\t\t\t\t\t    �׸��� ������ �ֽñ� �ٶ��ϴ�.");
	printf("\n\n\t\t\t\t\t        �� ���� �����ϱ� : 1��");
	printf("\n\n\t\t\t\t\t        ��  �� �� �� ��  : 2��");
	printf("\n\n\t\t\t\t\t        ��  ��       ��  : 3��");
}