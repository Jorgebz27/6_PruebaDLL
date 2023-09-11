#include <iostream>
#include <Windows.h>

int main()
{
    //cargar la dll
    HINSTANCE mydll = LoadLibrary(L"6_DLL.dll");

    //comprobar si cargo la dll
    if (mydll != NULL)
    {
        puts("Se cargo la DLL");
        typedef const char* (*GetCodenameFunc)();
        GetCodenameFunc getcodename = reinterpret_cast<GetCodenameFunc>(GetProcAddress(mydll, "GetCodename"));
        if (getcodename != NULL)
        {
            const char* mensaje = getcodename();
            std::cout << "desde la DLL " << mensaje << "\n";
        }
    }
    else
    {
        puts("No se pudo cargar la DLL");
    }

    typedef double (*sumarFunc)(double a, double b);
    sumarFunc sumar = reinterpret_cast<sumarFunc>(GetProcAddress(mydll, "sumar"));
    if (sumar != NULL)
    {
        std::cout << "prueba de suma " << sumar(3.1416, 23456) << "\n";
    }

    typedef std::string* (*concatFunc)(std::string * A, std::string * B, std::string * C);
    concatFunc concatenacion = reinterpret_cast<concatFunc>(GetProcAddress(mydll, "concatenacion"));
    if (concatenacion != NULL)
    {
        std::string A = "Hola";
        std::string B = "Hola";
        std::string C = "Hola";
        std::cout << "prueba de concatenacion " << concatenacion(A, B, C) << "\n";
    }

    FreeLibrary(mydll);

    puts("hola");
    return 0;
}