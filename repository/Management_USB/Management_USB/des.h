#include <stdio.h>

int IP[64] =
{
	58, 50, 42, 34, 26 ,18 ,10, 2,
	60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6,
	64, 56, 48, 40, 32, 24, 16, 8,
	57, 49, 41, 33, 25, 17, 9, 1,
	59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5,
	63, 55, 47, 39, 31, 23, 15, 7
};

int E[48] = { 32, 1, 2, 3, 4, 5,
4, 5, 6, 7, 8, 9,
8, 9, 10, 11, 12, 13,
12, 13, 14, 15, 16, 17,
16, 17, 18, 19, 20, 21,
20, 21, 22, 23, 24, 25,
24, 25, 26, 27, 28, 29,
28, 29, 30, 31, 32, 1 };

int PC_1[56] = { 57, 49, 41, 33, 25, 17, 9,
1, 58, 50, 42, 34, 26, 18,
10, 2, 59, 51, 43, 35, 27,
19, 11, 3, 60, 52, 44, 36,
63, 55, 47, 39, 31, 23, 15,
7, 62, 54, 46, 38, 30, 22,
14, 6, 61, 53, 45, 37, 29,
21, 13, 5, 28, 20, 12, 4 };

int PC_2[48] = { 14, 17, 11, 24, 1, 5, 3, 28,
15, 6, 21, 10, 23, 19, 12, 4,
26, 8, 16, 7, 27, 20, 13, 2,
41, 52, 31, 37, 47, 55, 30, 40,
51, 45, 33, 48, 44, 49, 39, 56,
34, 53, 46, 42, 50, 36, 29, 32 };

int IP_1[64] = { 40, 8, 48, 16, 56, 24, 64, 32,
39, 7, 47, 15, 55, 23, 63, 31,
38, 6, 46, 14, 54, 22, 62, 30,
37, 5, 45, 13, 53, 21, 61, 29,
36, 4, 44, 12, 52, 20, 60, 28,
35, 3, 43, 11, 51, 19, 59, 27,
34, 2, 42, 10, 50, 18, 58, 26,
33, 1, 41, 9, 49, 17, 57, 25 };

int shiftNum[16] = { 1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1 };

int P[32] = { 16, 7, 20, 21, 29, 12, 28, 17,
1, 15, 23, 26, 5, 18, 31, 10,
2, 8, 24, 14, 32, 27, 3, 9,
19, 13, 30, 6, 22, 11, 4, 25 };

int SBOX[8][4][16] = { { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 },
{ 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8 },
{ 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0 },
{ 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 2, 14, 10, 0, 6, 13 } },

{ { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10 },
{ 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5 },
{ 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15 },
{ 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 } },

{ { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8 },
{ 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1 },
{ 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7 },
{ 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 } },

{ { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15 },
{ 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9 },
{ 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4 },
{ 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 } },

{ { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9 },
{ 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6 },
{ 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14 },
{ 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 } },

{ { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11 },
{ 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8 },
{ 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6 },
{ 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 } },

{ { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1 },
{ 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6 },
{ 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2 },
{ 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 } },


{ { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7 },
{ 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2 },
{ 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8 },
{ 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } } };

int round1 = 0;

char plainTextIn[16];
int beforeIp_64[64];
int afterIp_64[64];
int afterIp[16];
int leftBool[32];
char leftText[8];
int rightBool[48];
int rightText[8];


int keyIn[16] = { 10,5,2,4,9,12,11,8,1,3,9,5,12,8,11,2 };
int keyBool[64];
int leftKey[48];
int rightKey[48];
int keyText[16];
int resultKey[48];

void function();
void key_function();
void result_pc2();
void shift();
void ip();
void firstKey();
void ip_1();

void des() {

	ip();
	firstKey();
	for (int i = 0; i < 16; i++) {    //16번 돌아요~~~ ><
		key_function();
		function();
	}
	ip_1();

}


void ip() {
	//평문 입력
	printf("Plaintext 입력 : ");


	//평문 64비트 전환
	for (int i = 0; i < 8; i++) {
		beforeIp_64[8 * i + 7] = plainTextIn[i] % 2;
		beforeIp_64[8 * i + 6] = plainTextIn[i] / 2 % 2;
		beforeIp_64[8 * i + 5] = plainTextIn[i] / 4 % 2;
		beforeIp_64[8 * i + 4] = plainTextIn[i] / 8 % 2;
		beforeIp_64[8 * i + 3] = plainTextIn[i] / 16 % 2;
		beforeIp_64[8 * i + 2] = plainTextIn[i] / 32 % 2;
		beforeIp_64[8 * i + 1] = plainTextIn[i] / 64 % 2;
		beforeIp_64[8 * i] = plainTextIn[i] / 128 % 2;
	}

	//초기순열(IP) 적용 후
	for (int i = 0; i < 64; i++) {
		afterIp_64[i] = beforeIp_64[IP[i] - 1];
	}


	for (int i = 0; i < 32; i++) {
		leftBool[i] = afterIp_64[i];
		rightBool[i] = afterIp_64[i + 32];
	}

	//16진수로 다시 전환
	for (int i = 0; i < 8; i++) {
		leftText[i] = afterIp_64[4 * i] * 8 + afterIp_64[4 * i + 1] * 4 + afterIp_64[4 * i + 2] * 2 + afterIp_64[4 * i + 3];
	}

	for (int i = 8; i < 16; i++) {
		rightText[i] = afterIp_64[4 * i] * 8 + afterIp_64[4 * i + 1] * 4 + afterIp_64[4 * i + 2] * 2 + afterIp_64[4 * i + 3];
	}
}


