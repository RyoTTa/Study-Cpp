#include "pch.h"
#include <iostream>
#include <string>
#include <cstdio>

void callByReference(int &rParam) {

	rParam = 100;
}
int main(int argc, char* argv[])
{
	//출력
    std::cout << "Hello World!" << std::endl; 

	std::cout << 2 + 4 << std::endl;

	//입력
	std::cout << "Typing to anythings" << std::endl;
	std::string temp;
	//std::cin >> temp;
	//std::cout << temp << std::endl;
	
	//자료형
	int a = 99;
	int b(a);
	auto c(b);
	std::cout << c << std::endl;

	//동적할당
	int *pInt = new int;
	int *pIntA = new int[10];
	*pInt = 10;
	pIntA[0] = 11;
	std::cout << *pInt <<' '<< pIntA[0] << std::endl;
	delete pInt;
	delete[] pIntA;

	//참조자
	int nInt = 12;
	int &ref = nInt;
	std::cout << ref << std::endl;
	ref = 13;
	std::cout << ref << std::endl;
	callByReference(nInt);
	std::cout << ref << std::endl;

	//r-value(연산에 활용된 직후 소멸하는 r-value ??)
	int &&rvdata = 2;
	std::cout << rvdata << std::endl;

	//Range-based FOR
	int aList[5] = {10,20,30,40,50};

	for (auto n : aList)
		std::cout << n << ' ';
	std::cout << std::endl;
	for (auto &n : aList)
		n = 10;
	for (auto n : aList)
		std::cout << n << ' ';
	std::cout << std::endl;
	

	return 0;
}
