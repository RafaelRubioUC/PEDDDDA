#include <iostream>
#include <string>
#include <list>

struct Miembros
{
    std::string nombre;
    std::string apellido;
    std::string direccion;

    int edad;
};

struct Clubs
{
    std::string nombre_club;
    std::string fecha_de_creacion;
    int capacidad_maxima;
    int miembros_disponibles = 0;
    int miembros_totales = 0;
};

void AgregarClubs(std::list<Clubs> &lista_clubs);
void AgregarMiembros(std::list<Miembros> &listaMiembros, std::list<Clubs> &lista_clubs);
void MostrarClubs(std::list<Clubs> lista_clubs);