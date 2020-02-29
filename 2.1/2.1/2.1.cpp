#include "pch.h"
#include <iostream>

#define ADD(a,b)((a)+(b))

using namespace std;

int TestFunc(int = 20);
int TestFunc(int nParam) {
	return nParam;
}

int TestFunc2(int nParam1, int nParam2 = 2) {

	return nParam1 * nParam2;
}

int Add(int a, int b, int c) {
	std::cout << "Add(int, int ,int)" << std::endl;

	return a + b + c;
}
int Add(int a, int b) {
	std::cout << "Add(int, int)" << std::endl;

	return a + b;
}
double Add(double a, double b) {
	std::cout << "Add(double, double)" << std::endl;

	return a + b;
}

template <typename T>
T TestFunc3(T a, T b) {

	return a + b;
}

inline int AddNew(int a, int b) {
	
	return a + b;
}

namespace TEST {
	int g_nData = 100;

	void TestFunc4(void) {
		std::cout << "TEST::TestFunc4()" << std::endl;
	}

	int TestFunc(void) {
		return 30;
	}
}

namespace TEST2 {
	int g_nData = 100;
	namespace DEV {
		int g_nData = 200;
		namespace WIN {
			int g_nData = 300;
		}
	}
}

int main()
{
	//디폴트 매개변수
    std::cout << TestFunc() << std::endl;
	std::cout << TestFunc(10) << std::endl;

	/*여러개의 디폴트매개변수
		매개변수의 왼쪽부터 함수짝을 맞춘다
		오른쪽 매개변수부터 디폴트값을 기술
		디폴트값을 기술하려면 나머지 오른쪽 모든 매개변수에 디폴트값을 기술

	*/
	std::cout << TestFunc2(10) << std::endl;
	std::cout << TestFunc2(10, 5) << std::endl;

	//오버로딩(다중정의)
	std::cout << Add(3, 4) << std::endl;
	std::cout << Add(2, 3, 4) << std::endl;
	std::cout << Add(3.3, 4.4) << std::endl;

	//템플릿
	std::cout << TestFunc3<int>(3, 4) << std::endl;
	std::cout << TestFunc3<double>(3.3, 4.4) << std::endl;

	//인라인 함수(매크로+함수)
	std::cout << ADD(1, 2) << std::endl;	//매크로
	std::cout << AddNew(2, 3) << std::endl;	//인라인(컴파일러 차이)

	//네임스페이스
	TEST::TestFunc4();
	std::cout << TEST::g_nData << std::endl;	//namespace내 변수 및 함수 사용

	cout << "using namespace" << endl;	//using 사용

	cout << TEST2::g_nData << endl;	//namespace 중첩
	cout << TEST2::DEV::g_nData << endl;
	cout << TEST2::DEV::WIN::g_nData << endl;

	cout << TestFunc() << endl;	//묵시적 전역
	cout << ::TestFunc() << endl; //명시적 전역
	cout << TEST::TestFunc() << endl;


	return 0;
}