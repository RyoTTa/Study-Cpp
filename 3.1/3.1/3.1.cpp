#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class USERDATA {
public:
	int nAge;
	char szName[32];

	void Pirnt(void) {
		cout << this->nAge << ' ' << this->szName << endl;
	}
};

class USERDATA2 {
public:
	
	int nAge;
	string szName;

	USERDATA2() {
		nAge = 10;
		szName = "철수";
	}

	void PrintData(void);
};

void USERDATA2::PrintData(void) {
	cout << this->nAge << ' ' << this->szName << endl;
}

class USERDATA3 {
public:
	int rData = 0;

	USERDATA3() {
		cout << "생성자" << endl;
	}
	USERDATA3(int Param) {
		this->rData = Param;
	}
	~USERDATA3() {
		cout << "소멸자 rData = " << this->rData << endl;
	}
};

class USERDATA4 {
public:
	USERDATA4(int &rParam) : m_nData(rParam) {};	//참조자는 선언과 동시에 초기화 필요
	int GetData(void) { return m_nData; }

private:
	int &m_nData;
};

class USERDATA5 {
public:
	USERDATA5(int x) {
		if (x > 100)
			x = 100;
		m_x = 100;
	
	}
	USERDATA5(int x, int y) : USERDATA5(x){
		if (y > 200)
			y = 200;
		m_y = 200;
	}
	void Print() {
		cout << "X : " << m_x << endl;
		cout << "Y : " << m_y << endl;
	}

private:
	int m_x = 0;
	int m_y = 0;
};

int main()
{
	//structure 형식으로 사용한 class
	USERDATA user = { 10, "철수" };
	user.Pirnt();

	//생성자 함수 사용한 class 및 함수 정의 분리
	USERDATA2 t;
	t.PrintData();

	//생성자 및 소멸자(생성자 오버로딩 가능, 소멸자 불가능)
	cout << "Begin" << endl;
	USERDATA3 a;
	cout << "Before b" << endl;
	USERDATA3 b(2);
	cout << "End" << endl;
	
	//돌적 객체 생성 및 소멸
	USERDATA3 *t2 = new USERDATA3;
	cout << "Test" << endl;
	delete t2;
	cout << "End" << endl;

	//참조 형식 멤버 초기화
	int aa = 10;
	USERDATA4 t3(aa);

	cout << t3.GetData() << endl;
	aa = 20;
	cout << t3.GetData() << endl;

	//생성자 위임
	USERDATA5 t

	return 0;
}