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

    typedef std::string(*concatFunc)(const std::string& A, const std::string& B, const std::string& C);
    concatFunc concatenacion = reinterpret_cast<concatFunc>(GetProcAddress(mydll, "concatenacion"));
    if (concatenacion != NULL)
    {
        std::cout << "prueba de concatenacion " << concatenacion("Hola", "ojo", "ojoooooooo") << "\n";
    }

    FreeLibrary(mydll);

    puts("hola");
    return 0;



    typedef std::string(*ConcatenarFunc)(const std::string& A, const std::string& B);
    ConcatenarFunc concatenar = reinterpret_cast<ConcatenarFunc>(GetProcAddress(mydll, "Concatenar"));
    if (concatenar != NULL)
    {
        std::cout << "Concatenacion: " << concatenar("Hola, ", "mundo") << "\n";
    }
}