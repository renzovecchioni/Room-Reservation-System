#ifndef RESERVATIONSYSTEM_HPP
#define RESERVATIONSYSTEM_HPP

#include <iostream>
#include <string>
#include "ReservationRequest.hpp"

class ReservationSystem {
private:
    int room_count;
    int* room_capacities;

    struct Dados {
        int sala_id[30];
        std::string course_name[30];
        std::string weekday[30];
        int start_hour[30];
        int end_hour[30];
        int student_count[30];
        int count = 0;
    };
    Dados d; 
public:
    ReservationSystem(int room_count, int* room_capacities);
    ~ReservationSystem();
    bool reserve(ReservationRequest request);
    bool cancel(std::string course_name);
    void printSchedule();
};
#endif 