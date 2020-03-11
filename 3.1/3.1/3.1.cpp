#include "pch.h"
#include <iostream>
#include <string>
#include "MyString.h"

namespace TEST {
	class USERDATA {
	public:
		int nAge;
		char szName[32];
		void Pirnt(void) {
			cout << this->nAge << ' ' << this->szName << endl;
		}
	};
}


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

class USERDATA6 {
public:
	USERDATA6(void) = default;
	int m_nData = 5;
};

class USERDATA7 {
public:
	USERDATA7(int nParam) : m_nData(nParam) {

	}
	USERDATA7() {}

	int Getdata() const {
		//Setdata(100);
		m_nData2 = 100;
		return m_nData;
	}

	void Setdata(int nParam) {
		this->m_nData = nParam;
	}

	void Setdata(double nParam) = delete;

	int TestFunc(const int &nParam) {
		int &nNewParam = const_cast<int &>(nParam);
		nNewParam = 100;
	}

	static int GetCount() {
		return ++m_nCount;
	}

private:
	int m_nData = 0;
	mutable int m_nData2 = 0;

	static int m_nCount;
};

int USERDATA7::m_nCount = 0;

int main()
{
	//structure 형식으로 사용한 class
	TEST::USERDATA user = { 10, "철수" };
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
	USERDATA5 t4(110);
	t4.Print();

	USERDATA5 t5(50, 250);
	t5.Print();

	//명시적 디폴트 생성자
	USERDATA6 t6;
	cout << t6.m_nData << endl;

	//실습1
	CMyString strData;
	strData.SetString("Hello");
	cout << strData.GetString() << endl;

	//상수형 메소드
	USERDATA7 t7(10);
	cout << t7.Getdata() << endl;
		//t7.Setdata(10.5);

	//정적 멤버
	cout << t7.GetCount() << endl;
	cout << USERDATA7::GetCount() << endl;

	return 0;
}