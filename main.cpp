#include <iostream>
#include <cmath>
#include <cstring>
#include <stdlib.h>

using namespace std;

int valorChar (char numero, int base)
{
    int valor = -1;
    if(numero >= '0' && numero <= '9')
    {
        valor = numero - '0';
    }
    else
    {
        numero = toupper(numero);
        if(numero >= 'A' && numero <= 'Z')
        {
            valor = numero - 'A' + 10;
        }
        else
        {
            cout << "Error: Fuera del rango 0-9, A-O";
            valor = -1;
        }
    }
    if(valor > base - 1)
    {
        cout << "Error: Digito debe ser menor que " << base << endl;
        valor = -1;
    }
    return valor;
}

int n_dec (char *numero, int base)
{
    int a = 0, total = 0;
    double dbase = (double)base;

    for(int i = strlen(numero) - 1; i >= 0; i--)
    {
        total = total + pow(dbase, a) * valorChar(numero[i], base);
        a++;
    }

    return total;
}

string dec_m (int numero, int base)
{
    string rango = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string resultado = "";

    while(numero > 0)
    {
        resultado = rango[numero % base] + resultado;
        numero = numero / base;
    }

    return resultado;
}

int main()
{
    const int MAX = 100;
    int baseN, baseM, opc = 0;
    char numero[MAX];

    do
    {
        system("cls");
        cout << "------------ Calculadora de bases---------" << endl;
        cout << endl;
        cout << "1.- Calcular" << endl;
        cout << endl;
        cout << "0.- Salir" << endl;
        cout << endl;
        cout << "Ingresa la opcion deseada: ";
        cin >> opc;
        switch (opc)
        {
            case 1:
            {
                system("cls");
                cout << "------------ Calculadora de bases---------" << endl;
                cout << endl;
                cin.ignore();
                cout << "Ingresa en numero a convertir: ";
                cin.getline(numero, MAX);
                cout << "Ingresa la base n: ";
                cin >> baseN;
                cout << "Ingresa la base m: ";
                cin >> baseM;
                cout << "El resultado es :" << dec_m(n_dec(numero, baseN), baseM)  << endl;
                system("pause");
                break;
            }
            case 0:
            {
                cout << "Saliendo ..." << endl;
                break;
            }
            default:
            {
                cout << "Opcion no valida !" << endl;
                system("pause");
                break;
            }
        }
    }while(opc != 0);

    cout << "Hello world!" << endl;

    return 0;
}
