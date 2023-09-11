#pragma 
#include <string>

extern "C"
{
	__declspec(dllimport) const char* GetCodeName();
	__declspec(dllimport) double Sumar(double a, double b);
	__declspec(dllimport) std::string Concatenar(const std::string A, const std::string B);
}