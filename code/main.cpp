#include <iostream>
#include "ReservationSystem.hpp"
#include "ReservationRequest.hpp"

using namespace std;

int main() {
    int capacities[] = {30, 50, 40};
    ReservationSystem system(3, capacities);

    ReservationRequest r1("Calculo", "segunda", 8, 10, 35);
    ReservationRequest r2("Fisica", "segunda", 9, 11, 20);
    ReservationRequest r3("Algoritmos", "segunda", 10, 12, 35);

    if (system.reserve(r1))
        cout << "Reserva 1 feita\n";
    else
        cout << "Falha reserva 1\n";
    // if (system.reserve(r2))
    //     cout << "Reserva 2 feita\n";
    // else
    //     cout << "Falha reserva 2 (conflito esperado)\n";
    // if (system.reserve(r3))
    //     cout << "Reserva 3 feita\n";
    // else
    //     cout << "Falha reserva 3\n";
    // system.printSchedule();
    // system.cancel("Calculo");
    // system.printSchedule();
    // return 0;
}