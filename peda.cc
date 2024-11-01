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
void MostrarMiembros(std::list<Miembros> listaMiembros);
int MostrarCantidadDeMiembros(std::list<Clubs> lista_clubs);

int main()
{
    std::list<Miembros> listaMiembros;
    std::list<Clubs> lista_clubs;
    int opcion;

    do
    {   
        system("cls");
        std::cout << "-----------------------------MENU--------------------------------" << std::endl << std::endl;
        std::cout << "1. Agregar clubs" << std::endl;
        std::cout << "2. Agregar miembros" << std::endl;
        std::cout << "3. Ver clubs" << std::endl;
        std::cout << "4. Ver miembros" << std::endl;
        std::cout << "5. Ver cantidad de miembros agregados" << std::endl;
        std::cout << "6. Salir" << std::endl << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            AgregarClubs(lista_clubs);
            std::cout << std::endl << std::endl;
            system("pause");
            break;

        case 2:
            system("cls");
            AgregarMiembros(listaMiembros, lista_clubs);
            std::cout << std::endl << std::endl;
            system("pause");
            break;

        case 3:
            system("cls");
            MostrarClubs(lista_clubs);
            std::cout << std::endl << std::endl;
            system("pause");
            break;

        case 4:
            system("cls");
            MostrarMiembros(listaMiembros);
            std::cout << std::endl << std::endl;
            system("pause");
            break;

        case 5:
            system("cls");
            if (!listaMiembros.empty()){
                
                std::cout << "La cantidad de miembros es de: " << MostrarCantidadDeMiembros(lista_clubs) << std::endl;

            }
            else{

                std::cout << "La lista de miembros esta vacia." << std::endl;

            }
            std::cout << std::endl << std::endl;
            system("pause");
            break;
        
        case 6:
            system("cls");
            std::cout << "Saliendo del programa..." << std::endl;
            break;
        
        default:
            system("cls");
            std::cout << "Opcion invalida, intente de nuevo." << std::endl;
            break;
        }

    } while (opcion != 6);
    
    
    return 0;
}

void AgregarClubs(std::list<Clubs> &lista_clubs){

    Clubs informacion;
    int posicion;
    int n;

    std::cout << "Donde desea agregar el club?(al inicio = 1, al final = 2): ";
    std::cin >> posicion;

    std::cout << "Ingrese el nombre del club: ";
    std::cin >> informacion.nombre_club;
    std::cout << "Ingrese la fecha de creacion del club: ";
    std::cin >> informacion.fecha_de_creacion;
    std::cout << "Ingrese capacidad maxima del club: ";
    std::cin >> informacion.capacidad_maxima;
    informacion.miembros_disponibles = informacion.capacidad_maxima;

    if (posicion == 1){
        lista_clubs.push_front(informacion);
        std::cout << std::endl;
        std::cout << "Se agrego el club al Inicio!" << std::endl;
    }
    else if (posicion == 2){
        lista_clubs.push_back(informacion);
        std::cout << std::endl;
        std::cout << "Se agrego el club al final!" << std::endl;
    }
    else{
        std::cout << "Valor invalido." << std::endl;
    }
    
}

void AgregarMiembros(std::list<Miembros> &listaMiembros, std::list<Clubs> &lista_clubs){

    if (!lista_clubs.empty()){
        
        Clubs informacion;
        Miembros datos;
        std::string agregar;
        bool club_encontrado = false;
        int posicion;
        int agregar_otro_miembro;
        int i = 1;

        for(auto &informacion : lista_clubs){

            if (informacion.miembros_disponibles != 0){
                std::cout << i++ << ". " << informacion.nombre_club << std::endl; 
            }
            
        }
        std::cout << std::endl << std::endl;
        std::cout << "Ingrese el nombre del club al cual desea agregarle miembros: ";
        std::cin >> agregar;

        for(auto &informacion : lista_clubs){

        if (informacion.nombre_club == agregar){
            std::cout << "El club existe." << std::endl;    
            club_encontrado = true;

        for (int j = 0; j < informacion.capacidad_maxima; j++)
        {
          system("cls");
          std::cout << "Miembros disponibles para agregar: " << informacion.miembros_disponibles << std::endl;
          std::cout << "Donde desea agregar al miembro?(al inicio = 1, al final = 2): ";
          std::cin >> posicion; 
        
          datos.direccion = informacion.nombre_club;
          std::cout << "Ingrese el nombre del miembro: ";
          std::cin >>  datos.nombre;
          std::cout << "Ingrese el apellido del miembro: ";
          std::cin >>  datos.apellido;
          std::cout << "Ingrese la edad del miembro: ";
          std::cin >>  datos.edad;
          informacion.miembros_disponibles--;
          informacion.miembros_totales++;


          if (posicion == 1){

             listaMiembros.push_front(datos);
             std::cout << std::endl << std::endl;
             std::cout << "El miembro fue agregado al inicio." << std::endl;

          }
          else if (posicion == 2){

             listaMiembros.push_back(datos);
             std::cout << std::endl << std::endl;
             std::cout << "El miembro fue agregado al final." << std::endl;

          }
          else{
            std::cout << "Posicion invalida." << std::endl;
          }
          
          if (informacion.miembros_disponibles != 0){
            std::cout << "Miembros disponibles para agregar: " << informacion.miembros_disponibles << std::endl;
            std::cout << "Desea agregar otro miembro a este club?(si = 1, no = 2): ";
            std::cin >> agregar_otro_miembro;

            if (agregar_otro_miembro == 1){
                continue;
            }
            else if (agregar_otro_miembro == 2){
                break;
            }
            else{
                std::cout << "Opcion invalida." << std::endl;
            }
                            
          }
          else{
            std::cout << "No hay mas espacio para agregar miembros." << std::endl;
            break;
          }
            
        }
     }
            
  }
        if (club_encontrado == false){
            std::cout << "El club no existe." << std::endl;
        }
        
    }   
    else{
        std::cout << "No hay clubes a los cuales agregar miembros." << std::endl;
    }
}

void MostrarClubs(std::list<Clubs> lista_clubs){

    Clubs informacion;

    if (!lista_clubs.empty()){

    for(auto &informacion :  lista_clubs){

        std::cout << "Nombre del club: " << informacion.nombre_club << std::endl;
        std::cout << "Capacidad maxima: " << informacion.capacidad_maxima << std::endl;
    }

    }
    else{

        std::cout << "La lista esta vacia." << std::endl;
    }
    
}

void MostrarMiembros(std::list<Miembros> listaMiembros){

    Miembros informacion;

    if (!listaMiembros.empty())
    {
        for(auto &informacion : listaMiembros){

        std::cout << "Club al que pertenecen: " << informacion.direccion << std::endl;
        std::cout << "Nombre: " << informacion.nombre << std::endl;
        std::cout << "Apellido: " << informacion.apellido << std::endl;
        std::cout << "Edad: " << informacion.edad << std::endl << std::endl;

        }
    }
    else{
        std::cout << "La lista esta vacia." << std::endl;
    }
    
}

int MostrarCantidadDeMiembros(std::list<Clubs> lista_clubs){

    int total_miembros = 0;
    Clubs informacion;

    for(auto &informacion :  lista_clubs){

        total_miembros = total_miembros + informacion.miembros_totales;

    }

    return total_miembros;

}

