#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H
#include "corretor.h"
#include <vector>


struct agendamento {
    int idImovel;
    int hora;
    int minuto;
};

std::vector<agendamento> organizar_visitas(corretor); //função que organiza as visitas, traçando a rota entre os imoveis e agendando horários


#endif
