#include "calculo_distancia.h"
#include <limits>
#include "agendamentos.h"


std::vector<agendamento> organizar_visitas(corretor avaliador){
    std::vector<agendamento> agendamentos; // declaração de vetor do tipo struct agendamento para guardar as informações de cada visita
    std::vector<imovel*> lista = avaliador.getImoveisAtribuidos(); /// obtém a lista de imóveis sob responsabilidade do avaliador

    int total = lista.size(); // total de imóveis para visitar
    int jj = 0; // variável que guarda a qt. de imoveis visitados
    std::vector<bool> visitados(lista.size(), false); // vetor de controle de visita

    // declaração inicial de horário
    int hora = 9; 
    int minuto = 0;

    // obtém latitude e longitude iniciais do avaliador;
    double latAtual = avaliador.getLat();
    double lngAtual = avaliador.getLng();

    while(jj < total){
        int indexProx = -1; // variável que armazenará o index do imovel mais próximo
        double menorDistancia = std::numeric_limits<double>::max(); // armazenar o maior valor que um double pode representar.

        // loop que busca o imóvel mais próximo entre os ainda não visitados e armazenar o index e a distância
        for(int ii = 0; ii < total; ii++){ 
            if(visitados[ii] == false){
                double dist = haversine(latAtual, lngAtual, lista[ii]->getLat(), lista[ii]->getLng());

                if(dist < menorDistancia){
                    menorDistancia = dist;
                    indexProx = ii;
                }
            }
        }


        int tempo_desloc = static_cast<int>(menorDistancia * 2); // calculo do tempo de deslocamento e conversão para inteiro
        minuto = minuto + tempo_desloc; // adição do tempo de deslocamento
        //atualização dos minutos e hora caso exceda
        if (minuto >= 60){ 
            hora = hora + (minuto/60);
            minuto = minuto % 60;
        }

        agendamentos.push_back({lista[indexProx]->getId(), hora, minuto}); // agenda a visita

        minuto = minuto + 60; // adição do tempo de visita
        //atualização dos minutos e hora caso exceda
        if (minuto >= 60){
            hora = hora + (minuto/60);
            minuto = minuto % 60;
        }

        // atualização da localização atual para a do imovel recém-visitado
        latAtual = lista[indexProx]->getLat();
        lngAtual = lista[indexProx]->getLng();


        // marca o imovel como visitado e atualiza a variavel
        visitados[indexProx] = true;
        jj++;
        
    }

    return agendamentos;
}