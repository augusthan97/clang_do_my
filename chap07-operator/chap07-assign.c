﻿/*
*	chap07-operator.c
*	연산자 예제
* ---------------------------------------------
*	1. 대입연산자, 산술연산자, 증감연산자, 관계연산자, 논리연산자
*	2. 연산자의 우선순위와 연산방향
*/


#include <stdio.h>

#define MAX_CHAR    127
#define MAX_SHORT   32767
#define MAX_INT     2147483647
#define MAX_UCHAR   0xff        //256
#define MAX_USHORT  0xffff      //65535
#define MAX_UINT    0xffffffff  //4294967295

void assignInt();
void assignUInt();
void assignFloatDouble();
void assignCasting();
void assignCastingReal();
void assignLoss();

void main() {
	assignInt();
	assignUInt();
	assignFloatDouble();	
	assignCasting();
	assignCastingReal();
	assignLoss();

}

// 대입연산자( = ), 같다는 의미가 아니다.
// a를 b에 대입한다 : b = a
// 1. 대입이 되는 대상의 원래 값은 사라진다.
// 2. 양쪽 모두 동일한 자료형이어야 한다.
//	char | char		short | short		int | int		float | float		double | double

void assignInt() {
	int a = 1;		// signed (부호가 있는 정수 )
	int b = 2;		// b의 원래값은 사라진다.
	b = a;

	int c = b;
	int d = 123456;

	int dd = 32767;
	char cc = dd;
	char c1 = 32767;
	/*
	양수( + )의 값을 signed에서 unsigned로 대입할때는 문제가 없다.
	음수( - )의 값을 signed에서 unsigned로 대입할때는 문제가 발생한다.
	*/
	
	printf("a를 b에 대입(b=a)할때, a의 값:(%d) ,  b의 값:(%d)\n", a, b);
	printf("선언과 동시에 c에 b를 대입(c=b), c의 값:(%d) ,  b의 값:(%d)\n", c, b);
	
	unsigned int ud = d;
	printf("int -> char을 하게되면 컴파일러 경고!  dd(%d) cc(%d)\n\n", dd, cc);
}

void assignUInt() {
	
	/*
	양수( + )의 값을 signed에서 unsigned로 대입할때는 문제가 없다.
	음수( - )의 값을 signed에서 unsigned로 대입할때는 문제가 발생한다.
	(오버플로우가 발생하여 minus(-)가 된다.)
	그 값을 unsigned로 대입하게 되면 정상적인 값을 얻을 수 있다.
	*/
	int plus = 1;
	int sd = MAX_INT + plus;
	unsigned int ud = sd;

	printf("sd(%d), ud(%u)\n\n", sd, ud);
	
}
/*
 3. 같은 형태의 자료형에서 서로 자료형의 크기가 다른경우 데이터의 손실?
		- signed , unsigned
		- float(e38) , double(e308) : 유효자리, 지수의 크기

	float에서 Double로 대입시 문제가 없다.
	Double에서 float로 대입시 값의 손실이 발생될 수 있다.
*/
void assignFloatDouble() {
	float a = 0.123456f;	// 맨 뒤에 f를 붙여야 한다.
	double b = 0.123456789; // 맨 뒤에 f가 없으면 double형 이다.


	printf("Float : a(%f)\n", a);			// 기본 6자리까지 출력
	printf("Double : b(%15.10f)\n\n", b);			
		
//	float c = b; // 손실발생
//	printf("Double을 float에 대입후 Float c의 값 : %15.10f\n\n", c);
}

/*
	3. 양쪽의 자료형의 속성이 다르면 캐스팅(casting)을 해야한다.
	- int 에서 char로 캐스팅을 하게되면 데이터 손실이 발생될 수 있다.
	- 캐스팅을 ㅎ게되면 컴파일러 경고가 발생되지 않는다.
	ex) float ff = 89.12345f;
		int df = (int)ff;
	
*/
void assignCasting() {
	char c = 'A';		// 1바이트 문자, 정수처럼 사용된다.
	short cs = c;		// 2바이트 정수
	int cx = c;			// 4바이트 정수 손실발생

	float ff = 89.12345f;
	int df = (int)ff;			// int로 변환하면서 소숫점 이하의 값 소실
	float f1 = (float)df;		// 소숫점값 소실로 0으로 표시
	
	int dm = MAX_INT;
	float f2 = (float)dm;

	printf("char -> short 는 캐스팅이 필요없다. c(%c), cs(%c)(%d)\n", c, cs, cs);
	printf("char -> int 는 캐스팅이 필요없다. c(%c), cx(%c)(%d)\n", c, cx, cx);
	printf("float(%f) -> int(%d)\n", ff, df);
	printf("int(%d) -> float(%f)\n", df, f1);
	printf("int(%d) -> float(%f)\n\n", dm, f2);
}

void assignCastingReal() {
	float a = 0.123456f;	// 맨 뒤에 f를 붙여야 한다.
	double b = 0.123456789; // 맨 뒤에 f가 없으면 double형 이다.
	float c = (float)b; // 손실발생


	printf("Float : a(%f)\n", a);			// 기본 6자리까지 출력
	printf("Double : b(%15.10f)\n", b);
	printf("Double을 float에 대입후 Float c의 값 : %15.10f\n\n", c);
	
}

/*
*	큰 자료형의 데이터를 작은 자료형으로 대입하면 손실이 발생할 수 있다.
*/
void assignLoss() {
	int d1 = 255;
	int d2 = 256;
	char c1 = (char)d1;
	char c2 = (char)d2;

	printf("d1(%d) (%08x), d2(%d) (%08x), c1(%d) (%x), c2(%d) (%x)\n", d1, d1, d2, d2, c1, c1, c2, c2);
}