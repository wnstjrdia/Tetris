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
void bolck();//첫블럭
void panprint();//출력
void fpanin();//첫블럭 입력
void down();//내려가기
void pank();//터짐 
void change();//블럭바꿈 
void colorchange();//터질시 색바꿈 
void ranksave();//끝날시 저장 
void rankload();//끝날시 불러오기 
int end();//끝 
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
		printf("★");
	}
	else {
		gotoxy(30, 3);
		printf("  ");
	}
	bolcknum = bolcknum2;//bolcknum2는 블럭미리보기
	if (num = 0) {
		bolcknum = (rand() % 7);
		num = 1;
	}

	if (bolcknum == 0)//ㅁㅁ//블럭모양저장
	{//                 ㅁㅁ
		a[0][0] = 1;
		b[0][1] = 1;
		c[1][0] = 1;
		d[1][1] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		color = 2;
	}
	else if (bolcknum == 1)//ㅁ
	{//                      ㅁ
		a[0][0] = 1;//         ㅁ
		b[1][0] = 1;//         ㅁ
		c[2][0] = 1;
		d[3][0] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		color = 3;
	}
	else if (bolcknum == 2)//ㅁㅁ
	{//                        ㅁㅁ
		a[0][0] = 1;
		b[0][1] = 1;
		c[1][1] = 1;
		d[1][2] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		color = 4;
	}
	else if (bolcknum == 3)//ㅁㅁ
	{//                    ㅁㅁ
		a[0][1] = 1;
		b[0][2] = 1;
		c[1][0] = 1;
		d[1][1] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		color = 5;
	}
	else if (bolcknum == 4)//ㅁ
	{//                      ㅁㅁㅁ
		a[0][0] = 1;
		b[1][0] = 1;
		c[1][1] = 1;
		d[1][2] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		color = 6;
	}
	else if (bolcknum == 5)//ㅁ
	{//                  ㅁㅁㅁ
		a[0][2] = 1;
		b[1][0] = 1;
		c[1][1] = 1;
		d[1][2] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		color = 7;
	}
	else if (bolcknum == 6)//ㅁ
	{//                    ㅁㅁㅁ
		a[0][1] = 1;
		b[1][0] = 1;
		c[1][1] = 1;
		d[1][2] = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		color = 8;
	}
	bolcknum2 = (rand() % 7);
	//미리보기
	if (bolcknum2 == 0)//ㅁㅁ
	{//                 ㅁㅁ
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
		printf("ㅁ");
		gotoxy(30, 7);
		printf("ㅁ");
		gotoxy(32, 6);
		printf("ㅁ");
		gotoxy(32, 7);
		printf("ㅁ");
	}
	else if (bolcknum2 == 1)//ㅁ
	{//                      ㅁ
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
		printf("ㅁ");
		gotoxy(32, 6);
		printf("ㅁ");
		gotoxy(34, 6);
		printf("ㅁ");
		gotoxy(36, 6);
		printf("ㅁ");
	}
	else if (bolcknum2 == 2)//ㅁㅁ
	{//                        ㅁㅁ
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
		printf("ㅁ");
		gotoxy(30, 7);
		printf("ㅁ");
		gotoxy(32, 7);
		printf("ㅁ");
		gotoxy(32, 8);
		printf("ㅁ");
	}
	else if (bolcknum2 == 3)//ㅁㅁ
	{//                    ㅁㅁ
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
		printf("ㅁ");
		gotoxy(30, 8);
		printf("ㅁ");
		gotoxy(32, 6);
		printf("ㅁ");
		gotoxy(32, 7);
		printf("ㅁ");
	}
	else if (bolcknum2 == 4)//ㅁ
	{//                      ㅁㅁㅁ
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
		printf("ㅁ");
		gotoxy(32, 6);
		printf("ㅁ");
		gotoxy(32, 7);
		printf("ㅁ");
		gotoxy(32, 8);
		printf("ㅁ");
	}
	else if (bolcknum2 == 5)//ㅁ
	{//                  ㅁㅁㅁ
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
		printf("ㅁ");
		gotoxy(32, 6);
		printf("ㅁ");
		gotoxy(32, 7);
		printf("ㅁ");
		gotoxy(32, 8);
		printf("ㅁ");
	}
	else if (bolcknum2 == 6)//ㅁ
	{//                    ㅁㅁㅁ
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
		printf("ㅁ");
		gotoxy(32, 6);
		printf("ㅁ");
		gotoxy(32, 7);
		printf("ㅁ");
		gotoxy(32, 8);
		printf("ㅁ");
	}
}
void panprint() {//처음판출력
	int i, j;
	printf("▩▩▩▩▩▩▩▩▩▩▩▩\n");
	printf("▩▩▩▩테트리스▩▩▩▩\n");
	printf("▩▩▩▩▩▩▩▩▩▩▩▩\n");
	for (i = 0; i < PAN_SIZE; i++) {
		printf("▩");
		for (j = 0; j < PPAN_SIZE; j++) {
			printf("  ");
		}
		printf("▩\n");
	}
	printf("▩▩▩▩▩▩▩▩▩▩▩▩\n");
	gotoxy(30, 10);
	printf("점수 : %d", score);
	gotoxy(40, 3);
	printf("아이템 사용법:하면서 별이 나타나면");
	gotoxy(40, 4);
	printf("              스페이스바를 누를시");
	gotoxy(40, 5);
	printf("              모든것을 무시하고 ");
	gotoxy(40, 6);
	printf("              가장 아랫쪽으로 내려감");
}
void fpanin() {//처음 블럭의 위치잡기
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
	gotoxy(aa.X, aa.Y);//첫블럭출력
	printf("■");
	gotoxy(bb.X, bb.Y);
	printf("■");
	gotoxy(cc.X, cc.Y);
	printf("■");
	gotoxy(dd.X, dd.Y);
	printf("■");
	clock_t t1, t2, t3;
	t1 = clock();
	for (;;) {
		t2 = clock();
		if ((t2 - t1) > speed) {//시간에 따라 내려감 speed는 점수에따라 빨라짐
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
			printf("■");
			gotoxy(bb.X, bb.Y);
			printf("■");
			gotoxy(cc.X, cc.Y);
			printf("■");
			gotoxy(dd.X, dd.Y);
			printf("■");
			t1 = t2;
		}
		if (_kbhit()) {
			inkey1 = _getch();
			if (inkey1 == 27) {//종료
				eend = 1;
				break;
			}
			else if (inkey1 == 32) {//스페이스바 바로내려가는것
				for (;;) {
					if ((aa.Y > 21 || bb.Y > 21 || cc.Y > 21 || dd.Y > 21 ||
						pan[aa.Y - 2][(aa.X / 2) - 1] == 1 || pan[bb.Y - 2][(bb.X / 2) - 1] == 1 ||
						pan[cc.Y - 2][(cc.X / 2) - 1] == 1 || pan[dd.Y - 2][(dd.X / 2) - 1] == 1) &&
						item != 0) {
						break;
					}
					if ((aa.Y > 21 || bb.Y > 21 || cc.Y > 21 || dd.Y > 21) && item == 0) {//아이템일때
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
					printf("■");
					gotoxy(bb.X, bb.Y);
					printf("■");
					gotoxy(cc.X, cc.Y);
					printf("■");
					gotoxy(dd.X, dd.Y);
					printf("■");
				}
			}
			else if (inkey1 == 0x0 || inkey1 == 0xE0) {
				inkey2 = _getch();
				if (inkey2 == 75 && aa.X > 2 && bb.X > 2 && cc.X > 2 && dd.X > 2 &&//왼쪽키
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
					printf("■");
					gotoxy(bb.X, bb.Y);
					printf("■");
					gotoxy(cc.X, cc.Y);
					printf("■");
					gotoxy(dd.X, dd.Y);
					printf("■");
				}
				else if (inkey2 == 77 && aa.X < 20 && bb.X < 20 && cc.X < 20 && dd.X < 20 &&//오른쪽키
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
					printf("■");
					gotoxy(bb.X, bb.Y);
					printf("■");
					gotoxy(cc.X, cc.Y);
					printf("■");
					gotoxy(dd.X, dd.Y);
					printf("■");
				}
				else if (inkey2 == 80) {//아랫방향키
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
					printf("■");
					gotoxy(bb.X, bb.Y);
					printf("■");
					gotoxy(cc.X, cc.Y);
					printf("■");
					gotoxy(dd.X, dd.Y);
					printf("■");
				}
				else if (inkey2 == 72) {//위쪽방향키 블럭의 모양변경
					change();
				}
			}
		}
		if (aa.Y > 21 || bb.Y > 21 || cc.Y > 21 || dd.Y > 21 ||//아래쪽의 블럭에 막혔을때
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
				count++;//count는 한줄완성확인
			}
			if (linecount == 0)//linecount는 터질라인의 갯수
			{
				pankline = i;//pankline는 터질라인의 위치
			}
			if (count == 10) {
				ckcount = 1;//ckcount가 1이면 터짐
				linecount++;
			}

		}
		count = 0;
		if (ckcount != 0)//ckcount가 1일때
		{
			for (j = 0; j < PPAN_SIZE; j++)
			{
				pan[i][j] = 0;//그줄 라인을 제거한다
				gotoxy((i * 2) + 10, j + 3);
				printf("  ");
			}
		}
		ckcount = 0;
	}
	i = 0;
	j = 0;

	if (linecount != 0) {//터진것들이 있다면
		for (i = (pankline - 1); i >= 0; i--) {//터진라인에서부터
			for (j = 0; j < PPAN_SIZE; j++) {
				if (pan[i][j] == 1) {
					gotoxy((j * 2) + 2, i + 3);//모두 아래쪽으로 끌어내린다
					printf("  ");
					pan[i][j] = 0;

					gotoxy((j * 2) + 2, i + 3 + linecount);
					printf("■");
					pan[i + linecount][j] = 1;
				}
				else {
					gotoxy((j * 2) + 2, i + 3 + linecount);
					printf("  ");

				}
			}
		}

	}
	if (speed - linecount * 10 > 200) {//스피드조절 
		speed -= linecount * 10;
	}
	gotoxy(30, 10);
	score += linecount;
	printf("점수 : %d", score);
	colorchange();
}

