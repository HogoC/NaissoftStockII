#include "GameFunctions.h"

int month, day, hour, achour;

int viewmode, timemode;

char *Tips[MAX_TIP] =
{
	"�ְ��� �� �� �ż��ϰ� ��� �� �ŵ��ؼ� ������ ������!",
	"������ ���� ���� ���� �Ǿ����!",
	"1�޸��� ������ ���ϴ�. ��� ��ٸ��ٰ� �Ļ��� �� ������ �����ϼ���!",
	"���� ȸ���� �ֽ��� �� �� �ֽ��ϴ�. ȸ�� ����� Ȯ���ϼ���!",
};

char *GoodNews[MAX_NEWS] =
{
	"�� �� ��ǰ, �α���� ��",
	"�� ������ �̲� �� CEO�� �濵ö��...",
	"�� �������� �� ����",
	", ȯ�� �޵����� �ְ� ����",
	"�� �ܱ����� ��Ը� ���ڷ� ȣ��",
};

char *BadNews[MAX_NEWS] =
{
	"�� �� ��ǰ �� ����... CEO ���� ����",
	", ���� �߼��δ� �����ϴ� - ������ �м�",
	"�� ����... �ñ��� ��å ���� �ʿ�",
	", ȯ���� ���� �ɰ��� ����",
	" �ֽ� ����.. �ܱ��� ��Ը� �ŵ��� �ְ� �޶�",
};

char *Infos[MAX_COMPANY] =
{
	" Naissoft�� ��Ī ���ѹα� �ִ� �Ը��� ����Ʈ���� ���� ��ü�Դϴ�.\n ��ƿ��Ƽ, ���� �� ���� ���� ���α׷����� �����ϰ� ����.",
	" �ޱ׸�����Ʈ����ʵ�� ���̽�����Ʈ�� �׻� �и��� ����� ����Ʈ���� ��ü�Դϴ�.\n �̸��� ����ϴٸ� �ޱ׸� ���� ���� �ʵ尡 �Ҽ��� �ɾ��ٴ� �ҹ��� �־��.",
	" �ϰܳ���� �������� �� ����� �̽��� �۹��� ������ �����ϰ� ��ǰ�� ����� ȸ���Դϴ�.\n Ư���� �̸��� ȸ�� �����ÿ� ������ ����.\n �ֱ��� ���� �� ��ⱸ�� �����ϰ� �ִ�ϴ�.",
	" MK Electronics�� ������ǰ ���� ȸ���Դϴ�.\n TV, PC, ����Ʈ��, ����� ���� ��������.",
	" ���뱺���� ���� ���� ���� ��ü�Դϴ�.\n �̸���� ��ź�� �ַ� �����ϴ� ȸ�翹��.",
	" CJ ���ϼտ���� �н�Ʈ Ǫ�� ��ü�Դϴ�.\n �տ���� ���� ��(��), ��ġ ��(��), �� ��(�) ��,\n �׻� �Դ� ��ġ�� �������� ���̶�� �ǹ̶��ϴ�.",
	" KJS �ý����� ���, ������ ����Ʈ��� �����ϴ� ȸ���Դϴ�.\n �ַ� ���� �ӽ�, ������ ���� ���� ������.",
	" Fruit�� ������ ����� ��� ȸ���Դϴ�.\n �º�, ����Ʈ��, ����Ʈ ��ġ ���� �����ϰ� �־��.\n Grand Theft Auto V�⿡ �⿬�� ���� �ִ�ϴ�.",
	" ������ ���ͽ��� �ڵ����� ����/�����ϴ� ��ü�Դϴ�.\n �������� ������ ���� ���̸�, ������ �ڵ��� ȸ���� ���� ���Դϴ�.",
	" ����������� ��߱׷� ������ �߰��� ȸ���, �踦 ����� ȸ����ϴ�.",
};

int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void init()
{
	Money = DEF_MONEY;
	for (int i = 0; i < MAX_COMPANY; i++) StockPrice[i] = 9000;
	for (int i = 0; i < MAX_COMPANY; i++) ifGood[i] = true;
	Stocks = StockDeal = 0;
	loanMoney = 0;
	ChangeStockPrice();
	hour++;
	viewmode = timemode = 0;
}

