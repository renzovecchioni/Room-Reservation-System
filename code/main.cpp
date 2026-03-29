#include <iostream>
#include "ReservationSystem.hpp"
#include "ReservationRequest.hpp"

using namespace std;

#include <iostream>
#include "ReservationSystem.hpp"
#include "ReservationRequest.hpp"

int main() {
    cout<<"criação do sistema\n"<<endl;
    int capacities[2] = {30, 50};
    ReservationSystem system(2, capacities);

    cout<<"\nreservas bem-sucedidas\n"<<endl;
    ReservationRequest r1("Calculo", "segunda", 8, 10, 25);
    ReservationRequest r2("Fisica", "segunda", 10, 12, 20);

    if (system.reserve(r1))
        std::cout << "Reserva Calculo\n";
    else
        std::cout << "Falha Calculo\n";

    if (system.reserve(r2))
        std::cout << "Reserva Fisica\n";
    else
        std::cout << "Falha Fisica\n";

    cout<<"\ntentativa de reserva sem disponibilidade\n"<<endl;
    ReservationRequest r3("Quimica", "segunda", 9, 11, 20);

    if (system.reserve(r3))
        std::cout << "Reserva Quimica -> Valor esperado: Falha\n";
    else
        std::cout << "Falha Quimica\n";

    ReservationRequest r4("Biologia", "terca", 8, 10, 60);
    if (system.reserve(r4))
        std::cout << "Reserva Biologia OK -> Valor esperado: Falha\n";
    else
        std::cout << "Falha Biologia\n";
    system.printSchedule();

    cout<<"\ncancelamentos\n"<<endl;
    if (system.cancel("Calculo"))
        std::cout << "Cancelamento Calculo OK\n";
    else
        std::cout << "Falha ao cancelar Calculo\n";

    cout<<"\nexibição da grade\n"<<endl;

    system.printSchedule();
    return 0;
}