void change() {//블럭의 모양변환
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
		printf("■");
		gotoxy(bb.X, bb.Y);
		printf("■");
		gotoxy(cc.X, cc.Y);
		printf("■");
		gotoxy(dd.X, dd.Y);
		printf("■");
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
		printf("■");
		gotoxy(bb.X, bb.Y);
		printf("■");
		gotoxy(cc.X, cc.Y);
		printf("■");
		gotoxy(dd.X, dd.Y);
		printf("■");
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
		printf("■");
		gotoxy(bb.X, bb.Y);
		printf("■");
		gotoxy(cc.X, cc.Y);
		printf("■");
		gotoxy(dd.X, dd.Y);
		printf("■");
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
		printf("■");
		gotoxy(bb.X, bb.Y);
		printf("■");
		gotoxy(cc.X, cc.Y);
		printf("■");
		gotoxy(dd.X, dd.Y);
		printf("■");
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
		printf("■");
		gotoxy(bb.X, bb.Y);
		printf("■");
		gotoxy(cc.X, cc.Y);
		printf("■");
		gotoxy(dd.X, dd.Y);
		printf("■");
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
		printf("■");
		gotoxy(bb.X, bb.Y);
		printf("■");
		gotoxy(cc.X, cc.Y);
		printf("■");
		gotoxy(dd.X, dd.Y);
		printf("■");
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
		printf("■");
		gotoxy(bb.X, bb.Y);
		printf("■");
		gotoxy(cc.X, cc.Y);
		printf("■");
		gotoxy(dd.X, dd.Y);
		printf("■");
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
		printf("■");
		gotoxy(bb.X, bb.Y);
		printf("■");
		gotoxy(cc.X, cc.Y);
		printf("■");
		gotoxy(dd.X, dd.Y);
		printf("■");
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
		printf("■");
		gotoxy(bb.X, bb.Y);
		printf("■");
		gotoxy(cc.X, cc.Y);
		printf("■");
		gotoxy(dd.X, dd.Y);
		printf("■");
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
		printf("■");
		gotoxy(bb.X, bb.Y);
		printf("■");
		gotoxy(cc.X, cc.Y);
		printf("■");
		gotoxy(dd.X, dd.Y);
		printf("■");
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
		printf("■");
		gotoxy(bb.X, bb.Y);
		printf("■");
		gotoxy(cc.X, cc.Y);
		printf("■");
		gotoxy(dd.X, dd.Y);
		printf("■");
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
		printf("■");
		gotoxy(bb.X, bb.Y);
		printf("■");
		gotoxy(cc.X, cc.Y);
		printf("■");
		gotoxy(dd.X, dd.Y);
		printf("■");
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
		printf("■");
		gotoxy(bb.X, bb.Y);
		printf("■");
		gotoxy(cc.X, cc.Y);
		printf("■");
		gotoxy(dd.X, dd.Y);
		printf("■");
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
		printf("■");
		gotoxy(bb.X, bb.Y);
		printf("■");
		gotoxy(cc.X, cc.Y);
		printf("■");
		gotoxy(dd.X, dd.Y);
		printf("■");
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
		printf("■");
		gotoxy(bb.X, bb.Y);
		printf("■");
		gotoxy(cc.X, cc.Y);
		printf("■");
		gotoxy(dd.X, dd.Y);
		printf("■");
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
		printf("■");
		gotoxy(bb.X, bb.Y);
		printf("■");
		gotoxy(cc.X, cc.Y);
		printf("■");
		gotoxy(dd.X, dd.Y);
		printf("■");
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
		printf("■");
		gotoxy(bb.X, bb.Y);
		printf("■");
		gotoxy(cc.X, cc.Y);
		printf("■");
		gotoxy(dd.X, dd.Y);
		printf("■");
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
		printf("■");
		gotoxy(bb.X, bb.Y);
		printf("■");
		gotoxy(cc.X, cc.Y);
		printf("■");
		gotoxy(dd.X, dd.Y);
		printf("■");
		bolckck = 0;
	}
}