void ShowMain()
{
	gotoxy(0, 1);
	printf(" Stock II - Naissoft �ֽ� ����\n ver 1.0.developing\n\n B ���, S �ȱ�, V ���, E ����, I ȸ�� ����, Esc �޴�");
	if (timemode == 1) printf(" W ��ٸ���");
	gotoxy(0, 4);
	printf("\n ���� �� �� : %d��, ���ƾ� �� �� : %d��\n\n\n\n", Money, loanMoney);

	ShowStockPrice(viewmode);

	printf("\n %d�� %d�� %d��", month + 1, day + 1, hour);
	printf("\n\n �̹� ���� ������ %d���Դϴ�. %d�� ���ҽ��ϴ�.\n", (15000 + (Money / 100)), days[month] - day);
}

void load()
{
	int stocks = 0;
	Stock tmp;

	FILE *save = fopen("save.ns3", "rb");
	if (save == NULL)
	{
		init();
		return;
	}

	fscanf(save, "%d ", &stocks);
	stocks = _rotr(stocks, 1);

	for (int i = 0; i < stocks; i++)
	{
		now = head;

		fscanf(save, "%d %d ", &tmp.company, &tmp.price);
		tmp.company = _rotr(tmp.company, 1); tmp.price = _rotr(tmp.price, 1);
		InsertStock(now, &tmp);
	}

	for (int i = 0; i < MAX_COMPANY; i++)
	{
		fscanf(save, "%d ", &StockPrice[i]);
		StockPrice[i] = _rotr(StockPrice[i], 1);
	}

	for (int i = 0; i < MAX_COMPANY; i++)
	{
		fscanf(save, "%d ", &ifGood[i]);
		ifGood[i] = _rotr(ifGood[i], 1);
	}

	fscanf(save, "%d %d %d %d %d %d %d %d %d", &Money, &loanMoney, &Stocks, &StockDeal, &month, &day, &hour, &viewmode, &timemode);
	Money = _rotr(Money, 1); loanMoney = _rotr(loanMoney, 1); Stocks = _rotr(Stocks, 1);
	StockDeal = _rotr(StockDeal, 1); month = _rotr(month, 1); day = _rotr(day, 1); hour = _rotr(hour, 1);

	fclose(save);
}

void save()
{
	int stocks = 0;
	FILE *save = fopen("save.ns3", "wb");

	for (now = head->next; now; now = now->next) stocks++;
	fprintf(save, "%d ", _rotl(stocks, 1));

	for (now = head->next; now; now = now->next)
		fprintf(save, "%d %d ", _rotl(now->company, 1), _rotl(now->price, 1));

	for (int i = 0; i < MAX_COMPANY; i++)
		fprintf(save, "%d ", _rotl(StockPrice[i], 1));

	for (int i = 0; i < MAX_COMPANY; i++)
		fprintf(save, "%d ", _rotl(ifGood[i], 1));

	fprintf(save, "%d %d %d %d %d %d %d %d %d", _rotl(Money, 1), _rotl(loanMoney, 1), _rotl(Stocks, 1), _rotl(StockDeal, 1),
		_rotl(month, 1), _rotl(day, 1), _rotl(hour, 1), viewmode, timemode);

	fclose(save);
}

void showTipNews()
{
	gotoxy(0, 7);
	for (int i = 0; i < 80; i++) printf(" ");
	gotoxy(0, 7);
	if (rand() % 4 == 0)
		printf(" �� : %s", Tips[rand() % MAX_TIP]);
	else
	{
		int comp = rand() % MAX_COMPANY;
		if (ifGood[comp] == true) printf(" NEWS : %s%s", CompanyName[comp], GoodNews[rand() % MAX_NEWS]);
		else printf(" NEWS : %s%s", CompanyName[comp], BadNews[rand() % MAX_NEWS]);
	}
}

void buyMenu(int order)
{
	char ch;
	int amount;

	system("cls");
	titleLine("�ֽ� ���");

	printf(" ���� %s ȸ���� �ְ��� %d���Դϴ�.\n �� ���� �����Ͻðڽ��ϱ�?", CompanyName[order], StockPrice[order]);

	scanf("%d", &amount);
	if (amount > 0)
	{
		buyStock(order, amount);
		printf("\n\n �����Ͽ����ϴ�.");
		Sleep(2000);
	}
	system("cls");
	return;
}

