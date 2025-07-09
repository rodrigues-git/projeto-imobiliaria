#include "roundrobin.h"

void round_robin(std::vector<corretor>& avaliadores, std::vector<imovel>& imoveis){
    int indice;
    int num_avaliadores = avaliadores.size();
    imovel* ptr;

    for(size_t ii = 0; ii < imoveis.size(); ii++){
        ptr = &imoveis[ii];
        indice = ii % num_avaliadores;
        avaliadores[indice].atribuirImovel(ptr);
    }
    

}



