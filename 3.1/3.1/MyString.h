#pragma once
class CMyString
{
public:
	CMyString();
	~CMyString();

private:
	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;

	// ����� ���ڿ� ����
	int m_nLength;
public:
	int SetString(const char* pszPram);
	const char* GetString();
	void Release();
};