int end()//판에 가득 찼다면 끝남
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//모든 블럭의 색변경
	for (i = 0; i < PAN_SIZE; i++) {
		for (j = 0; j < PPAN_SIZE; j++) {
			if (pan[i][j] == 1) {
				gotoxy((j * 2) + 2, i + 3);
				printf("■");
			}

		}
	}
}

void ranksave()//랭크저장 점수가 0이면 저장x
{
	system("cls");
	int inkey1;
	int my[7];//자신의 것을 찾기위한것
	int i, j, k;
	rankload();
	FILE* rsave;
	rsave = fopen("D:\\abc.txt", "w");
	for (i = 0; i < 6; i++) {
		if (rankscore[i] == NULL) {//비어있는곳은 일단 0을저장
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
		for (j = 0; j < 6; j++) {//등수정렬
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
	printf("등수");
	gotoxy(12, 1);
	printf("이름");
	gotoxy(18, 1);
	printf("점수");

	for (i = 0; i < 5; i++) {//오락실형태의 이름 저장
		gotoxy(6, i + 2);
		printf("%d등", i + 1);
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
		if (my[i] == 0) {//자신의 점수가 아닐때 이름 출력
			if (rankscore[i] != 0) {
				gotoxy(12, i + 2);
				printf("%c", (char)name[i][0]);
				gotoxy(14, i + 2);
				printf("%c", (char)name[i][1]);
				gotoxy(16, i + 2);
				printf("%c", (char)name[i][2]);
			}
			else {//이름이 없을때 출력
				gotoxy(12, i + 2);
				printf("ㅡ");
				gotoxy(14, i + 2);
				printf("ㅡ");
				gotoxy(16, i + 2);
				printf("ㅡ");
			}
		}
		gotoxy(20, i + 2);
		printf("점수 : %d", rankscore[i]);
		fprintf(rsave, "%d ", rankscore[i]);//저장
		fprintf(rsave, "%d ", name[i][0]);
		fprintf(rsave, "%d ", name[i][1]);
		fprintf(rsave, "%d ", name[i][2]);

	}

	fclose(rsave);
}

void rankload()//불러오기
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