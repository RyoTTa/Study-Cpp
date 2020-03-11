#pragma once
class CMyString
{
public:
	CMyString();
	~CMyString();

private:
	// 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
	char* m_pszData;

	// 저장된 문자열 길이
	int m_nLength;
public:
	int SetString(const char* pszPram);
	const char* GetString();
	void Release();
};

