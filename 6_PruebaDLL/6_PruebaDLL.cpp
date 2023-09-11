// 6_PruebaDLL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

int main()
{
    //cargar la dll
    HINSTANCE mydll = LoadLibrary(L"6_dll.dll");
    //comprobar si cargó la dll
    if (mydll != NULL)
    {
        puts("Se cargo la DLL :)");
        //cargar la funcion GetCodeName
        typedef const char* (*GetCodeNameFunc)();
        GetCodeNameFunc getCodename = reinterpret_cast<GetCodeNameFunc>(GetProcAddress(mydll, "GetCodeName"));
        if (getCodename != NULL)
        {
            const char* mensaje = getCodename();
            std::cout << "desde la DLL: " << mensaje << "\n";
        }
        else
        {
            puts("No se encontro la función");
        }

        //cargar la funcion Sumar
        typedef double (*SumarFunc)(double a, double b);
        SumarFunc sumar = reinterpret_cast<SumarFunc>(GetProcAddress(mydll, "Sumar"));
        if (sumar != NULL)
        {
            std::cout << "prueba de suma: " << sumar(3.1416, 1.414) << "\n";
        }
        else
        {
            puts("No se encontro la función");
        }

        //cargar la funcion Contatenar
        typedef std::string(*ConcatenarFunc)(const std::string& A, const std::string& B);
        ConcatenarFunc concatenar = reinterpret_cast<ConcatenarFunc>(GetProcAddress(mydll, "Concatenar"));
        if (concatenar != NULL)
        {
            std::cout << "Concatenacion: " << concatenar("Hola, ", "mundo") << "\n";
        }
        else
        {
            puts("No se encontro la funcion");
        }
        FreeLibrary(mydll);
    }
    else
    {
        puts("No se pudo cargar la DLL");
    }

    return 0;
}


