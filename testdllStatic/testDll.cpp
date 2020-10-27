#include<iostream>
#include"..\\myDllGenerate\\myDll.h" 
using namespace std;

#pragma comment (lib,"..\\Debug\\myDllGenerate.lib")

int main()
{
	int c = 3;
	int d = 2;
	printMax(c, d);
	return 0;
}