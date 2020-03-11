#include "pch.h"
#include "MyString.h"


CMyString::CMyString()
	:m_pszData(nullptr),
	m_nLength(0)
{
}


CMyString::~CMyString()
{
}


int CMyString::SetString(const char* pszPram)
{
	Release();

	if (pszPram == NULL) {
		return 0;
	}

	int nLength = strlen(pszPram);

	if (nLength == 0) {
		return 0;
	}

	m_pszData = new char[nLength + 1];

	strcpy_s(m_pszData, sizeof(char)* (nLength + 1), pszPram);
	m_nLength = nLength;

	return m_nLength;
}


const char* CMyString::GetString()
{
	return m_pszData;
}


void CMyString::Release()
{
	if (m_pszData != NULL) {
		delete[] m_pszData;
	}
	
	m_pszData = NULL;
	m_nLength = 0;
}
