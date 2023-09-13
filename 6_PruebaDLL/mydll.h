#pragma once
#include <string>

extern "C"
{
	__declspec(dllimport) const char* GetCodename();
	__declspec(dllimport) double sumar(double a, double b);
	__declspec(dllimport) std::string concatenacion(const std::string A, const std::string B, const std::string C);
}