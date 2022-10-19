#include <iostream>
#include <cstdio>
#include <cmath>
#include <windows.h>
#include <limits>

void muestra_info(struct Alumno  &a);
void pedir_info();
void syllabus(struct Alumno  &a);
double value(double x);
int valueInt(int x);

using namespace std;

struct Alumno {
    int ncuenta;
    string name;
    string nombre;
    string fecha_ing;
    int sem;
    int gpo;
    double prom_p1;
    double prom_p2;
    double prom_p3;
    int edad;
};

Alumno a;
Alumno b;
Alumno c;

int main() {

    a.ncuenta = 101010;
    a.name = "A";
    a.nombre = "Beatriz De La Paz Arellanos";
    a.fecha_ing = "1/07/2001";
    a.sem = 1;
    a.gpo = 3;
    a.prom_p1 = 7.22;
    a.prom_p2 = 6.32;
    a.prom_p3 = 3.5;
    a.edad = 18;

    b.ncuenta = 191919;
    b.name = "B";
    b.nombre = "Daniel Robles Guzmán";
    b.fecha_ing = "11/07/2001";
    b.sem = 1;
    b.gpo = 1;
    b.prom_p1 = 6.5;
    b.prom_p2 = 9.44;
    b.prom_p3 = 8.8;
    b.edad = 19;

    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
    system("color 0c");

    cout << "\t\t" << "*** Estructuras ***" << endl;
    muestra_info(a);
    cout << endl;
    cout << "\t" << "Tamaño en Bytes de la estructura (a): " << sizeof(a) << endl;
    cout << "\t" << "***************************************************************" << endl;
    system("pause");
    system("cls");

    muestra_info(b);
    cout << endl;
    cout << "\t" << "Tamaño en Bytes de la estructura (b): " << sizeof(b) << endl;
    cout << "\t" << "***************************************************************" << endl;
    system("pause");
    system("cls");

    cout << "\t" << "Solicitar información de (c) " << endl;
    pedir_info();
    system("pause");
    system("cls");
    cout << "\t" << "*****************************************************" << endl;
    cout << "\t" << "************** PROMEDIOS FINALES ********************" << endl;
    syllabus(a);
    system("pause");
    syllabus(b);
    system("pause");
    syllabus(c);


    return 0;
}

void  muestra_info(Alumno  &a) {
    system("cls");
    cout << "\t\t" << "Datos que contiene la estructura (" << a.name << ")" << endl;
    cout << "# Cuenta: " << a.ncuenta << endl;
    cout << "Nombre: " << a.nombre << endl;
    cout << "Fecha Ingreso: " << a.fecha_ing << endl;
    cout << "Semana: " << a.sem << endl;
    cout << "Grupo: " << a.gpo << endl;
    cout << "Promedio 1er Parcial: " << a.prom_p1 << endl;
    cout << "Promedio 2do Parcial: " << a.prom_p2 << endl;
    cout << "Promedio 3er Parcial: " << a.prom_p3 << endl;
    cout << "Edad: " << a.edad << endl;
}

void pedir_info() {
    c.name = "C";
    cout << "# Cuenta: ";
    c.ncuenta = valueInt(c.ncuenta);
    cout << endl;
    cout << "Nombre: ";
    getline(cin, c.nombre);
    cout << endl;
    cout << "Fecha Ingreso: ";
    getline(cin, c.fecha_ing);
    cout << endl;
    cout << "Semana: ";
    c.sem = valueInt(c.sem);
    cout << endl;
    cout << "Grupo: ";
    c.gpo = valueInt(c.gpo);
    cout << endl;
    cout << "Promedio 1er Parcial: ";
    c.prom_p1 = value(c.prom_p1);
    cout << endl;
    cout << "Promedio 2do Parcial: ";
    c.prom_p2 = value(c.prom_p2);
    cout << endl;
    cout << "Promedio 3er Parcial: ";
    c.prom_p3 = value(c.prom_p3);
    cout << endl;
    cout << "Edad: ";
    c.edad = valueInt(c.edad);
    cout << endl;

    muestra_info(c);
}

double value(double x) {

    do {
        if (!(cin >> x)) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "\nError... Valor incorrecto...\n";
        }else {
            cout << endl;
            break;
        }
    }while (true);

    cin.ignore(numeric_limits<int>::max(), '\n');
    return x;
}

int valueInt(int n) {
    do {
        if (!(cin >> n) || n <= 0 ) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "\nError... Valor incorrecto...\n";
        }else {
            cout << endl;
            break;
        }
    }while (true);

    cin.ignore(numeric_limits<int>::max(), '\n');
    return n;
}

void syllabus(Alumno  &a) {
    double prom = a.prom_p1*0.3 + a.prom_p2 * 0.3 + a.prom_p3 * 0.4;

    if (prom < 7) {
        printf("\n %s NO ESTÁ APROBADO :( \n Promedio Final: %.0f \n", a.name.c_str(), round(prom));
    } else {
        printf("\n %s ESTÁ APROBADO :) \n Promedio Final: %.0f \n", a.name.c_str(), round(prom));
    }

}