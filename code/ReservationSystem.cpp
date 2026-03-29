#include <iostream>
#include <string>
#include "ReservationSystem.hpp"
#include "ReservationRequest.hpp"
using namespace std;

class ReservationSystem {
private:
    int room_count;
    int* room_capacities;
    struct Dados {
        int sala_id[30];
        string course_name[30];
        string weekday[30];
        int start_hour[30];
        int end_hour[30];
        int student_count[30];
        int count = 0;
    };
    Dados d; 

public:
    ReservationSystem(int room_count, int* room_capacities){
        this->room_count = room_count;
        this->room_capacities = new int[room_count];
        for (int i =0;i<room_count; i++){
            this->room_capacities[i] = room_capacities[i];
        }
    }

    ~ReservationSystem(){
        delete[] this->room_capacities; 
    }

    bool reserve(ReservationRequest request){
        for (int sala_id=0;sala_id<this->room_count; sala_id++){
            if (request.getStudentCount() <= this->room_capacities[sala_id]){
                bool conflito = false;
                
                for (int j=0;j<this->d.count;j++){
                    if (d.sala_id[j] == sala_id && d.weekday[j] == request.getWeekday() && 
                        !(request.getEndHour() <= d.start_hour[j] || request.getStartHour() >= d.end_hour[j])){
                        conflito = true;
                        break;
                    }
                }
                
                if (!conflito){
                    d.sala_id[d.count] = sala_id;
                    d.course_name[d.count] = request.getCourseName();
                    d.weekday[d.count] = request.getWeekday();
                    d.start_hour[d.count] = request.getStartHour();
                    d.end_hour[d.count] = request.getEndHour();
                    d.student_count[d.count] = request.getStudentCount();
                    d.count += 1;
                    return true;
                }
            }
        }
        return false;
    }

    bool cancel(std::string course_name){
        for (int i = 0; i < d.count; i++){
            if(d.course_name[i] == course_name){
                d.sala_id[i] = d.sala_id[d.count - 1];
                d.course_name[i] = d.course_name[d.count - 1];
                d.weekday[i] = d.weekday[d.count - 1];
                d.start_hour[i] = d.start_hour[d.count - 1];
                d.end_hour[i] = d.end_hour[d.count - 1];
                d.student_count[i] = d.student_count[d.count - 1];
                d.count -= 1;
                return true;
            }
        }
        return false;
    }

    void printSchedule(){
        string diasSemana[] = {"segunda", "terca", "quarta", "quinta", "sexta"};
        
        for (int i=0; i<this->room_count;i++){
            for (int j = 0;j<d.count;j++){
                if (d.sala_id[j] == i){
                    cout<<"\nRoom "<<i+1<<endl;
                    for(int k = 0; k < 5; k++){ 
                        if (d.weekday[j] == diasSemana[k]){
                            cout<<diasSemana[k]<<":"<<endl;
                            cout<<d.start_hour[j]<<"h~"<<d.end_hour[j]<<"h: "<<d.course_name[j]<<endl;
                        }
                    }
                }
            }
        }
    }
};