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
void bolck();//湛鷺薫
void panprint();//窒径
void fpanin();//湛鷺薫 脊径
void down();//鎧形亜奄
void pank();//斗像 
void change();//鷺薫郊嘩 
void colorchange();//斗霜獣 事郊嘩 
void ranksave();//魁劾獣 煽舌 
void rankload();//魁劾獣 災君神奄 
int end();//魁 
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
		printf("【");
	}
	else {
		gotoxy(30, 3);
		printf("  ");
	}
	bolcknum = bolcknum2;//bolcknum2澗 鷺薫耕軒左奄
	if (num = 0) {
		bolcknum = (rand() % 7);
		num = 1;
	}

	if (bolcknum == 0)//けけ//鷺薫乞丞煽舌
	{//                 けけ
		a[0][0] = 1;
		b[0][1] = 1;
		c[1][0] = 1;
		d[1][1] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		color = 2;
	}
	else if (bolcknum == 1)//け
	{//                      け
		a[0][0] = 1;//         け
		b[1][0] = 1;//         け
		c[2][0] = 1;
		d[3][0] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		color = 3;
	}
	else if (bolcknum == 2)//けけ
	{//                        けけ
		a[0][0] = 1;
		b[0][1] = 1;
		c[1][1] = 1;
		d[1][2] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		color = 4;
	}
	else if (bolcknum == 3)//けけ
	{//                    けけ
		a[0][1] = 1;
		b[0][2] = 1;
		c[1][0] = 1;
		d[1][1] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		color = 5;
	}
	else if (bolcknum == 4)//け
	{//                      けけけ
		a[0][0] = 1;
		b[1][0] = 1;
		c[1][1] = 1;
		d[1][2] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		color = 6;
	}
	else if (bolcknum == 5)//け
	{//                  けけけ
		a[0][2] = 1;
		b[1][0] = 1;
		c[1][1] = 1;
		d[1][2] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		color = 7;
	}
	else if (bolcknum == 6)//け
	{//                    けけけ
		a[0][1] = 1;
		b[1][0] = 1;
		c[1][1] = 1;
		d[1][2] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		color = 8;
	}
	bolcknum2 = (rand() % 7);
	//耕軒左奄
	if (bolcknum2 == 0)//けけ
	{//                 けけ
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
		printf("け");
		gotoxy(30, 7);
		printf("け");
		gotoxy(32, 6);
		printf("け");
		gotoxy(32, 7);
		printf("け");
	}
	else if (bolcknum2 == 1)//け
	{//                      け
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
		printf("け");
		gotoxy(32, 6);
		printf("け");
		gotoxy(34, 6);
		printf("け");
		gotoxy(36, 6);
		printf("け");
	}
	else if (bolcknum2 == 2)//けけ
	{//                        けけ
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
		printf("け");
		gotoxy(30, 7);
		printf("け");
		gotoxy(32, 7);
		printf("け");
		gotoxy(32, 8);
		printf("け");
	}
	else if (bolcknum2 == 3)//けけ
	{//                    けけ
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
		printf("け");
		gotoxy(30, 8);
		printf("け");
		gotoxy(32, 6);
		printf("け");
		gotoxy(32, 7);
		printf("け");
	}
	else if (bolcknum2 == 4)//け
	{//                      けけけ
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
		printf("け");
		gotoxy(32, 6);
		printf("け");
		gotoxy(32, 7);
		printf("け");
		gotoxy(32, 8);
		printf("け");
	}
	else if (bolcknum2 == 5)//け
	{//                  けけけ
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
		printf("け");
		gotoxy(32, 6);
		printf("け");
		gotoxy(32, 7);
		printf("け");
		gotoxy(32, 8);
		printf("け");
	}
	else if (bolcknum2 == 6)//け
	{//                    けけけ
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
		printf("け");
		gotoxy(32, 6);
		printf("け");
		gotoxy(32, 7);
		printf("け");
		gotoxy(32, 8);
		printf("け");
	}
}
void panprint() {//坦製毒窒径
	int i, j;
	printf("¬¬¬¬¬¬¬¬¬¬¬¬\n");
	printf("¬¬¬¬砺闘軒什¬¬¬¬\n");
	printf("¬¬¬¬¬¬¬¬¬¬¬¬\n");
	for (i = 0; i < PAN_SIZE; i++) {
		printf("¬");
		for (j = 0; j < PPAN_SIZE; j++) {
			printf("  ");
		}
		printf("¬\n");
	}
	printf("¬¬¬¬¬¬¬¬¬¬¬¬\n");
	gotoxy(30, 10);
	printf("繊呪 : %d", score);
	gotoxy(40, 3);
	printf("焼戚奴 紫遂狛:馬檎辞 紺戚 蟹展蟹檎");
	gotoxy(40, 4);
	printf("              什凪戚什郊研 刊研獣");
	gotoxy(40, 5);
	printf("              乞窮依聖 巷獣馬壱 ");
	gotoxy(40, 6);
	printf("              亜舌 焼熊楕生稽 鎧形姶");
}
void fpanin() {//坦製 鷺薫税 是帖説奄
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
	gotoxy(aa.X, aa.Y);//湛鷺薫窒径
	printf("＝");
	gotoxy(bb.X, bb.Y);
	printf("＝");
	gotoxy(cc.X, cc.Y);
	printf("＝");
	gotoxy(dd.X, dd.Y);
	printf("＝");
	clock_t t1, t2, t3;
	t1 = clock();
	for (;;) {
		t2 = clock();
		if ((t2 - t1) > speed) {//獣娃拭 魚虞 鎧形姶 speed澗 繊呪拭魚虞 察虞像
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
			printf("＝");
			gotoxy(bb.X, bb.Y);
			printf("＝");
			gotoxy(cc.X, cc.Y);
			printf("＝");
			gotoxy(dd.X, dd.Y);
			printf("＝");
			t1 = t2;
		}
		if (_kbhit()) {
			inkey1 = _getch();
			if (inkey1 == 27) {//曽戟
				eend = 1;
				break;
			}
			else if (inkey1 == 32) {//什凪戚什郊 郊稽鎧形亜澗依
				for (;;) {
					if ((aa.Y > 21 || bb.Y > 21 || cc.Y > 21 || dd.Y > 21 ||
						pan[aa.Y - 2][(aa.X / 2) - 1] == 1 || pan[bb.Y - 2][(bb.X / 2) - 1] == 1 ||
						pan[cc.Y - 2][(cc.X / 2) - 1] == 1 || pan[dd.Y - 2][(dd.X / 2) - 1] == 1) &&
						item != 0) {
						break;
					}
					if ((aa.Y > 21 || bb.Y > 21 || cc.Y > 21 || dd.Y > 21) && item == 0) {//焼戚奴析凶
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
					printf("＝");
					gotoxy(bb.X, bb.Y);
					printf("＝");
					gotoxy(cc.X, cc.Y);
					printf("＝");
					gotoxy(dd.X, dd.Y);
					printf("＝");
				}
			}
			else if (inkey1 == 0x0 || inkey1 == 0xE0) {
				inkey2 = _getch();
				if (inkey2 == 75 && aa.X > 2 && bb.X > 2 && cc.X > 2 && dd.X > 2 &&//図楕徹
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
					printf("＝");
					gotoxy(bb.X, bb.Y);
					printf("＝");
					gotoxy(cc.X, cc.Y);
					printf("＝");
					gotoxy(dd.X, dd.Y);
					printf("＝");
				}
				else if (inkey2 == 77 && aa.X < 20 && bb.X < 20 && cc.X < 20 && dd.X < 20 &&//神献楕徹
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
					printf("＝");
					gotoxy(bb.X, bb.Y);
					printf("＝");
					gotoxy(cc.X, cc.Y);
					printf("＝");
					gotoxy(dd.X, dd.Y);
					printf("＝");
				}
				else if (inkey2 == 80) {//焼熊号狽徹
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
					printf("＝");
					gotoxy(bb.X, bb.Y);
					printf("＝");
					gotoxy(cc.X, cc.Y);
					printf("＝");
					gotoxy(dd.X, dd.Y);
					printf("＝");
				}
				else if (inkey2 == 72) {//是楕号狽徹 鷺薫税 乞丞痕井
					change();
				}
			}
		}
		if (aa.Y > 21 || bb.Y > 21 || cc.Y > 21 || dd.Y > 21 ||//焼掘楕税 鷺薫拭 厳縛聖凶
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
				count++;//count澗 廃匝刃失溌昔
			}
			if (linecount == 0)//linecount澗 斗霜虞昔税 姐呪
			{
				pankline = i;//pankline澗 斗霜虞昔税 是帖
			}
			if (count == 10) {
				ckcount = 1;//ckcount亜 1戚檎 斗像
				linecount++;
			}

		}
		count = 0;
		if (ckcount != 0)//ckcount亜 1析凶
		{
			for (j = 0; j < PPAN_SIZE; j++)
			{
				pan[i][j] = 0;//益匝 虞昔聖 薦暗廃陥
				gotoxy((i * 2) + 10, j + 3);
				printf("  ");
			}
		}
		ckcount = 0;
	}
	i = 0;
	j = 0;

	if (linecount != 0) {//斗遭依級戚 赤陥檎
		for (i = (pankline - 1); i >= 0; i--) {//斗遭虞昔拭辞採斗
			for (j = 0; j < PPAN_SIZE; j++) {
				if (pan[i][j] == 1) {
					gotoxy((j * 2) + 2, i + 3);//乞砧 焼掘楕生稽 怪嬢鎧鍵陥
					printf("  ");
					pan[i][j] = 0;

					gotoxy((j * 2) + 2, i + 3 + linecount);
					printf("＝");
					pan[i + linecount][j] = 1;
				}
				else {
					gotoxy((j * 2) + 2, i + 3 + linecount);
					printf("  ");

				}
			}
		}

	}
	if (speed - linecount * 10 > 200) {//什杷球繕箭 
		speed -= linecount * 10;
	}
	gotoxy(30, 10);
	score += linecount;
	printf("繊呪 : %d", score);
	colorchange();
}

