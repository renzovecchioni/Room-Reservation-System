# Trabalho 1: Room-Reservation-System

Neste trabalho, os alunos devem implementar um sistema simples para gerenciar a alocação de disciplinas em salas de aula durante uma semana.
## Descrição do Projeto

Este projeto implementa um sistema de gerenciamento de reservas de salas, dividido em duas classes, uma de requisição de sala onde informava dados como:
* Nome do Curso;
* Dia da semana;
* Horario de Inicio;
* Horario de Término;
* Numero de Alunos.
Já a outra classe, atua como o sistema em si, que a partir das atribuições do número de salas total e a quantidade de vagas referente à sala, ele possui métodos que:
* Fazem a Reserva de Sala, com as devidas restrições como por exemplo não haver conflito de salas quando os horários de salas diferentes baterem;
* Cancelamento de determinada sala, a partir do nome do Curso, sendo feito também o devido descarte do horário no sistema;
* Reproduzir as Salas reservadas dividido pelos dias da semana.

## Instruções de excecução
O usuario deve encontrar o diretorio referente ao código e excecutar no terminal:
´´´bash
g++ main.cpp ReservationSystem.cpp ReservationRequest.cpp -o programa
´´´
## Instruções de execução
Basta que o usuário rode no terminal:
´´´bash
./programa
´´´
## Uma breve explicação de como os dados estão organizados internamente no sistema.
### ReservationRequest
Os dados sao encapsulados e acessados por meio de getters
### ReservationSystem
Os dados sao guardados dentro de um struct e cada um deles (exceto o count) é um array, são eles:

* sala_id
* course_name
* weekday
* start_hour
* end_hour
* student_count
* count

O count é uma parte fundamental dessa estrutura, pois controla a quantidade atual de elementos armazenados. Ele é essencial para o funcionamento dos métodos da classe, como inserção, remoção e verificação de dados. Além disso, o count define o limite até o qual os laços for devem iterar, garantindo que apenas posições válidas sejam acessadas. Dessa forma, ele evita acessos indevidos à memória e permite percorrer corretamente os elementos existentes.