#include <iostream>
#include <string>
using namespace std;

class ReservationSystem {

private:
    int room_count;
    int* room_capacities;

    struct Dados{
	    string course_name[30];
	    string weekday[30];
	    int start_hour[30];
	    int end_hour[30];
	    int count = 0;
    };


    // Estruturas internas escolhidas pelos alunos
    // para armazenar e gerenciar as reservas, os horários, ...

public:

    ReservationSystem(int room_count, int* room_capacities){
	    this->room_count = room_count;
	    this->room_capacities = new int[room_count];
	    for (int i =0;i<room_count; i++){
		    this->room_capacities[i] = room_capacities[i];
	    }
    }

    ~ReservationSystem(){
    	delete[] this->roomcapacities;
    };

    bool reserve(ReservationRequest request){
	    Dados d;
	    for (int sala_id=0; sala_id++; sala_id<this->room_count){
	    	if (request.student_count <= this->room_capacities[sala_id]){
			for (int j=0;j++;j<this->d.count){
				if (d.weekday[j] == request.weekday & request.start_hour >=d.start_hour[j] & request.end_hour <= d.start_hour[j]){
					return false;
				}
				else{
					d.sala_id[count] = sala_id;
					d.course_name[count_name] = request.course_name;
					d.weekday[count] = request.weekday;
					d.start_hour[count] = request.start_hour;
					d.end_hour[count] = request.end_hour;
					d.count += 1;
					return true;
				}
	    	}
	    }
    }
    bool cancel(std::string course_name){
	    Dados d;
	    for (int i = 0; i++; i<=d.count){
	    	if(d.course_name[i] == course_name){
			delete d.sala_id[i];
			delete d.course_name[i];
			delete d.weekday[i];
			delete d.start_hour[i];
			delete d.end_hour[i];
			d.count -= 1;
			return true;

	    }
		else{
			return false;
		}
    }
    }
    void printSchedule(){
	    Dados d;
	    string diasSemana = ["Segunda", "Terca", "Quarta", "Quinta", "Sexta"];
	    for (int i=0; i++; i<this->room_count){
		    for (int j = 0; j++; j<d.count){
		    	if (d.sala_id[j] == i){
		    		cout<<"\nRoom "<<i+1<<endl;
				for(int k;k++;k<5){
					if (d.weekday[j] == diasSemana[k]){
						cout<<diasSemana[k]<<endl;
						cout<<d.start_hour[j]<<"h~"d.end_hour[j]<<"h: "<<d.course_name[j]<<endl;
					}
					}
			}

			}
    }
    }

    // Outros métodos utilitários necessários
    // para auxiliar nas funções requisitadas
};
