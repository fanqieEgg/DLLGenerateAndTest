#include<Windows.h>  
#include<iostream>
using namespace std;

int main()
{
	//����dll
	HMODULE module = LoadLibrary(TEXT("..\\Debug\\myDllGenerate.dll"));
	if (module == NULL)
	{
		cout << "load dll error!" << endl;
		FreeLibrary(module);
		return 1;
	}
	//��dll�е���������ַ
	typedef void(*printMaxFunc)(int, int); // ���庯��ָ������
	printMaxFunc printMax;
	printMax = (printMaxFunc)GetProcAddress(module, "printMax");
	GetLastError();
	if (printMax == NULL)
	{
		cout << "get dll error!" << endl;
		FreeLibrary(module);
		return 1;
	}
	//����dll
	int c = 3;
	int d = 2;
	printMax(c, d);
	//�ͷ�
	FreeLibrary(module);//��LoadLibrary�ɶԳ��֣�����new delete����˼
	return 0;
}