#include<iostream>
using  std::cout;
using  std::endl;

extern "C" _declspec(dllexport)
int printMax(int a, int b)
{
	cout << "the max number is: " << ((a>b) ? a : b) << endl;
	return 0;
}