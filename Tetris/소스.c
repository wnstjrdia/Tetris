#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#define PAN_SIZE 20
#define PPAN_SIZE 10
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
void bolck();//ù��
void panprint();//���
void fpanin();//ù�� �Է�
void down();//��������
void pank();//���� 
void change();//���ٲ� 
void colorchange();//������ ���ٲ� 
void ranksave();//������ ���� 
void rankload();//������ �ҷ����� 
int end();//�� 
int pan[PAN_SIZE][PPAN_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int bolcknum, bolcknum2, num = 0;
int bolckck = 0;
int a[4][4];
int b[4][4];
int c[4][4];
int d[4][4];
COORD aa;
COORD bb;
COORD cc;
COORD dd;
int color, eend = 0, score = 0, speed = 1000, item;
int rankscore[7];
int name[7][3];
int tm[7];
void bolck() {
	srand((unsigned)time(NULL));
	item = (rand() % 7);
	if (item == 0) {
		gotoxy(30, 3);
		printf("��");
	}
	else {
		gotoxy(30, 3);
		printf("  ");
	}
	bolcknum = bolcknum2;//bolcknum2�� ���̸�����
	if (num = 0) {
		bolcknum = (rand() % 7);
		num = 1;
	}

	if (bolcknum == 0)//����//���������
	{//                 ����
		a[0][0] = 1;
		b[0][1] = 1;
		c[1][0] = 1;
		d[1][1] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		color = 2;
	}
	else if (bolcknum == 1)//��
	{//                      ��
		a[0][0] = 1;//         ��
		b[1][0] = 1;//         ��
		c[2][0] = 1;
		d[3][0] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		color = 3;
	}
	else if (bolcknum == 2)//����
	{//                        ����
		a[0][0] = 1;
		b[0][1] = 1;
		c[1][1] = 1;
		d[1][2] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		color = 4;
	}
	else if (bolcknum == 3)//����
	{//                    ����
		a[0][1] = 1;
		b[0][2] = 1;
		c[1][0] = 1;
		d[1][1] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		color = 5;
	}
	else if (bolcknum == 4)//��
	{//                      ������
		a[0][0] = 1;
		b[1][0] = 1;
		c[1][1] = 1;
		d[1][2] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		color = 6;
	}
	else if (bolcknum == 5)//��
	{//                  ������
		a[0][2] = 1;
		b[1][0] = 1;
		c[1][1] = 1;
		d[1][2] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		color = 7;
	}
	else if (bolcknum == 6)//��
	{//                    ������
		a[0][1] = 1;
		b[1][0] = 1;
		c[1][1] = 1;
		d[1][2] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		color = 8;
	}
	bolcknum2 = (rand() % 7);
	//�̸�����
	if (bolcknum2 == 0)//����
	{//                 ����
		gotoxy(30, 6);
		printf("  ");
		gotoxy(30, 7);
		printf("  ");
		gotoxy(32, 6);
		printf("  ");
		gotoxy(32, 7);
		printf("  ");
		gotoxy(34, 6);
		printf("  ");
		gotoxy(36, 6);
		printf("  ");
		gotoxy(30, 8);
		printf("  ");
		gotoxy(32, 8);
		printf("  ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		gotoxy(30, 6);
		printf("��");
		gotoxy(30, 7);
		printf("��");
		gotoxy(32, 6);
		printf("��");
		gotoxy(32, 7);
		printf("��");
	}
	else if (bolcknum2 == 1)//��
	{//                      ��
		gotoxy(30, 6);
		printf("  ");
		gotoxy(30, 7);
		printf("  ");
		gotoxy(32, 6);
		printf("  ");
		gotoxy(32, 7);
		printf("  ");
		gotoxy(34, 6);
		printf("  ");
		gotoxy(36, 6);
		printf("  ");
		gotoxy(30, 8);
		printf("  ");
		gotoxy(32, 8);
		printf("  ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		gotoxy(30, 6);
		printf("��");
		gotoxy(32, 6);
		printf("��");
		gotoxy(34, 6);
		printf("��");
		gotoxy(36, 6);
		printf("��");
	}
	else if (bolcknum2 == 2)//����
	{//                        ����
		gotoxy(30, 6);
		printf("  ");
		gotoxy(30, 7);
		printf("  ");
		gotoxy(32, 6);
		printf("  ");
		gotoxy(32, 7);
		printf("  ");
		gotoxy(34, 6);
		printf("  ");
		gotoxy(36, 6);
		printf("  ");
		gotoxy(30, 8);
		printf("  ");
		gotoxy(32, 8);
		printf("  ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		gotoxy(30, 6);
		printf("��");
		gotoxy(30, 7);
		printf("��");
		gotoxy(32, 7);
		printf("��");
		gotoxy(32, 8);
		printf("��");
	}
	else if (bolcknum2 == 3)//����
	{//                    ����
		gotoxy(30, 6);
		printf("  ");
		gotoxy(30, 7);
		printf("  ");
		gotoxy(32, 6);
		printf("  ");
		gotoxy(32, 7);
		printf("  ");
		gotoxy(34, 6);
		printf("  ");
		gotoxy(36, 6);
		printf("  ");
		gotoxy(30, 8);
		printf("  ");
		gotoxy(32, 8);
		printf("  ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		gotoxy(30, 7);
		printf("��");
		gotoxy(30, 8);
		printf("��");
		gotoxy(32, 6);
		printf("��");
		gotoxy(32, 7);
		printf("��");
	}
	else if (bolcknum2 == 4)//��
	{//                      ������
		gotoxy(30, 6);
		printf("  ");
		gotoxy(30, 7);
		printf("  ");
		gotoxy(32, 6);
		printf("  ");
		gotoxy(32, 7);
		printf("  ");
		gotoxy(34, 6);
		printf("  ");
		gotoxy(36, 6);
		printf("  ");
		gotoxy(30, 8);
		printf("  ");
		gotoxy(32, 8);
		printf("  ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		gotoxy(30, 6);
		printf("��");
		gotoxy(32, 6);
		printf("��");
		gotoxy(32, 7);
		printf("��");
		gotoxy(32, 8);
		printf("��");
	}
	else if (bolcknum2 == 5)//��
	{//                  ������
		gotoxy(30, 6);
		printf("  ");
		gotoxy(30, 7);
		printf("  ");
		gotoxy(32, 6);
		printf("  ");
		gotoxy(32, 7);
		printf("  ");
		gotoxy(34, 6);
		printf("  ");
		gotoxy(36, 6);
		printf("  ");
		gotoxy(30, 8);
		printf("  ");
		gotoxy(32, 8);
		printf("  ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		gotoxy(30, 8);
		printf("��");
		gotoxy(32, 6);
		printf("��");
		gotoxy(32, 7);
		printf("��");
		gotoxy(32, 8);
		printf("��");
	}
	else if (bolcknum2 == 6)//��
	{//                    ������
		gotoxy(30, 6);
		printf("  ");
		gotoxy(30, 7);
		printf("  ");
		gotoxy(32, 6);
		printf("  ");
		gotoxy(32, 7);
		printf("  ");
		gotoxy(34, 6);
		printf("  ");
		gotoxy(36, 6);
		printf("  ");
		gotoxy(30, 8);
		printf("  ");
		gotoxy(32, 8);
		printf("  ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		gotoxy(30, 7);
		printf("��");
		gotoxy(32, 6);
		printf("��");
		gotoxy(32, 7);
		printf("��");
		gotoxy(32, 8);
		printf("��");
	}
}
void panprint() {//ó�������
	int i, j;
	printf("�̢̢̢̢̢̢̢̢̢̢̢�\n");
	printf("�̢̢̢���Ʈ�����̢̢̢�\n");
	printf("�̢̢̢̢̢̢̢̢̢̢̢�\n");
	for (i = 0; i < PAN_SIZE; i++) {
		printf("��");
		for (j = 0; j < PPAN_SIZE; j++) {
			printf("  ");
		}
		printf("��\n");
	}
	printf("�̢̢̢̢̢̢̢̢̢̢̢�\n");
	gotoxy(30, 10);
	printf("���� : %d", score);
	gotoxy(40, 3);
	printf("������ ����:�ϸ鼭 ���� ��Ÿ����");
	gotoxy(40, 4);
	printf("              �����̽��ٸ� ������");
	gotoxy(40, 5);
	printf("              ������ �����ϰ� ");
	gotoxy(40, 6);
	printf("              ���� �Ʒ������� ������");
}
void fpanin() {//ó�� ���� ��ġ���
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (a[i][j] == 1) {
				aa.X = (j * 2) + 10;
				aa.Y = i + 3;
			}
			if (b[i][j] == 1) {
				bb.X = (j * 2) + 10;
				bb.Y = i + 3;
			}
			if (c[i][j] == 1) {
				cc.X = (j * 2) + 10;
				cc.Y = i + 3;
			}
			if (d[i][j] == 1) {
				dd.X = (j * 2) + 10;
				dd.Y = i + 3;
			}
		}
	}
}
void down() {
	int inkey1, inkey2;
	gotoxy(aa.X, aa.Y);//ù�����
	printf("��");
	gotoxy(bb.X, bb.Y);
	printf("��");
	gotoxy(cc.X, cc.Y);
	printf("��");
	gotoxy(dd.X, dd.Y);
	printf("��");
	clock_t t1, t2, t3;
	t1 = clock();
	for (;;) {
		t2 = clock();
		if ((t2 - t1) > speed) {//�ð��� ���� ������ speed�� ���������� ������
			gotoxy(aa.X, aa.Y);
			printf("  ");
			gotoxy(bb.X, bb.Y);
			printf("  ");
			gotoxy(cc.X, cc.Y);
			printf("  ");
			gotoxy(dd.X, dd.Y);
			printf("  ");
			aa.Y += 1;
			bb.Y += 1;
			cc.Y += 1;
			dd.Y += 1;
			gotoxy(aa.X, aa.Y);
			printf("��");
			gotoxy(bb.X, bb.Y);
			printf("��");
			gotoxy(cc.X, cc.Y);
			printf("��");
			gotoxy(dd.X, dd.Y);
			printf("��");
			t1 = t2;
		}
		if (_kbhit()) {
			inkey1 = _getch();
			if (inkey1 == 27) {//����
				eend = 1;
				break;
			}
			else if (inkey1 == 32) {//�����̽��� �ٷγ������°�
				for (;;) {
					if ((aa.Y > 21 || bb.Y > 21 || cc.Y > 21 || dd.Y > 21 ||
						pan[aa.Y - 2][(aa.X / 2) - 1] == 1 || pan[bb.Y - 2][(bb.X / 2) - 1] == 1 ||
						pan[cc.Y - 2][(cc.X / 2) - 1] == 1 || pan[dd.Y - 2][(dd.X / 2) - 1] == 1) &&
						item != 0) {
						break;
					}
					if ((aa.Y > 21 || bb.Y > 21 || cc.Y > 21 || dd.Y > 21) && item == 0) {//�������϶�
						break;
					}
					gotoxy(aa.X, aa.Y);
					printf("  ");
					gotoxy(bb.X, bb.Y);
					printf("  ");
					gotoxy(cc.X, cc.Y);
					printf("  ");
					gotoxy(dd.X, dd.Y);
					printf("  ");
					aa.Y += 1;
					bb.Y += 1;
					cc.Y += 1;
					dd.Y += 1;
					gotoxy(aa.X, aa.Y);
					printf("��");
					gotoxy(bb.X, bb.Y);
					printf("��");
					gotoxy(cc.X, cc.Y);
					printf("��");
					gotoxy(dd.X, dd.Y);
					printf("��");
				}
			}
			else if (inkey1 == 0x0 || inkey1 == 0xE0) {
				inkey2 = _getch();
				if (inkey2 == 75 && aa.X > 2 && bb.X > 2 && cc.X > 2 && dd.X > 2 &&//����Ű
					pan[aa.Y - 3][(aa.X / 2) - 2] != 1 &&
					pan[bb.Y - 3][(bb.X / 2) - 2] != 1 &&
					pan[cc.Y - 3][(cc.X / 2) - 2] != 1 &&
					pan[dd.Y - 3][(dd.X / 2) - 2] != 1) {
					gotoxy(aa.X, aa.Y);
					printf("  ");
					gotoxy(bb.X, bb.Y);
					printf("  ");
					gotoxy(cc.X, cc.Y);
					printf("  ");
					gotoxy(dd.X, dd.Y);
					printf("  ");
					aa.X -= 2;
					bb.X -= 2;
					cc.X -= 2;
					dd.X -= 2;
					gotoxy(aa.X, aa.Y);
					printf("��");
					gotoxy(bb.X, bb.Y);
					printf("��");
					gotoxy(cc.X, cc.Y);
					printf("��");
					gotoxy(dd.X, dd.Y);
					printf("��");
				}
				else if (inkey2 == 77 && aa.X < 20 && bb.X < 20 && cc.X < 20 && dd.X < 20 &&//������Ű
					pan[aa.Y - 3][(aa.X / 2) + 1] != 1 &&
					pan[bb.Y - 3][(bb.X / 2) + 1] != 1 &&
					pan[cc.Y - 3][(cc.X / 2) + 1] != 1 &&
					pan[dd.Y - 3][(dd.X / 2) + 1] != 1) {
					gotoxy(aa.X, aa.Y);
					printf("  ");
					gotoxy(bb.X, bb.Y);
					printf("  ");
					gotoxy(cc.X, cc.Y);
					printf("  ");
					gotoxy(dd.X, dd.Y);
					printf("  ");
					aa.X += 2;
					bb.X += 2;
					cc.X += 2;
					dd.X += 2;
					gotoxy(aa.X, aa.Y);
					printf("��");
					gotoxy(bb.X, bb.Y);
					printf("��");
					gotoxy(cc.X, cc.Y);
					printf("��");
					gotoxy(dd.X, dd.Y);
					printf("��");
				}
				else if (inkey2 == 80) {//�Ʒ�����Ű
					gotoxy(aa.X, aa.Y);
					printf("  ");
					gotoxy(bb.X, bb.Y);
					printf("  ");
					gotoxy(cc.X, cc.Y);
					printf("  ");
					gotoxy(dd.X, dd.Y);
					printf("  ");
					aa.Y += 1;
					bb.Y += 1;
					cc.Y += 1;
					dd.Y += 1;
					gotoxy(aa.X, aa.Y);
					printf("��");
					gotoxy(bb.X, bb.Y);
					printf("��");
					gotoxy(cc.X, cc.Y);
					printf("��");
					gotoxy(dd.X, dd.Y);
					printf("��");
				}
				else if (inkey2 == 72) {//���ʹ���Ű ���� ��纯��
					change();
				}
			}
		}
		if (aa.Y > 21 || bb.Y > 21 || cc.Y > 21 || dd.Y > 21 ||//�Ʒ����� ���� ��������
			pan[aa.Y - 2][(aa.X / 2) - 1] == 1 || pan[bb.Y - 2][(bb.X / 2) - 1] == 1 ||
			pan[cc.Y - 2][(cc.X / 2) - 1] == 1 || pan[dd.Y - 2][(dd.X / 2) - 1] == 1) {
			pan[aa.Y - 3][(aa.X / 2) - 1] = 1;
			pan[bb.Y - 3][(bb.X / 2) - 1] = 1;
			pan[cc.Y - 3][(cc.X / 2) - 1] = 1;
			pan[dd.Y - 3][(dd.X / 2) - 1] = 1;
			int i, j;
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					a[i][j] = 0;
					b[i][j] = 0;
					c[i][j] = 0;
					d[i][j] = 0;
				}
			}
			bolckck = 0;
			break;
		}
	}

}

void pank()
{
	int i, j, count = 0, linecount = 0, pankline = 0, ckcount = 0;
	for (i = 0; i < PAN_SIZE; i++) {
		for (j = 0; j < PPAN_SIZE; j++) {
			if (pan[i][j] == 1) {
				count++;//count�� ���ٿϼ�Ȯ��
			}
			if (linecount == 0)//linecount�� ���������� ����
			{
				pankline = i;//pankline�� ���������� ��ġ
			}
			if (count == 10) {
				ckcount = 1;//ckcount�� 1�̸� ����
				linecount++;
			}

		}
		count = 0;
		if (ckcount != 0)//ckcount�� 1�϶�
		{
			for (j = 0; j < PPAN_SIZE; j++)
			{
				pan[i][j] = 0;//���� ������ �����Ѵ�
				gotoxy((i * 2) + 10, j + 3);
				printf("  ");
			}
		}
		ckcount = 0;
	}
	i = 0;
	j = 0;

	if (linecount != 0) {//�����͵��� �ִٸ�
		for (i = (pankline - 1); i >= 0; i--) {//�������ο�������
			for (j = 0; j < PPAN_SIZE; j++) {
				if (pan[i][j] == 1) {
					gotoxy((j * 2) + 2, i + 3);//��� �Ʒ������� �������
					printf("  ");
					pan[i][j] = 0;

					gotoxy((j * 2) + 2, i + 3 + linecount);
					printf("��");
					pan[i + linecount][j] = 1;
				}
				else {
					gotoxy((j * 2) + 2, i + 3 + linecount);
					printf("  ");

				}
			}
		}

	}
	if (speed - linecount * 10 > 200) {//���ǵ����� 
		speed -= linecount * 10;
	}
	gotoxy(30, 10);
	score += linecount;
	printf("���� : %d", score);
	colorchange();
}

void change() {//���� ��纯ȯ
	if (bolcknum == 1 && bolckck == 0 && ((aa.Y + 1) < 21 && bb.Y < 21 && (cc.Y - 1) < 21 && (dd.Y - 2) < 21 &&
		pan[(aa.Y + 1) - 2][((aa.X - 2) / 2) - 1] != 1 && pan[bb.Y - 2][(bb.X / 2) - 1] != 1 &&
		pan[(cc.Y - 1) - 2][((cc.X + 2) / 2) - 1] != 1 && pan[(dd.Y - 2) - 2][((dd.X + 4) / 2) - 1] != 1) &&
		((aa.X - 2) > 0 && bb.X > 0 && (cc.X + 2) > 0 && (dd.X + 4) > 0 &&
			pan[(aa.Y + 1) - 3][((aa.X - 2) / 2) - 1] != 1 &&
			pan[bb.Y - 3][(bb.X / 2) - 1] != 1 &&
			pan[(cc.Y - 1) - 3][((cc.X + 2) / 2) - 1] != 1 &&
			pan[(dd.Y - 2) - 3][((dd.X + 4) / 2) - 1] != 1) &&
		((aa.X - 2) < 22 && bb.X < 22 && (cc.X + 2) < 22 && (dd.X + 4) < 22 &&
			pan[(aa.Y + 1) - 3][((aa.X - 2) / 2) + 1] != 1 &&
			pan[bb.Y - 3][(bb.X / 2) + 1] != 1 &&
			pan[(cc.Y - 1) - 3][((cc.X + 2) / 2) + 1] != 1 &&
			pan[(dd.Y - 2) - 3][((dd.X + 4) / 2) + 1] != 1)) {
		gotoxy(aa.X, aa.Y);
		printf("  ");
		gotoxy(bb.X, bb.Y);
		printf("  ");
		gotoxy(cc.X, cc.Y);
		printf("  ");
		gotoxy(dd.X, dd.Y);
		printf("  ");
		aa.X -= 2;
		aa.Y += 1;
		cc.X += 2;
		cc.Y -= 1;
		dd.X += 4;
		dd.Y -= 2;
		gotoxy(aa.X, aa.Y);
		printf("��");
		gotoxy(bb.X, bb.Y);
		printf("��");
		gotoxy(cc.X, cc.Y);
		printf("��");
		gotoxy(dd.X, dd.Y);
		printf("��");
		bolckck = 1;
	}
	else if (bolcknum == 1 && bolckck == 1 && ((aa.Y - 1) < 21 && bb.Y < 21 && (cc.Y + 1) < 21 && (dd.Y + 2) < 21 &&
		pan[(aa.Y - 1) - 2][((aa.X + 2) / 2) - 1] != 1 && pan[bb.Y - 2][(bb.X / 2) - 1] != 1 &&
		pan[(cc.Y + 1) - 2][((cc.X - 2) / 2) - 1] != 1 && pan[(dd.Y + 2) - 2][((dd.X - 4) / 2) - 1] != 1) &&
		((aa.X + 2) > 0 && bb.X > 0 && (cc.X - 2) > 0 && (dd.X - 4) > 0 &&
			pan[(aa.Y - 1) - 3][((aa.X + 2) / 2) - 1] != 1 &&
			pan[bb.Y - 3][(bb.X / 2) - 1] != 1 &&
			pan[(cc.Y + 1) - 3][((cc.X - 2) / 2) - 1] != 1 &&
			pan[(dd.Y + 2) - 3][((dd.X - 4) / 2) - 1] != 1) &&
		((aa.X + 2) < 22 && bb.X < 22 && (cc.X - 2) < 22 && (dd.X - 4) < 22 &&
			pan[(aa.Y - 1) - 3][((aa.X + 2) / 2) + 1] != 1 &&
			pan[bb.Y - 3][(bb.X / 2) + 1] != 1 &&
			pan[(cc.Y + 1) - 3][((cc.X - 2) / 2) + 1] != 1 &&
			pan[(dd.Y + 2) - 3][((dd.X - 4) / 2) + 1] != 1)) {
		gotoxy(aa.X, aa.Y);
		printf("  ");
		gotoxy(bb.X, bb.Y);
		printf("  ");
		gotoxy(cc.X, cc.Y);
		printf("  ");
		gotoxy(dd.X, dd.Y);
		printf("  ");
		aa.X += 2;
		aa.Y -= 1;
		cc.X -= 2;
		cc.Y += 1;
		dd.X -= 4;
		dd.Y += 2;
		gotoxy(aa.X, aa.Y);
		printf("��");
		gotoxy(bb.X, bb.Y);
		printf("��");
		gotoxy(cc.X, cc.Y);
		printf("��");
		gotoxy(dd.X, dd.Y);
		printf("��");
		bolckck = 0;
	}//////////////////////////////////////////
	else if (bolcknum == 2 && bolckck == 0 && ((aa.Y + 2) < 21 && (bb.Y + 1) < 21 && (cc.Y) < 21 && (dd.Y - 1) < 21 &&
		pan[(aa.Y + 2) - 2][((aa.X - 2) / 2) - 1] != 1 && pan[(bb.Y + 1) - 2][((bb.X - 2) / 2) - 1] != 1 &&//
		pan[(cc.Y) - 2][((cc.X) / 2) - 1] != 1 && pan[(dd.Y - 1) - 2][((dd.X - 2) / 2) - 1] != 1) &&
		((aa.X) > 0 && (bb.X - 2) > 0 && (cc.X) > 0 && (dd.X - 2) > 0 &&
			pan[(aa.Y + 2) - 3][((aa.X) / 2) - 1] != 1 &&
			pan[(bb.Y + 1) - 3][((bb.X - 2) / 2) - 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) - 1] != 1 &&
			pan[(dd.Y - 1) - 3][((dd.X - 2) / 2) - 1] != 1) &&
		((aa.X) < 22 && (bb.X - 2) < 22 && (cc.X) < 22 && (dd.X - 2) < 22 &&
			pan[(aa.Y + 2) - 3][((aa.X) / 2) + 1] != 1 &&
			pan[(bb.Y + 1) - 3][((bb.X - 2) / 2) + 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) + 1] != 1 &&
			pan[(dd.Y - 1) - 3][((dd.X - 2) / 2) + 1] != 1)) {
		gotoxy(aa.X, aa.Y);
		printf("  ");
		gotoxy(bb.X, bb.Y);
		printf("  ");
		gotoxy(cc.X, cc.Y);
		printf("  ");
		gotoxy(dd.X, dd.Y);
		printf("  ");
		aa.Y += 2;
		bb.X -= 2;
		bb.Y += 1;
		dd.X -= 2;
		dd.Y -= 1;
		gotoxy(aa.X, aa.Y);
		printf("��");
		gotoxy(bb.X, bb.Y);
		printf("��");
		gotoxy(cc.X, cc.Y);
		printf("��");
		gotoxy(dd.X, dd.Y);
		printf("��");
		bolckck = 1;
	}
	else if (bolcknum == 2 && bolckck == 1 && ((aa.Y - 2) < 21 && (bb.Y - 1) < 21 && (cc.Y) < 21 && (dd.Y + 1) < 21 &&
		pan[(aa.Y - 2) - 2][((aa.X + 2) / 2) - 1] != 1 && pan[(bb.Y - 1) - 2][((bb.X + 2) / 2) - 1] != 1 &&//
		pan[(cc.Y) - 2][((cc.X) / 2) - 1] != 1 && pan[(dd.Y + 1) - 2][((dd.X + 2) / 2) - 1] != 1) &&
		((aa.X) > 0 && (bb.X + 2) > 0 && (cc.X) > 0 && (dd.X + 2) > 0 &&
			pan[(aa.Y - 2) - 3][((aa.X) / 2) - 1] != 1 &&
			pan[(bb.Y - 1) - 3][((bb.X + 2) / 2) - 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) - 1] != 1 &&
			pan[(dd.Y + 1) - 3][((dd.X + 2) / 2) - 1] != 1) &&
		((aa.X) < 22 && (bb.X + 2) < 22 && (cc.X) < 22 && (dd.X + 2) < 22 &&
			pan[(aa.Y - 2) - 3][((aa.X) / 2) + 1] != 1 &&
			pan[(bb.Y - 1) - 3][((bb.X + 2) / 2) + 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) + 1] != 1 &&
			pan[(dd.Y + 1) - 3][((dd.X + 2) / 2) + 1] != 1)) {
		gotoxy(aa.X, aa.Y);
		printf("  ");
		gotoxy(bb.X, bb.Y);
		printf("  ");
		gotoxy(cc.X, cc.Y);
		printf("  ");
		gotoxy(dd.X, dd.Y);
		printf("  ");
		aa.Y -= 2;
		bb.X += 2;
		bb.Y -= 1;
		dd.X += 2;
		dd.Y += 1;
		gotoxy(aa.X, aa.Y);
		printf("��");
		gotoxy(bb.X, bb.Y);
		printf("��");
		gotoxy(cc.X, cc.Y);
		printf("��");
		gotoxy(dd.X, dd.Y);
		printf("��");
		bolckck = 0;
	}/////////////////////////////////////////
	else if (bolcknum == 3 && bolckck == 0 && ((aa.Y + 1) < 21 && (bb.Y + 2) < 21 && (cc.Y - 1) < 21 && (dd.Y) < 21 &&
		pan[(aa.Y + 1) - 2][((aa.X + 2) / 2) - 1] != 1 && pan[(bb.Y + 2) - 2][((bb.X) / 2) - 1] != 1 &&//
		pan[(cc.Y - 1) - 2][((cc.X + 2) / 2) - 1] != 1 && pan[(dd.Y) - 2][((dd.X) / 2) - 1] != 1) &&
		((aa.X + 2) > 0 && (bb.X) > 0 && (cc.X + 2) > 0 && (dd.X) > 0 &&
			pan[(aa.Y + 1) - 3][((aa.X + 2) / 2) - 1] != 1 &&
			pan[(bb.Y + 2) - 3][((bb.X) / 2) - 1] != 1 &&
			pan[(cc.Y - 1) - 3][((cc.X + 2) / 2) - 1] != 1 &&
			pan[(dd.Y) - 3][((dd.X) / 2) - 1] != 1) &&
		((aa.X + 2) < 22 && (bb.X) < 22 && (cc.X + 2) < 22 && (dd.X) < 22 &&
			pan[(aa.Y + 1) - 3][((aa.X + 2) / 2) + 1] != 1 &&
			pan[(bb.Y + 2) - 3][((bb.X) / 2) + 1] != 1 &&
			pan[(cc.Y - 1) - 3][((cc.X + 2) / 2) + 1] != 1 &&
			pan[(dd.Y) - 3][((dd.X) / 2) + 1] != 1)) {
		gotoxy(aa.X, aa.Y);
		printf("  ");
		gotoxy(bb.X, bb.Y);
		printf("  ");
		gotoxy(cc.X, cc.Y);
		printf("  ");
		gotoxy(dd.X, dd.Y);
		printf("  ");
		aa.X += 2;
		aa.Y += 1;
		bb.Y += 2;
		cc.X += 2;
		cc.Y -= 1;
		gotoxy(aa.X, aa.Y);
		printf("��");
		gotoxy(bb.X, bb.Y);
		printf("��");
		gotoxy(cc.X, cc.Y);
		printf("��");
		gotoxy(dd.X, dd.Y);
		printf("��");
		bolckck = 1;
	}
	else if (bolcknum == 3 && bolckck == 1 && ((aa.Y - 1) < 21 && (bb.Y - 2) < 21 && (cc.Y + 1) < 21 && (dd.Y) < 21 &&
		pan[(aa.Y - 1) - 2][((aa.X - 2) / 2) - 1] != 1 && pan[(bb.Y - 2) - 2][((bb.X) / 2) - 1] != 1 &&//
		pan[(cc.Y + 1) - 2][((cc.X - 2) / 2) - 1] != 1 && pan[(dd.Y) - 2][((dd.X) / 2) - 1] != 1) &&
		((aa.X - 2) > 0 && (bb.X) > 0 && (cc.X - 2) > 0 && (dd.X) > 0 &&
			pan[(aa.Y - 1) - 3][((aa.X - 2) / 2) - 1] != 1 &&
			pan[(bb.Y - 2) - 3][((bb.X) / 2) - 1] != 1 &&
			pan[(cc.Y + 1) - 3][((cc.X - 2) / 2) - 1] != 1 &&
			pan[(dd.Y) - 3][((dd.X) / 2) - 1] != 1) &&
		((aa.X - 2) < 22 && (bb.X) < 22 && (cc.X - 2) < 22 && (dd.X) < 22 &&
			pan[(aa.Y - 1) - 3][((aa.X - 2) / 2) + 1] != 1 &&
			pan[(bb.Y - 2) - 3][((bb.X) / 2) + 1] != 1 &&
			pan[(cc.Y + 1) - 3][((cc.X - 2) / 2) + 1] != 1 &&
			pan[(dd.Y) - 3][((dd.X) / 2) + 1] != 1)) {
		gotoxy(aa.X, aa.Y);
		printf("  ");
		gotoxy(bb.X, bb.Y);
		printf("  ");
		gotoxy(cc.X, cc.Y);
		printf("  ");
		gotoxy(dd.X, dd.Y);
		printf("  ");
		aa.X -= 2;
		aa.Y -= 1;
		bb.Y -= 2;
		cc.X -= 2;
		cc.Y += 1;
		gotoxy(aa.X, aa.Y);
		printf("��");
		gotoxy(bb.X, bb.Y);
		printf("��");
		gotoxy(cc.X, cc.Y);
		printf("��");
		gotoxy(dd.X, dd.Y);
		printf("��");
		bolckck = 0;
	}////////////////////////////////
	else if (bolcknum == 4 && bolckck == 0 && ((aa.Y) < 21 && (bb.Y - 1) < 21 && (cc.Y) < 21 && (dd.Y + 1) < 21 &&
		pan[(aa.Y) - 2][((aa.X + 4) / 2) - 1] != 1 && pan[(bb.Y - 1) - 2][((bb.X + 2) / 2) - 1] != 1 &&//
		pan[(cc.Y) - 2][((cc.X) / 2) - 1] != 1 && pan[(dd.Y + 1) - 2][((dd.X - 2) / 2) - 1] != 1) &&
		((aa.X + 4) > 0 && (bb.X + 2) > 0 && (cc.X) > 0 && (dd.X - 2) > 0 &&
			pan[(aa.Y) - 3][((aa.X + 4) / 2) - 1] != 1 &&
			pan[(bb.Y - 1) - 3][((bb.X + 2) / 2) - 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) - 1] != 1 &&
			pan[(dd.Y + 1) - 3][((dd.X - 2) / 2) - 1] != 1) &&
		((aa.X + 4) < 22 && (bb.X + 2) < 22 && (cc.X) < 22 && (dd.X - 2) < 22 &&
			pan[(aa.Y) - 3][((aa.X + 4) / 2) + 1] != 1 &&
			pan[(bb.Y - 1) - 3][((bb.X + 2) / 2) + 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) + 1] != 1 &&
			pan[(dd.Y + 1) - 3][((dd.X - 2) / 2) + 1] != 1)) {
		gotoxy(aa.X, aa.Y);
		printf("  ");
		gotoxy(bb.X, bb.Y);
		printf("  ");
		gotoxy(cc.X, cc.Y);
		printf("  ");
		gotoxy(dd.X, dd.Y);
		printf("  ");
		aa.X += 4;
		bb.X += 2;
		bb.Y -= 1;
		dd.X -= 2;
		dd.Y += 1;
		gotoxy(aa.X, aa.Y);
		printf("��");
		gotoxy(bb.X, bb.Y);
		printf("��");
		gotoxy(cc.X, cc.Y);
		printf("��");
		gotoxy(dd.X, dd.Y);
		printf("��");
		bolckck = 1;
	}
	else if (bolcknum == 4 && bolckck == 1 && ((aa.Y + 2) < 21 && (bb.Y + 1) < 21 && (cc.Y) < 21 && (dd.Y - 1) < 21 &&
		pan[(aa.Y + 2) - 2][((aa.X) / 2) - 1] != 1 && pan[(bb.Y + 1) - 2][((bb.X + 2) / 2) - 1] != 1 &&//
		pan[(cc.Y) - 2][((cc.X) / 2) - 1] != 1 && pan[(dd.Y - 1) - 2][((dd.X - 2) / 2) - 1] != 1) &&
		((aa.X) > 0 && (bb.X + 2) > 0 && (cc.X) > 0 && (dd.X - 2) > 0 &&
			pan[(aa.Y + 2) - 3][((aa.X) / 2) - 1] != 1 &&
			pan[(bb.Y + 1) - 3][((bb.X + 2) / 2) - 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) - 1] != 1 &&
			pan[(dd.Y - 1) - 3][((dd.X - 2) / 2) - 1] != 1) &&
		((aa.X) < 22 && (bb.X + 2) < 22 && (cc.X) < 22 && (dd.X - 2) < 22 &&
			pan[(aa.Y + 2) - 3][((aa.X) / 2) + 1] != 1 &&
			pan[(bb.Y + 1) - 3][((bb.X + 2) / 2) + 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) + 1] != 1 &&
			pan[(dd.Y - 1) - 3][((dd.X - 2) / 2) + 1] != 1)) {
		gotoxy(aa.X, aa.Y);
		printf("  ");
		gotoxy(bb.X, bb.Y);
		printf("  ");
		gotoxy(cc.X, cc.Y);
		printf("  ");
		gotoxy(dd.X, dd.Y);
		printf("  ");
		aa.Y += 2;
		bb.X += 2;
		bb.Y += 1;
		dd.X -= 2;
		dd.Y -= 1;
		gotoxy(aa.X, aa.Y);
		printf("��");
		gotoxy(bb.X, bb.Y);
		printf("��");
		gotoxy(cc.X, cc.Y);
		printf("��");
		gotoxy(dd.X, dd.Y);
		printf("��");
		bolckck = 2;
	}
	else if (bolcknum == 4 && bolckck == 2 && ((aa.Y) < 21 && (bb.Y + 1) < 21 && (cc.Y) < 21 && (dd.Y - 1) < 21 &&
		pan[(aa.Y) - 2][((aa.X - 4) / 2) - 1] != 1 && pan[(bb.Y + 1) - 2][((bb.X - 2) / 2) - 1] != 1 &&//
		pan[(cc.Y) - 2][((cc.X) / 2) - 1] != 1 && pan[(dd.Y - 1) - 2][((dd.X + 2) / 2) - 1] != 1) &&
		((aa.X - 4) > 0 && (bb.X - 2) > 0 && (cc.X) > 0 && (dd.X + 2) > 0 &&
			pan[(aa.Y) - 3][((aa.X - 4) / 2) - 1] != 1 &&
			pan[(bb.Y + 1) - 3][((bb.X - 2) / 2) - 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) - 1] != 1 &&
			pan[(dd.Y - 1) - 3][((dd.X + 2) / 2) - 1] != 1) &&
		((aa.X - 4) < 22 && (bb.X - 2) < 22 && (cc.X) < 22 && (dd.X + 2) < 22 &&
			pan[(aa.Y) - 3][((aa.X - 4) / 2) + 1] != 1 &&
			pan[(bb.Y + 1) - 3][((bb.X - 2) / 2) + 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) + 1] != 1 &&
			pan[(dd.Y - 1) - 3][((dd.X + 2) / 2) + 1] != 1)) {
		gotoxy(aa.X, aa.Y);
		printf("  ");
		gotoxy(bb.X, bb.Y);
		printf("  ");
		gotoxy(cc.X, cc.Y);
		printf("  ");
		gotoxy(dd.X, dd.Y);
		printf("  ");
		aa.X -= 4;
		bb.X -= 2;
		bb.Y += 1;
		dd.X += 2;
		dd.Y -= 1;
		gotoxy(aa.X, aa.Y);
		printf("��");
		gotoxy(bb.X, bb.Y);
		printf("��");
		gotoxy(cc.X, cc.Y);
		printf("��");
		gotoxy(dd.X, dd.Y);
		printf("��");
		bolckck = 3;
	}
	else if (bolcknum == 4 && bolckck == 3 && ((aa.Y - 2) < 21 && (bb.Y - 1) < 21 && (cc.Y) < 21 && (dd.Y + 1) < 21 &&
		pan[(aa.Y - 2) - 2][((aa.X) / 2) - 1] != 1 && pan[(bb.Y - 1) - 2][((bb.X - 2) / 2) - 1] != 1 &&//
		pan[(cc.Y) - 2][((cc.X) / 2) - 1] != 1 && pan[(dd.Y + 1) - 2][((dd.X + 2) / 2) - 1] != 1) &&
		((aa.X) > 0 && (bb.X - 2) > 0 && (cc.X) > 0 && (dd.X + 2) > 0 &&
			pan[(aa.Y - 2) - 3][((aa.X) / 2) - 1] != 1 &&
			pan[(bb.Y - 1) - 3][((bb.X - 2) / 2) - 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) - 1] != 1 &&
			pan[(dd.Y + 1) - 3][((dd.X + 2) / 2) - 1] != 1) &&
		((aa.X) < 22 && (bb.X - 2) < 22 && (cc.X) < 22 && (dd.X + 2) < 22 &&
			pan[(aa.Y - 2) - 3][((aa.X) / 2) + 1] != 1 &&
			pan[(bb.Y - 1) - 3][((bb.X - 2) / 2) + 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) + 1] != 1 &&
			pan[(dd.Y + 1) - 3][((dd.X + 2) / 2) + 1] != 1)) {
		gotoxy(aa.X, aa.Y);
		printf("  ");
		gotoxy(bb.X, bb.Y);
		printf("  ");
		gotoxy(cc.X, cc.Y);
		printf("  ");
		gotoxy(dd.X, dd.Y);
		printf("  ");
		aa.Y -= 2;
		bb.X -= 2;
		bb.Y -= 1;
		dd.X += 2;
		dd.Y += 1;
		gotoxy(aa.X, aa.Y);
		printf("��");
		gotoxy(bb.X, bb.Y);
		printf("��");
		gotoxy(cc.X, cc.Y);
		printf("��");
		gotoxy(dd.X, dd.Y);
		printf("��");
		bolckck = 0;
	}/////////////////////////////////////////////////////////////
	else if (bolcknum == 5 && bolckck == 0 && ((aa.Y + 2) < 21 && (bb.Y - 1) < 21 && (cc.Y) < 21 && (dd.Y + 1) < 21 &&
		pan[(aa.Y + 2) - 2][((aa.X) / 2) - 1] != 1 && pan[(bb.Y - 1) - 2][((bb.X + 2) / 2) - 1] != 1 &&//
		pan[(cc.Y) - 2][((cc.X) / 2) - 1] != 1 && pan[(dd.Y + 1) - 2][((dd.X - 2) / 2) - 1] != 1) &&
		((aa.X) > 0 && (bb.X + 2) > 0 && (cc.X) > 0 && (dd.X - 2) > 0 &&
			pan[(aa.Y + 2) - 3][((aa.X) / 2) - 1] != 1 &&
			pan[(bb.Y - 1) - 3][((bb.X + 2) / 2) - 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) - 1] != 1 &&
			pan[(dd.Y + 1) - 3][((dd.X - 2) / 2) - 1] != 1) &&
		((aa.X) < 22 && (bb.X + 2) < 22 && (cc.X) < 22 && (dd.X - 2) < 22 &&
			pan[(aa.Y + 2) - 3][((aa.X) / 2) + 1] != 1 &&
			pan[(bb.Y - 1) - 3][((bb.X + 2) / 2) + 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) + 1] != 1 &&
			pan[(dd.Y + 1) - 3][((dd.X - 2) / 2) + 1] != 1)) {
		gotoxy(aa.X, aa.Y);
		printf("  ");
		gotoxy(bb.X, bb.Y);
		printf("  ");
		gotoxy(cc.X, cc.Y);
		printf("  ");
		gotoxy(dd.X, dd.Y);
		printf("  ");
		aa.Y += 2;
		bb.X += 2;
		bb.Y -= 1;
		dd.X -= 2;
		dd.Y += 1;
		gotoxy(aa.X, aa.Y);
		printf("��");
		gotoxy(bb.X, bb.Y);
		printf("��");
		gotoxy(cc.X, cc.Y);
		printf("��");
		gotoxy(dd.X, dd.Y);
		printf("��");
		bolckck = 1;
	}
	else if (bolcknum == 5 && bolckck == 1 && ((aa.Y) < 21 && (bb.Y + 1) < 21 && (cc.Y) < 21 && (dd.Y - 1) < 21 &&
		pan[(aa.Y) - 2][((aa.X - 4) / 2) - 1] != 1 && pan[(bb.Y + 1) - 2][((bb.X + 2) / 2) - 1] != 1 &&//
		pan[(cc.Y) - 2][((cc.X) / 2) - 1] != 1 && pan[(dd.Y - 1) - 2][((dd.X - 2) / 2) - 1] != 1) &&
		((aa.X - 4) > 0 && (bb.X + 2) > 0 && (cc.X) > 0 && (dd.X - 2) > 0 &&
			pan[(aa.Y) - 3][((aa.X - 4) / 2) - 1] != 1 &&
			pan[(bb.Y + 1) - 3][((bb.X + 2) / 2) - 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) - 1] != 1 &&
			pan[(dd.Y - 1) - 3][((dd.X - 2) / 2) - 1] != 1) &&
		((aa.X - 4) < 22 && (bb.X + 2) < 22 && (cc.X) < 22 && (dd.X - 2) < 22 &&
			pan[(aa.Y) - 3][((aa.X - 4) / 2) + 1] != 1 &&
			pan[(bb.Y + 1) - 3][((bb.X + 2) / 2) + 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) + 1] != 1 &&
			pan[(dd.Y - 1) - 3][((dd.X - 2) / 2) + 1] != 1)) {
		gotoxy(aa.X, aa.Y);
		printf("  ");
		gotoxy(bb.X, bb.Y);
		printf("  ");
		gotoxy(cc.X, cc.Y);
		printf("  ");
		gotoxy(dd.X, dd.Y);
		printf("  ");
		aa.X -= 4;
		bb.X += 2;
		bb.Y += 1;
		dd.X -= 2;
		dd.Y -= 1;
		gotoxy(aa.X, aa.Y);
		printf("��");
		gotoxy(bb.X, bb.Y);
		printf("��");
		gotoxy(cc.X, cc.Y);
		printf("��");
		gotoxy(dd.X, dd.Y);
		printf("��");
		bolckck = 2;
	}
	else if (bolcknum == 5 && bolckck == 2 && ((aa.Y - 2) < 21 && (bb.Y + 1) < 21 && (cc.Y) < 21 && (dd.Y - 1) < 21 &&
		pan[(aa.Y - 2) - 2][((aa.X) / 2) - 1] != 1 && pan[(bb.Y + 1) - 2][((bb.X - 2) / 2) - 1] != 1 &&//
		pan[(cc.Y) - 2][((cc.X) / 2) - 1] != 1 && pan[(dd.Y - 1) - 2][((dd.X + 2) / 2) - 1] != 1) &&
		((aa.X) > 0 && (bb.X - 2) > 0 && (cc.X) > 0 && (dd.X + 2) > 0 &&
			pan[(aa.Y - 2) - 3][((aa.X) / 2) - 1] != 1 &&
			pan[(bb.Y + 1) - 3][((bb.X - 2) / 2) - 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) - 1] != 1 &&
			pan[(dd.Y - 1) - 3][((dd.X + 2) / 2) - 1] != 1) &&
		((aa.X) < 22 && (bb.X - 2) < 22 && (cc.X) < 22 && (dd.X + 2) < 22 &&
			pan[(aa.Y - 2) - 3][((aa.X) / 2) + 1] != 1 &&
			pan[(bb.Y + 1) - 3][((bb.X - 2) / 2) + 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) + 1] != 1 &&
			pan[(dd.Y - 1) - 3][((dd.X + 2) / 2) + 1] != 1)) {
		gotoxy(aa.X, aa.Y);
		printf("  ");
		gotoxy(bb.X, bb.Y);
		printf("  ");
		gotoxy(cc.X, cc.Y);
		printf("  ");
		gotoxy(dd.X, dd.Y);
		printf("  ");
		aa.Y -= 2;
		bb.X -= 2;
		bb.Y += 1;
		dd.X += 2;
		dd.Y -= 1;
		gotoxy(aa.X, aa.Y);
		printf("��");
		gotoxy(bb.X, bb.Y);
		printf("��");
		gotoxy(cc.X, cc.Y);
		printf("��");
		gotoxy(dd.X, dd.Y);
		printf("��");
		bolckck = 3;
	}
	else if (bolcknum == 5 && bolckck == 3 && ((aa.Y) < 21 && (bb.Y - 1) < 21 && (cc.Y) < 21 && (dd.Y + 1) < 21 &&
		pan[(aa.Y) - 2][((aa.X + 4) / 2) - 1] != 1 && pan[(bb.Y - 1) - 2][((bb.X - 2) / 2) - 1] != 1 &&//
		pan[(cc.Y) - 2][((cc.X) / 2) - 1] != 1 && pan[(dd.Y + 1) - 2][((dd.X + 2) / 2) - 1] != 1) &&
		((aa.X + 4) > 0 && (bb.X - 2) > 0 && (cc.X) > 0 && (dd.X + 2) > 0 &&
			pan[(aa.Y) - 3][((aa.X + 4) / 2) - 1] != 1 &&
			pan[(bb.Y - 1) - 3][((bb.X - 2) / 2) - 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) - 1] != 1 &&
			pan[(dd.Y + 1) - 3][((dd.X + 2) / 2) - 1] != 1) &&
		((aa.X + 4) < 22 && (bb.X - 2) < 22 && (cc.X) < 22 && (dd.X + 2) < 22 &&
			pan[(aa.Y) - 3][((aa.X + 4) / 2) + 1] != 1 &&
			pan[(bb.Y - 1) - 3][((bb.X - 2) / 2) + 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) + 1] != 1 &&
			pan[(dd.Y + 1) - 3][((dd.X + 2) / 2) + 1] != 1)) {
		gotoxy(aa.X, aa.Y);
		printf("  ");
		gotoxy(bb.X, bb.Y);
		printf("  ");
		gotoxy(cc.X, cc.Y);
		printf("  ");
		gotoxy(dd.X, dd.Y);
		printf("  ");
		aa.X += 4;
		bb.X -= 2;
		bb.Y -= 1;
		dd.X += 2;
		dd.Y += 1;
		gotoxy(aa.X, aa.Y);
		printf("��");
		gotoxy(bb.X, bb.Y);
		printf("��");
		gotoxy(cc.X, cc.Y);
		printf("��");
		gotoxy(dd.X, dd.Y);
		printf("��");
		bolckck = 0;
	}////////////////////////////////////////////////
	else if (bolcknum == 6 && bolckck == 0 && ((aa.Y + 1) < 21 && (bb.Y - 1) < 21 && (cc.Y) < 21 && (dd.Y + 1) < 21 &&
		pan[(aa.Y + 1) - 2][((aa.X + 2) / 2) - 1] != 1 && pan[(bb.Y - 1) - 2][((bb.X + 2) / 2) - 1] != 1 &&//
		pan[(cc.Y) - 2][((cc.X) / 2) - 1] != 1 && pan[(dd.Y + 1) - 2][((dd.X - 2) / 2) - 1] != 1) &&
		((aa.X + 2) > 0 && (bb.X + 2) > 0 && (cc.X) > 0 && (dd.X - 2) > 0 &&
			pan[(aa.Y + 1) - 3][((aa.X + 2) / 2) - 1] != 1 &&
			pan[(bb.Y - 1) - 3][((bb.X + 2) / 2) - 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) - 1] != 1 &&
			pan[(dd.Y + 1) - 3][((dd.X - 2) / 2) - 1] != 1) &&
		((aa.X + 2) < 22 && (bb.X + 2) < 22 && (cc.X) < 22 && (dd.X - 2) < 22 &&
			pan[(aa.Y + 1) - 3][((aa.X + 2) / 2) + 1] != 1 &&
			pan[(bb.Y - 1) - 3][((bb.X + 2) / 2) + 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) + 1] != 1 &&
			pan[(dd.Y + 1) - 3][((dd.X - 2) / 2) + 1] != 1)) {
		gotoxy(aa.X, aa.Y);
		printf("  ");
		gotoxy(bb.X, bb.Y);
		printf("  ");
		gotoxy(cc.X, cc.Y);
		printf("  ");
		gotoxy(dd.X, dd.Y);
		printf("  ");
		aa.X += 2;
		aa.Y += 1;
		bb.X += 2;
		bb.Y -= 1;
		dd.X -= 2;
		dd.Y += 1;
		gotoxy(aa.X, aa.Y);
		printf("��");
		gotoxy(bb.X, bb.Y);
		printf("��");
		gotoxy(cc.X, cc.Y);
		printf("��");
		gotoxy(dd.X, dd.Y);
		printf("��");
		bolckck = 1;
	}
	else if (bolcknum == 6 && bolckck == 1 && ((aa.Y + 1) < 21 && (bb.Y + 1) < 21 && (cc.Y) < 21 && (dd.Y - 1) < 21 &&
		pan[(aa.Y + 1) - 2][((aa.X - 2) / 2) - 1] != 1 && pan[(bb.Y + 1) - 2][((bb.X + 2) / 2) - 1] != 1 &&//
		pan[(cc.Y) - 2][((cc.X) / 2) - 1] != 1 && pan[(dd.Y - 1) - 2][((dd.X - 2) / 2) - 1] != 1) &&
		((aa.X - 2) > 0 && (bb.X + 2) > 0 && (cc.X) > 0 && (dd.X - 2) > 0 &&
			pan[(aa.Y + 1) - 3][((aa.X - 2) / 2) - 1] != 1 &&
			pan[(bb.Y + 1) - 3][((bb.X + 2) / 2) - 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) - 1] != 1 &&
			pan[(dd.Y - 1) - 3][((dd.X - 2) / 2) - 1] != 1) &&
		((aa.X - 2) < 22 && (bb.X + 2) < 22 && (cc.X) < 22 && (dd.X - 2) < 22 &&
			pan[(aa.Y + 1) - 3][((aa.X - 2) / 2) + 1] != 1 &&
			pan[(bb.Y + 1) - 3][((bb.X + 2) / 2) + 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) + 1] != 1 &&
			pan[(dd.Y - 1) - 3][((dd.X - 2) / 2) + 1] != 1)) {
		gotoxy(aa.X, aa.Y);
		printf("  ");
		gotoxy(bb.X, bb.Y);
		printf("  ");
		gotoxy(cc.X, cc.Y);
		printf("  ");
		gotoxy(dd.X, dd.Y);
		printf("  ");
		aa.X -= 2;
		aa.Y += 1;
		bb.X += 2;
		bb.Y += 1;
		dd.X -= 2;
		dd.Y -= 1;
		gotoxy(aa.X, aa.Y);
		printf("��");
		gotoxy(bb.X, bb.Y);
		printf("��");
		gotoxy(cc.X, cc.Y);
		printf("��");
		gotoxy(dd.X, dd.Y);
		printf("��");
		bolckck = 2;
	}
	else if (bolcknum == 6 && bolckck == 2 && ((aa.Y - 1) < 21 && (bb.Y + 1) < 21 && (cc.Y) < 21 && (dd.Y - 1) < 21 &&
		pan[(aa.Y - 1) - 2][((aa.X - 2) / 2) - 1] != 1 && pan[(bb.Y + 1) - 2][((bb.X - 2) / 2) - 1] != 1 &&//
		pan[(cc.Y) - 2][((cc.X) / 2) - 1] != 1 && pan[(dd.Y - 1) - 2][((dd.X + 2) / 2) - 1] != 1) &&
		((aa.X - 2) > 0 && (bb.X - 2) > 0 && (cc.X) > 0 && (dd.X + 2) > 0 &&
			pan[(aa.Y - 1) - 3][((aa.X - 2) / 2) - 1] != 1 &&
			pan[(bb.Y + 1) - 3][((bb.X - 2) / 2) - 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) - 1] != 1 &&
			pan[(dd.Y - 1) - 3][((dd.X + 2) / 2) - 1] != 1) &&
		((aa.X - 2) < 22 && (bb.X - 2) < 22 && (cc.X) < 22 && (dd.X + 2) < 22 &&
			pan[(aa.Y - 1) - 3][((aa.X - 2) / 2) + 1] != 1 &&
			pan[(bb.Y + 1) - 3][((bb.X - 2) / 2) + 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) + 1] != 1 &&
			pan[(dd.Y - 1) - 3][((dd.X + 2) / 2) + 1] != 1)) {
		gotoxy(aa.X, aa.Y);
		printf("  ");
		gotoxy(bb.X, bb.Y);
		printf("  ");
		gotoxy(cc.X, cc.Y);
		printf("  ");
		gotoxy(dd.X, dd.Y);
		printf("  ");
		aa.X -= 2;
		aa.Y -= 1;
		bb.X -= 2;
		bb.Y += 1;
		dd.X += 2;
		dd.Y -= 1;
		gotoxy(aa.X, aa.Y);
		printf("��");
		gotoxy(bb.X, bb.Y);
		printf("��");
		gotoxy(cc.X, cc.Y);
		printf("��");
		gotoxy(dd.X, dd.Y);
		printf("��");
		bolckck = 3;
	}
	else if (bolcknum == 6 && bolckck == 3 && ((aa.Y - 1) < 21 && (bb.Y - 1) < 21 && (cc.Y) < 21 && (dd.Y + 1) < 21 &&
		pan[(aa.Y - 1) - 2][((aa.X + 2) / 2) - 1] != 1 && pan[(bb.Y - 1) - 2][((bb.X - 2) / 2) - 1] != 1 &&//
		pan[(cc.Y) - 2][((cc.X) / 2) - 1] != 1 && pan[(dd.Y + 1) - 2][((dd.X + 2) / 2) - 1] != 1) &&
		((aa.X + 2) > 0 && (bb.X - 2) > 0 && (cc.X) > 0 && (dd.X + 2) > 0 &&
			pan[(aa.Y - 1) - 3][((aa.X + 2) / 2) - 1] != 1 &&
			pan[(bb.Y - 1) - 3][((bb.X - 2) / 2) - 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) - 1] != 1 &&
			pan[(dd.Y + 1) - 3][((dd.X + 2) / 2) - 1] != 1) &&
		((aa.X + 2) < 22 && (bb.X - 2) < 22 && (cc.X) < 22 && (dd.X + 2) < 22 &&
			pan[(aa.Y - 1) - 3][((aa.X + 2) / 2) + 1] != 1 &&
			pan[(bb.Y - 1) - 3][((bb.X - 2) / 2) + 1] != 1 &&
			pan[(cc.Y) - 3][((cc.X) / 2) + 1] != 1 &&
			pan[(dd.Y + 1) - 3][((dd.X + 2) / 2) + 1] != 1)) {
		gotoxy(aa.X, aa.Y);
		printf("  ");
		gotoxy(bb.X, bb.Y);
		printf("  ");
		gotoxy(cc.X, cc.Y);
		printf("  ");
		gotoxy(dd.X, dd.Y);
		printf("  ");
		aa.X += 2;
		aa.Y -= 1;
		bb.X -= 2;
		bb.Y -= 1;
		dd.X += 2;
		dd.Y += 1;
		gotoxy(aa.X, aa.Y);
		printf("��");
		gotoxy(bb.X, bb.Y);
		printf("��");
		gotoxy(cc.X, cc.Y);
		printf("��");
		gotoxy(dd.X, dd.Y);
		printf("��");
		bolckck = 0;
	}
}