void function() {

	int temp1[32], temp2[32];
	//rightbool 저장(스왑하기 위해)
	for (int i = 0; i < 32; i++) {
		temp1[i] = rightBool[i];
	}
	//e table, 키와 R을 xor연산
	for (int i = 0; i < 48; i++) {
		rightBool[i] = temp1[E[i] - 1];
		if (rightBool[i] == resultKey[i])rightBool[i] = 0;
		else rightBool[i] = 1;

	}
	//sbox
	int row, column, result;
	for (int i = 0; i < 8; i++) {
		row = rightBool[6 * i] * 2 + rightBool[6 * i + 5];
		column = rightBool[6 * i + 1] * 8 + rightBool[6 * i + 2] * 4 + rightBool[6 * i + 3] * 2 + rightBool[6 * i + 4];
		result = SBOX[i][row][column];


		rightBool[4 * i + 3] = result % 2;
		rightBool[4 * i + 2] = result / 2 % 2;
		rightBool[4 * i + 1] = result / 4 % 2;
		rightBool[4 * i] = result / 8 % 2;

	}

	for (int i = 0; i < 32; i++) {
		temp2[i] = rightBool[i];
	}

	//p 순열
	for (int i = 0; i < 32; i++) {
		rightBool[i] = temp2[P[i] - 1];
	}
	//L 과 R xor 연산
	for (int i = 0; i < 32; i++) {
		if (rightBool[i] == leftBool[i]) {
			rightBool[i] = 0;
		}
		else rightBool[i] = 1;
		leftBool[i] = temp1[i];
	}

	//16진수로 전환
	for (int i = 0; i < 8; i++) {
		leftText[i] = leftBool[4 * i] * 8 + leftBool[4 * i + 1] * 4 + leftBool[4 * i + 2] * 2 + leftBool[4 * i + 3];
		rightText[i] = rightBool[4 * i] * 8 + rightBool[4 * i + 1] * 4 + rightBool[4 * i + 2] * 2 + rightBool[4 * i + 3];
	}



	round1 += 1;
}



//처음 키
void firstKey() {

	for (int i = 0; i < 16; i++) {
		keyBool[4 * i + 3] = keyIn[i] % 2;
		keyBool[4 * i + 2] = keyIn[i] / 2 % 2;
		keyBool[4 * i + 1] = keyIn[i] / 4 % 2;
		keyBool[4 * i] = keyIn[i] / 8 % 2;
	}
	int temp[64];
	for (int i = 0; i < 64; i++) {
		temp[i] = keyBool[i];
	}
	for (int i = 0; i < 56; i++) {
		keyBool[i] = temp[PC_1[i] - 1];
	}
	for (int i = 0; i < 28; i++) {
		leftKey[i] = keyBool[i];
		rightKey[i] = keyBool[i + 28];
	}
}


void result_pc2() {
	int temp[56];
	for (int i = 0; i < 56; i++) {
		temp[i] = keyBool[i];
	}
	for (int i = 0; i < 48; i++) {
		resultKey[i] = temp[PC_2[i] - 1];
	}

}


//키
void key_function() {
	for (int i = 0; i<shiftNum[round1]; i++) {
		shift();
	}

	for (int i = 0; i < 28; i++) {
		keyBool[i] = leftKey[i];
		keyBool[i + 28] = rightKey[i];
	}

	result_pc2();
}


void shift() {
	int temp;
	temp = leftKey[0];
	for (int i = 0; i < 27; i++) {
		leftKey[i] = leftKey[i + 1];
	}
	leftKey[27] = temp;

	temp = rightKey[0];
	for (int i = 0; i < 27; i++) {
		rightKey[i] = rightKey[i + 1];
	}
	rightKey[27] = temp;
}

void ip_1() {
	int temp[64], temp1[64] = { 0, };


	for (int i = 0; i < 32; i++) {
		temp[i] = rightBool[i];
		temp[i + 32] = leftBool[i];
	}


	for (int i = 0; i < 64; i++) {
		temp1[i] = temp[IP_1[i] - 1];
	}

	for (int i = 0; i < 8; i++) {
		leftText[i] = temp1[4 * i] * 8 + temp1[4 * i + 1] * 4 + temp1[4 * i + 2] * 2 + temp1[4 * i + 3];
	}
	for (int i = 8; i < 16; i++) {
		rightText[i] = temp1[4 * i] * 8 + temp1[4 * i + 1] * 4 + temp1[4 * i + 2] * 2 + temp1[4 * i + 3];
	}

	printf("\n\n");
	for (int i = 0; i < 8; i++) {
		printf("%x", leftText[i]);
	}
	for (int i = 8; i < 16; i++) {
		printf("%x", rightText[i]);
	}
	printf("\n");
}