void change() {//鷺薫税 乞丞痕発
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
		printf("＝");
		gotoxy(bb.X, bb.Y);
		printf("＝");
		gotoxy(cc.X, cc.Y);
		printf("＝");
		gotoxy(dd.X, dd.Y);
		printf("＝");
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
		printf("＝");
		gotoxy(bb.X, bb.Y);
		printf("＝");
		gotoxy(cc.X, cc.Y);
		printf("＝");
		gotoxy(dd.X, dd.Y);
		printf("＝");
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
		printf("＝");
		gotoxy(bb.X, bb.Y);
		printf("＝");
		gotoxy(cc.X, cc.Y);
		printf("＝");
		gotoxy(dd.X, dd.Y);
		printf("＝");
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
		printf("＝");
		gotoxy(bb.X, bb.Y);
		printf("＝");
		gotoxy(cc.X, cc.Y);
		printf("＝");
		gotoxy(dd.X, dd.Y);
		printf("＝");
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
		printf("＝");
		gotoxy(bb.X, bb.Y);
		printf("＝");
		gotoxy(cc.X, cc.Y);
		printf("＝");
		gotoxy(dd.X, dd.Y);
		printf("＝");
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
		printf("＝");
		gotoxy(bb.X, bb.Y);
		printf("＝");
		gotoxy(cc.X, cc.Y);
		printf("＝");
		gotoxy(dd.X, dd.Y);
		printf("＝");
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
		printf("＝");
		gotoxy(bb.X, bb.Y);
		printf("＝");
		gotoxy(cc.X, cc.Y);
		printf("＝");
		gotoxy(dd.X, dd.Y);
		printf("＝");
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
		printf("＝");
		gotoxy(bb.X, bb.Y);
		printf("＝");
		gotoxy(cc.X, cc.Y);
		printf("＝");
		gotoxy(dd.X, dd.Y);
		printf("＝");
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
		printf("＝");
		gotoxy(bb.X, bb.Y);
		printf("＝");
		gotoxy(cc.X, cc.Y);
		printf("＝");
		gotoxy(dd.X, dd.Y);
		printf("＝");
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
		printf("＝");
		gotoxy(bb.X, bb.Y);
		printf("＝");
		gotoxy(cc.X, cc.Y);
		printf("＝");
		gotoxy(dd.X, dd.Y);
		printf("＝");
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
		printf("＝");
		gotoxy(bb.X, bb.Y);
		printf("＝");
		gotoxy(cc.X, cc.Y);
		printf("＝");
		gotoxy(dd.X, dd.Y);
		printf("＝");
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
		printf("＝");
		gotoxy(bb.X, bb.Y);
		printf("＝");
		gotoxy(cc.X, cc.Y);
		printf("＝");
		gotoxy(dd.X, dd.Y);
		printf("＝");
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
		printf("＝");
		gotoxy(bb.X, bb.Y);
		printf("＝");
		gotoxy(cc.X, cc.Y);
		printf("＝");
		gotoxy(dd.X, dd.Y);
		printf("＝");
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
		printf("＝");
		gotoxy(bb.X, bb.Y);
		printf("＝");
		gotoxy(cc.X, cc.Y);
		printf("＝");
		gotoxy(dd.X, dd.Y);
		printf("＝");
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
		printf("＝");
		gotoxy(bb.X, bb.Y);
		printf("＝");
		gotoxy(cc.X, cc.Y);
		printf("＝");
		gotoxy(dd.X, dd.Y);
		printf("＝");
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
		printf("＝");
		gotoxy(bb.X, bb.Y);
		printf("＝");
		gotoxy(cc.X, cc.Y);
		printf("＝");
		gotoxy(dd.X, dd.Y);
		printf("＝");
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
		printf("＝");
		gotoxy(bb.X, bb.Y);
		printf("＝");
		gotoxy(cc.X, cc.Y);
		printf("＝");
		gotoxy(dd.X, dd.Y);
		printf("＝");
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
		printf("＝");
		gotoxy(bb.X, bb.Y);
		printf("＝");
		gotoxy(cc.X, cc.Y);
		printf("＝");
		gotoxy(dd.X, dd.Y);
		printf("＝");
		bolckck = 0;
	}
}

