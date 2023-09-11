#pragma once
#include <string>

extern "C"
{
	__declspec(dllimport) const char* GetCodename();
	__declspec(dllimport) double sumar(double a, double b);
	__declspec(dllimport) std::string* concatenacion(std::string* A, std::string* B, std::string* C);
}