int end()//�ǿ� ���� á�ٸ� ����
{
	if (pan[aa.Y - 3][(aa.X / 2) - 1] == 1 || pan[bb.Y - 3][(bb.X / 2) - 1] == 1 ||
		pan[cc.Y - 3][(cc.X / 2) - 1] == 1 || pan[dd.Y - 3][(dd.X / 2) - 1] == 1) {
		ranksave();
		return 1;
	}
	return 0;
}

void colorchange()
{
	int i, j;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//��� ���� ������
	for (i = 0; i < PAN_SIZE; i++) {
		for (j = 0; j < PPAN_SIZE; j++) {
			if (pan[i][j] == 1) {
				gotoxy((j * 2) + 2, i + 3);
				printf("��");
			}

		}
	}
}

void ranksave()//��ũ���� ������ 0�̸� ����x
{
	system("cls");
	int inkey1;
	int my[7];//�ڽ��� ���� ã�����Ѱ�
	int i, j, k;
	rankload();
	FILE* rsave;
	rsave = fopen("D:\\abc.txt", "w");
	for (i = 0; i < 6; i++) {
		if (rankscore[i] == NULL) {//����ִ°��� �ϴ� 0������
			rankscore[i] = 0;
			name[i][0] = 0;
			name[i][1] = 0;
			name[i][2] = 0;
		}
		my[i] = 0;
	}
	rankscore[5] = score;
	my[5] = 1;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {//�������
			if (rankscore[i] > rankscore[j]) {
				rankscore[6] = rankscore[i];
				rankscore[i] = rankscore[j];
				rankscore[j] = rankscore[6];
				my[6] = my[i];
				my[i] = my[j];
				my[j] = my[6];
				name[6][0] = name[i][0];
				name[i][0] = name[j][0];
				name[j][0] = name[6][0];
				name[6][1] = name[i][1];
				name[i][1] = name[j][1];
				name[j][1] = name[6][1];
				name[6][2] = name[i][2];
				name[i][2] = name[j][2];
				name[j][2] = name[6][2];
			}
		}
	}
	gotoxy(6, 1);
	printf("���");
	gotoxy(12, 1);
	printf("�̸�");
	gotoxy(18, 1);
	printf("����");

	for (i = 0; i < 5; i++) {//������������ �̸� ����
		gotoxy(6, i + 2);
		printf("%d��", i + 1);
		gotoxy(12, i + 2);
		if (my[i] == 1) {
			name[i][0] = 65;
			printf("%c", (char)name[i][0]);
			for (;;) {
				inkey1 = _getch();
				if (inkey1 == 75 && name[i][0] >= 65) {
					name[i][0]--;
					gotoxy(12, i + 2);
					printf("%c", (char)name[i][0]);
				}
				else if (inkey1 == 77 && name[i][0] <= 90) {
					name[i][0]++;
					gotoxy(12, i + 2);
					printf("%c", (char)name[i][0]);
				}
				else if (inkey1 == 32)break;
			}
			gotoxy(14, i + 2);
			printf("%c", (char)name[i][1]);
			name[i][1] = 65;
			for (;;) {
				inkey1 = _getch();
				if (inkey1 == 75 && name[i][0] >= 65) {
					name[i][1]--;
					gotoxy(14, i + 2);
					printf("%c", (char)name[i][1]);
				}
				else if (inkey1 == 77 && name[i][0] <= 90) {
					name[i][1]++;
					gotoxy(14, i + 2);
					printf("%c", (char)name[i][1]);
				}
				else if (inkey1 == 32)break;
			}
			gotoxy(16, i + 2);
			name[i][2] = 65;
			printf("%c", (char)name[i][2]);
			for (;;) {
				inkey1 = _getch();
				if (inkey1 == 75 && name[i][0] >= 65) {
					name[i][2]--;
					gotoxy(16, i + 2);
					printf("%c", (char)name[i][2]);
				}
				else if (inkey1 == 77 && name[i][0] <= 90) {
					name[i][2]++;
					gotoxy(16, i + 2);
					printf("%c", (char)name[i][2]);
				}
				else if (inkey1 == 32)break;
			}
		}
		if (my[i] == 0) {//�ڽ��� ������ �ƴҶ� �̸� ���
			if (rankscore[i] != 0) {
				gotoxy(12, i + 2);
				printf("%c", (char)name[i][0]);
				gotoxy(14, i + 2);
				printf("%c", (char)name[i][1]);
				gotoxy(16, i + 2);
				printf("%c", (char)name[i][2]);
			}
			else {//�̸��� ������ ���
				gotoxy(12, i + 2);
				printf("��");
				gotoxy(14, i + 2);
				printf("��");
				gotoxy(16, i + 2);
				printf("��");
			}
		}
		gotoxy(20, i + 2);
		printf("���� : %d", rankscore[i]);
		fprintf(rsave, "%d ", rankscore[i]);//����
		fprintf(rsave, "%d ", name[i][0]);
		fprintf(rsave, "%d ", name[i][1]);
		fprintf(rsave, "%d ", name[i][2]);

	}

	fclose(rsave);
}

void rankload()//�ҷ�����
{
	int i;
	FILE* rload;
	rload = fopen("D:\\abc.txt", "r");
	for (i = 0; i < 6; i++) {
		fscanf(rload, "%d ", &rankscore[i]);
		fscanf(rload, "%d ", &name[i][0]);
		fscanf(rload, "%d ", &name[i][1]);
		fscanf(rload, "%d ", &name[i][2]);
	}
	fclose(rload);
}
int main() {
	panprint();
	for (; eend == 0;)
	{
		bolck();
		fpanin();
		if (end()) {
			break;
		}
		down();
		pank();

	}

}