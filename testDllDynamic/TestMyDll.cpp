#include<Windows.h>  
#include<iostream>
using namespace std;

int main()
{
	//加载dll
	HMODULE module = LoadLibrary(TEXT("..\\Debug\\myDllGenerate.dll"));
	if (module == NULL)
	{
		cout << "load dll error!" << endl;
		FreeLibrary(module);
		return 1;
	}
	//从dll中导出函数地址
	typedef void(*printMaxFunc)(int, int); // 定义函数指针类型
	printMaxFunc printMax;
	printMax = (printMaxFunc)GetProcAddress(module, "printMax");
	GetLastError();
	if (printMax == NULL)
	{
		cout << "get dll error!" << endl;
		FreeLibrary(module);
		return 1;
	}
	//测试dll
	int c = 3;
	int d = 2;
	printMax(c, d);
	//释放
	FreeLibrary(module);//与LoadLibrary成对出现，颇有new delete的意思
	return 0;
}