#include <iostream>
#include "ReservationSystem.hpp"
#include "ReservationRequest.hpp"

using namespace std;

int main() {
    cout<<"CRIAÇÃO DO SISTEMA\n"<<endl;
    int capacities[2] = {30, 50};
    ReservationSystem system(2, capacities);

    cout<<"\nRESERVAS BEM-SUCEDIDAS\n"<<endl;
    ReservationRequest r1("Calculo", "segunda", 8, 10, 25);
    ReservationRequest r2("Fisica", "segunda", 10, 12, 20);

    if (system.reserve(r1))
        cout << "Reserva Calculo\n";
    else
        cout << "Falha Calculo\n";

    if (system.reserve(r2))
        cout << "Reserva Fisica\n";
    else
        cout << "Falha Fisica\n";

    cout<<"\nTENTATIVA DE RESERVA SEM DISPONIBILIDADE\n"<<endl;
    ReservationRequest r3("Quimica", "segunda", 9, 11, 20);

    if (system.reserve(r3))
        cout << "Reserva Quimica -> Valor esperado: Falha\n";
    else
        cout << "Falha Quimica\n";

    ReservationRequest r4("Biologia", "terca", 8, 10, 60);
    if (system.reserve(r4))
        cout << "Reserva Biologia OK -> Valor esperado: Falha\n";
    else
        cout << "Falha Biologia\n";
    system.printSchedule();

    cout<<"\nCANCELAMENTOS\n"<<endl;
    if (system.cancel("Calculo"))
        cout << "Cancelamento Calculo OK\n";
    else
        cout << "Falha ao cancelar Calculo\n";

    cout<<"\nEXIBIÇÃO DA GRADE\n"<<endl;

    system.printSchedule();
    return 0;
}