void sellMenu()
{
	int i, j;
	i = 1;
	while (i != 0)
	{
		system("cls");
		titleLine("�ֽ� �ȱ�");
		printf("\n [ �� �ֽ��� ������ ]\n\n");
		j = 1;
		for (now = head->next; now; now = now->next)
		{
			printf("\n %d. ȸ�� : %-20s, ���� : %d��", j, CompanyName[now->company], now->price);
			j++;
		}
		printf("\n ���ư����� 0�� �����ϼ���.\n");
		scanf("%d", &i);
		if (i != 0) sellStock(i);
	}
	system("cls");
}

void showStats()
{
	system("cls");
	titleLine("��  ��");
	printf("\n �ֽ��� ��ų� �� Ƚ�� : %d\n ���� ���� �� : %d��\n �ֽ� ���� : %d\n\n ���ư����� Enter�� ��������.\n", StockDeal, Money, Stocks);
	getchar();
	system("cls");
}

void getKey(char *c)
{
	if (!timemode)
	{
		if (kbhit()) *c = getch();
	}
	else *c = getch();
}

void settingMenu()
{
	int select;
	system("cls");
	titleLine("��  ��");
	printf(" 1. ���� ��� ��ȯ\n 2. �ð� �帧 ��� ��ȯ\n Q ���ư���");
	scanf("%d", &select);

	switch (select)
	{
	case 1:
		viewmode++;
		if (viewmode > 2) viewmode = 0;
		switch (viewmode)
		{
		case 0:
			printf(" ���� ����� �⺻ ���� ��ȯ�Ǿ����ϴ�.");
			break;
		case 1:
			printf(" ���� ����� �������� ���� ��ȯ�Ǿ����ϴ�.");
			break;
		case 2:
			printf(" ���� ����� �������� ���� ��ȯ�Ǿ����ϴ�.");
			break;
		}
		break;
	case 2:
		timemode++;
		if (timemode > 1) timemode = 0;
		switch (timemode)
		{
		case 0:
			printf(" �ð� �帧�� �ڵ����� ��ȯ�Ǿ����ϴ�.");
			break;
		case 1:
			printf(" �ð� �帧�� �������� ��ȯ�Ǿ����ϴ�.");
			break;
		}
		break;
	default:
		break;
	}
	Sleep(300);
	system("cls");
	return;
}

void loanMenu()
{
	int loanmoney;

	system("cls");
	titleLine("��  ��");
	printf("\n �󸶸� ��������ðڽ��ϱ�?");
	scanf("%d", &loanmoney);
	loan(loanmoney);

	return;
}

void showCompanyInfo()
{
	int i = 0;
	char ch = '\0';

	system("cls");
	while (ch != 27)
	{
		system("cls");
		titleLine("ȸ�� ����");

		gotoxy(0, 5);
		printf(" %d / %d. W, S Ű�� �Ѱ� �� �� �ֽ��ϴ�.\n ȸ�� : %s\n\n", i + 1, MAX_COMPANY, CompanyName[i]);
		printf("%s", Infos[i]);

		ch = getch();

		switch (ch)
		{
		case 'W':
		case 'w':
			if (i < MAX_COMPANY - 1) i++;
			break;
		case 'S':
		case 's':
			if (i > 0) i--;
			break;
		}
	}
	system("cls");
}

void DrawGraph(int company)
{

	gotoxy(0, 25);
	printf(" 24000                                                                      \n 22000                                                                      \n 20000                                                                      "
		"\n 18000                                                                      \n 16000                                                                      \n 14000                                                                      "
		"\n 12000                                                                      \n 10000                                                                      \n  8000                                                                      "
		"\n  6000                                                                      \n  4000                                                                      \n  2000                                                                      \n");
	gotoxy(7, 46);

	int j = 0;
	for (int i = 47; i >= 0; i--)
	{
		if (GraphData[company][i] != 0)
		{
			gotoxy(7 + j, 36 - ((int)(GraphData[company][i] / 2000) - 1));
			printf("*");
			j++;
		}
	}
}