int end()//毒拭 亜究 叩陥檎 魁害
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//乞窮 鷺薫税 事痕井
	for (i = 0; i < PAN_SIZE; i++) {
		for (j = 0; j < PPAN_SIZE; j++) {
			if (pan[i][j] == 1) {
				gotoxy((j * 2) + 2, i + 3);
				printf("＝");
			}

		}
	}
}

void ranksave()//粂滴煽舌 繊呪亜 0戚檎 煽舌x
{
	system("cls");
	int inkey1;
	int my[7];//切重税 依聖 達奄是廃依
	int i, j, k;
	rankload();
	FILE* rsave;
	rsave = fopen("D:\\abc.txt", "w");
	for (i = 0; i < 6; i++) {
		if (rankscore[i] == NULL) {//搾嬢赤澗員精 析舘 0聖煽舌
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
		for (j = 0; j < 6; j++) {//去呪舛慶
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
	printf("去呪");
	gotoxy(12, 1);
	printf("戚硯");
	gotoxy(18, 1);
	printf("繊呪");

	for (i = 0; i < 5; i++) {//神喰叔莫殿税 戚硯 煽舌
		gotoxy(6, i + 2);
		printf("%d去", i + 1);
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
		if (my[i] == 0) {//切重税 繊呪亜 焼諌凶 戚硯 窒径
			if (rankscore[i] != 0) {
				gotoxy(12, i + 2);
				printf("%c", (char)name[i][0]);
				gotoxy(14, i + 2);
				printf("%c", (char)name[i][1]);
				gotoxy(16, i + 2);
				printf("%c", (char)name[i][2]);
			}
			else {//戚硯戚 蒸聖凶 窒径
				gotoxy(12, i + 2);
				printf("ぱ");
				gotoxy(14, i + 2);
				printf("ぱ");
				gotoxy(16, i + 2);
				printf("ぱ");
			}
		}
		gotoxy(20, i + 2);
		printf("繊呪 : %d", rankscore[i]);
		fprintf(rsave, "%d ", rankscore[i]);//煽舌
		fprintf(rsave, "%d ", name[i][0]);
		fprintf(rsave, "%d ", name[i][1]);
		fprintf(rsave, "%d ", name[i][2]);

	}

	fclose(rsave);
}

void rankload()//災君神奄
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